
///////////////////////////////////////////////////////////
// A Dead Code Eliminator using the LANCE library.
//
// The tool operates on an IR file whose name is passed as a 
// command line argument.
///////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

///////////////////////////////////////////////////////////
// include the LANCE V2.0 header file
///////////////////////////////////////////////////////////

#include "../INCL/lance2.h"

///////////////////////////////////////////////////////////
// this function should be declared by any application program
///////////////////////////////////////////////////////////

void yyyCheckForResizes(int,char**);


///////////////////////////////////////////////////////////
// Global HashTable to mark important variables
///////////////////////////////////////////////////////////
LargeHashTable *ht;


/*
Function upsert
Arguments:
1. ht - HashTable 
2. k - variable name to mark important.
3. v - integer pointer passed as void pointer which points to integer 
  a. 0 - Not Important.
  b. 1 - Importantance due to being reachable.
  c. 2 - Important 

Inserts an entry to the hashtable with key k and value v.
*/
void upsert(LargeHashTable* ht, char* k, void* v) {
  if(ht->Search(k)) {
    ht->Delete(k);
  }
  ht->Insert(k,v);
}


/*
Function gInsert
Arguments:
1. g - Graph variable 
2. info - a char pointer indicating name of node to be inserted into g.

Inserts a node into graph g with node whose name is info.
*/
void gInsert(Graph *g, char* info) {
  GraphNode* n;
  for(n = g->FirstNode();n;n = g->NextNode()) {
    if(!strcmp(info, (char*)n->Info())) return;
  }
  GraphNode* newNode = g->NewNode((void*)info);
}

/*
Function gEdge
Arguments:
1. g - Graph variable
2. lhs - name of node1 
3. rhs - name of node2

Inserts a directed edge from 'lhs' node (node1) to 'rhs' node (node2).
*/
void gEdge(Graph *g, char* lhs, char* rhs) {
  GraphNode* n, *n1, *n2;

  for(n = g->FirstNode();n;n = g->NextNode()) {
    if(!strcmp(lhs, (char*)n->Info())) {
      n1 = n;
      break;
    }
  }

  
  for(n = g->FirstNode();n;n = g->NextNode()) {
    if(!strcmp(rhs, (char*)n->Info())) {
      n2 = n;
      break;
    }
  }

  if(g->ContainsEdge(n1,n2)) return;
  
  GraphEdge* ge = g->NewEdge(n1,n2);
}

/*
Function makeImp
Arguments:
1. g - Graph variable 
2. ht - Hashtable
3. info - Name of variable to mark important
4. a - integer pointer where *(a+1) = 1 and *(a+2) = 2

Marks the 'info' variable as 'Important'(2) and then marks all reachable variables from 'info' as 'Importantance due to being reachable'(1).
*/
void makeImp(Graph *g, LargeHashTable *ht, char *info, int *a) {
  GraphNode* n, *n1;
  
  upsert(ht, info, (void*)(a+2));
  
  for(n = g->FirstNode();n;n = g->NextNode()) {
    if(!strcmp(info, (char*)n->Info())) {
      n1 = n;
      break;
    }
  }

  for(n = g->FirstNode();n;n = g->NextNode()) {
    if(g->Reachable(n1,n)) {
      upsert(ht, (char*)n->Info(), (void*)(a+1));
    }
  }
}

/*
Function delStatement
Arguments:
1. f - Function variable 
2. stm - statement to be deleted

Deletes statement stm and updates f to reflect the same.
*/
void delStatement(Function *f, IRStm* stm) {
  List* st = f->Statements();
  st->Delete(stm);
  f->SetStatements(st);
}


/*
Function gPrint
Arguments:
1. f- FILE variable
2. g - Graph variable 

Helper function which writes node information into a VCG file.
*/
void gPrint(FILE *f, void *g) {
  GraphNode* n = (GraphNode*)g;
  fprintf(f,"%s\n",(char*)g);
}

/*
Function gColor
Arguments:
1. f- FILE variable
2. info - information of node 

Helper function which colors node according to 'info' into a VCG file.
*/
void gColor(FILE *f, void *info) {
  if( *(int*)(ht->Search((char*)info)) == 1) fprintf(f,"lightgreen\n");
  else if ( *(int*)(ht->Search((char*)info)) == 2) fprintf(f,"green\n");
  else fprintf(f, "lightred\n"); 
}

/*
Function geInfo
Arguments:
1. f- FILE variable
2. info - information of edge

Helper function which writes the labels of edges according to info into a VCG file.
*/
void geInfo(FILE *f, void *info) {
  IRStm* stm = (IRStm*)info;
  stm->Write(f);
  stm->Write(stdout);
}

/*
Function printHt
Arguments:
1. ht  - Hashtable

Prints the hashtable onto stdout. Useful for debugging.
*/
void printHt(LargeHashTable* ht) {
  List* keys = ht->Keylist();
  char *key;
  for(key = (char*)keys->First(); key; key = (char*)keys->Succ(key)) {
    printf("Key: %s Value: %d\n", key, *((int*)ht->Search(key)));
    if(key == (char*)keys->Last()) break;
  }
  printf("\n");fflush(stdout);
}

/*
Function printG
Arguments:
1. g - Graph variable 

Prints Graph nodes onto stdout. Useful for debugging.
*/
void printG(Graph *g) {
  GraphNode* n;
  for(n = g->FirstNode();n;n = g->NextNode()) {
    printf("Node %s\n", (char*)n->Info());
  }
}

///////////////////////////////////////////////////////////
// main function
///////////////////////////////////////////////////////////

main(int argc, char*argv[])
{
  Function *f;
  int i,j;
  FILE *infile,*outfile,*gf;
  char str[MAXFILENAME];
  IntermediateRepresentation *IR;
  ControlFlowGraph* CFG;
  IRSymbol* sym;
  IRStm* stm;
  IRExp* expr, *arg;
  BitSet* useset;
  BitSet* defset;
  int def;
  DFTManager* DM;
  List* BBList;
  BasicBlock* BB;
  List* dftlist;
  List* cfglist;
  int no_statements = 0;
  
  LANCEDataFlowTree* DFT;
  
  int *a = (int*)malloc(sizeof(int)*3);
  a[0] = 0; a[1] = 1;a[2] = 2;
  
  Graph* g = new Graph();
  
  GraphEdge* ge;
  ///////////////////////////////////////////////////////////
  // make the program name globally known,
  // should be done for all tools writing back an IR file
  ///////////////////////////////////////////////////////////

  SetLANCEProgramName(argv[0]);

  ///////////////////////////////////////////////////////////
  // some messages
  ///////////////////////////////////////////////////////////

  printf("\n *** Dead Code Eliminator Application ***\n");

  if (argc < 2) 
  { printf("\nuse: %s <IR file>\n", argv[0]);
    exit(-1);
  }

  ///////////////////////////////////////////////////////////
  // start timer to report execution time later
  ///////////////////////////////////////////////////////////

  StartTimer();

  ///////////////////////////////////////////////////////////
  // setup IR file name
  ///////////////////////////////////////////////////////////

  infile = fopen(argv[1], "r");

  if (infile == NULL) 
  { printf("Could not open IR file for reading\n");
    exit(-1);
  }

  ///////////////////////////////////////////////////////////
  // any application must call this function before reading the IR
  ///////////////////////////////////////////////////////////

  yyyCheckForResizes(argc,argv);

  ///////////////////////////////////////////////////////////
  // read IR from file
  ///////////////////////////////////////////////////////////

  IR = ReadIR(infile);

  ///////////////////////////////////////////////////////////
  // check for success
  ///////////////////////////////////////////////////////////

  if (!IR) 
  { printf("\n\nerror: failed to get IR\n\n");
    exit(-1);
  }


  ///////////////////////////////////////////////////////////
  // traverse all functions
  ///////////////////////////////////////////////////////////

  for (f = IR->FirstFunction(); f; f = IR->NextFunction())
  { 
    ht = new LargeHashTable();
    g = new Graph();
    printf("\n\n * Running algorithm on Function '%s'\n",f->Name());


    ///////////////////////////////////////////////////////////
    // PASS 1
    ///////////////////////////////////////////////////////////

    /*
      If statement is of assignment type, 
      1.We insert the left variable into hashtable and mark it as 0.
        We also create a node for the variable and insert into graph.

      2. We check the if the RHS of the statement is an expression.
        If so, we insert any variables in the expression into the hashtable.
        A node is also inserted into the graph.
    */
    
    for (stm = f->FirstStm(); stm; stm = f->NextStm())
    {
      if(stm->Class() == 1) {
        upsert(ht, stm->LHS()->Symbol()->Name(), (void*)(a+0));
        gInsert(g, stm->LHS()->Symbol()->Name());
        
        if(stm->RHS()->Class() == 1) {
          gInsert(g, stm->RHS()->Symbol()->Name());  
          upsert(ht, stm->RHS()->Symbol()->Name(), (void*)(a+0));
        }

        else if(stm->RHS()->Class() == 2) {
          expr = stm->RHS();
          if(expr->Arg1()->Class() == 1) {
            gInsert(g, expr->Arg1()->Symbol()->Name());  
            upsert(ht, expr->Arg1()->Symbol()->Name(), (void*)(a+0));
          }

          if(expr->Arg2()->Class() == 1) {
            gInsert(g, expr->Arg2()->Symbol()->Name());
            upsert(ht, expr->Arg2()->Symbol()->Name(), (void*)(a+0));
          }
        }
      }
    }

    ///////////////////////////////////////////////////////////
    // END OF PASS 1
    ///////////////////////////////////////////////////////////

    //printHt(ht);


    ///////////////////////////////////////////////////////////
    // PASS 2
    ///////////////////////////////////////////////////////////

    /*
      We check for assignment statements. 
      We then make a directed edge from the LHS variable to all of the variables on the RHS of the statement.
    */

    for (stm = f->FirstStm(); stm; stm = f->NextStm()) {
      if(stm->Class() == 1) {
        
        if(stm->RHS()->Class() == 1) {
          gEdge(g, stm->LHS()->Symbol()->Name(), stm->RHS()->Symbol()->Name()); 
        }

        else if(stm->RHS()->Class() == 2) {
          expr = stm->RHS();
          if(expr->Arg1()->Class() == 1) {
            gEdge(g, stm->LHS()->Symbol()->Name(), expr->Arg1()->Symbol()->Name()); 
          }

          if(expr->Arg2()->Class() == 1) {
            gEdge(g, stm->LHS()->Symbol()->Name(), expr->Arg2()->Symbol()->Name()); 
          }
        }
      }
    }

    
    ///////////////////////////////////////////////////////////
    // END OF PASS 2
    ///////////////////////////////////////////////////////////
   


    ///////////////////////////////////////////////////////////
    // PASS 3
    ///////////////////////////////////////////////////////////

    /*
      We check for function calls. 
      When encountered:
      1. The parameters of the function call are marked important.
      2. Any variable reachable from the parameters are marked important.

      We check for return statements.
      When encountered:
      1. The return variable is marked important
      2. Any variable reachable from the return variable is marked important.
    */

    for (stm = f->FirstStm(); stm; stm = f->NextStm()) {

      if(stm -> Class() == 1) {
        if(stm->RHS()->Class() == 4) { //function call
          //if(!strcmp(stm->RHS()->CalledFunction()->Symbol()->Name(),"printf")) {
            makeImp(g,ht,stm->LHS()->Symbol()->Name(),a);
            expr = stm->RHS();
            for(arg = expr->FirstCallArg(); arg; arg = expr->NextCallArg()) {
              if(arg->Class() == 1) {
                makeImp(g, ht, arg->Symbol()->Name(),a);  
              }

              else if(arg->Class() == 2) {
                if(arg->Arg1()->Class() == 1) {
                  makeImp(g, ht, arg->Arg1()->Symbol()->Name(),a);                    
                }

                if(arg->Arg2()->Class() == 1) {
                  makeImp(g, ht, arg->Arg1()->Symbol()->Name(),a);  
                }
              }
            }
          //} 
        }
      }

      if(stm->Class() == 6) {
        expr = stm->ReturnExp();
        
        if(expr->Class() == 1) {
          makeImp(g, ht, expr->Symbol()->Name(),a);  
        }

        if(expr->Class() == 2) {
          if(expr->Arg1()->Class() == 1) {
            makeImp(g, ht, expr->Arg1()->Symbol()->Name(),a);  
          }
          if(expr->Arg2()->Class() == 1) {
            makeImp(g, ht, expr->Arg2()->Symbol()->Name(),a);  
          }
        }
      }
    }

    ///////////////////////////////////////////////////////////
    // END OF PASS 3
    ///////////////////////////////////////////////////////////

    //printHt(ht);
    //printG(g);


    ///////////////////////////////////////////////////////////
    // DELETE PASS 
    ///////////////////////////////////////////////////////////

    /*
      We iterate through each basic block in the function.
      We check if all the statements in the basic block have unimportant variables.
      If so, we delete all the statements in that basic block.

      We then go through the function from start to end and delete any unimportant statements.
    */


    cfglist = GetBasicBlocks(f);
    
    for(BB = (BasicBlock*)cfglist->First(); BB; BB = (BasicBlock*)cfglist->Succ(BB)) {
      
      for(stm = BB->FirstStmt(); stm ; stm = BB->NextStmt()) {
        if(stm->Class() == 1) {
          if(*(int*)(ht->Search(stm->LHS()->Symbol()->Name())) != 0) break;
        }
        if(stm->Class() == 5 || stm->Class() == 6) break;
      }

      if(stm == NULL) {
        for(stm = BB->FirstStmt(); stm ; stm = BB->NextStmt()) {
         delStatement(f,stm);
         no_statements += 1;
        } 
      }

      if(BB == (BasicBlock*)cfglist->Last()) break;
    }

    for (stm = f->FirstStm(); stm; stm = f->NextStm()) {
      if(stm->Class() == 1) {
        if(*(int*)(ht->Search(stm->LHS()->Symbol()->Name())) == 0) {
          delStatement(f,stm);
          no_statements += 1;
        }
      }
    }

    for (stm = f->FirstStm(); stm; stm = f->NextStm()) {
      if(stm->Class() == 1) {
        if(*(int*)(ht->Search(stm->LHS()->Symbol()->Name())) == 0) {
          delStatement(f,stm);
          no_statements += 1;
        }
      }
    }

    
    ///////////////////////////////////////////////////////////
    // END OF DELETE PASS 
    ///////////////////////////////////////////////////////////

    gf = fopen(f->Name(),"w");
    g->WriteVCG(gf, NULL, gPrint, NULL, gColor, NULL, NULL);

    printf(" - Removed %d IR statements \n",no_statements);
    no_statements = 0;

    delete ht;
    delete g;
  }


  ///////////////////////////////////////////////////////////
  // write IR back into file
  ///////////////////////////////////////////////////////////

  
  sprintf(str, "%s", ShortName(argv[1]));
  printf("\n * Writing '%s'", str);
  fflush(stdout);
  if ((outfile = fopen(str, "w")) == NULL) 
  { printf("\n\nerror: cannot write file '%s' \n\n", str);
    exit(-1);
  }
  IR->Write(outfile);
  fclose(outfile);

  ///////////////////////////////////////////////////////////
  // report execution time and quit
  ///////////////////////////////////////////////////////////

  StopTimer();
  TimeMsg();
  printf("\n * OK\n\n");

}