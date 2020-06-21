
///////////////////////////////////////////////////////////
// Example application of the LANCE library.
//
// It does not do anything useful, but just
// demonstrates IR access and flow analyses.
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
// main function
///////////////////////////////////////////////////////////

main(int argc, char*argv[])
{
  Function *f;
  int i,j;
  FILE *infile,*outfile;
  char str[MAXFILENAME];
  IntermediateRepresentation *IR;
  DataFlowAnalysis* DFA;
  ControlFlowGraph* CFG;
  IRSymbol* sym;
  IRStm* stm;
  BitSet* useset;
  BitSet* defset;
  int def;
  DFTManager* DM;
  List* BBList;
  BasicBlock* BB;
  List* dftlist;
  List* cfglist;
  LANCEDataFlowTree* DFT;

  ///////////////////////////////////////////////////////////
  // make the program name globally known,
  // should be done for all tools writing back an IR file
  ///////////////////////////////////////////////////////////

  SetLANCEProgramName(argv[0]);

  ///////////////////////////////////////////////////////////
  // some messages
  ///////////////////////////////////////////////////////////

  printf("\n *** LANCE V2.0 - Example application ***\n");

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
  // traverse all global symbols, emit in C syntax
  ///////////////////////////////////////////////////////////

  for (sym = IR->GlobalSymbolTable()->FirstObject(); sym;
       sym = IR->GlobalSymbolTable()->NextObject())
  {
    printf("\n * Global symbol: ");
    sym->Type()->Write(stdout,sym,false);
  }


  ///////////////////////////////////////////////////////////
  // traverse all functions
  ///////////////////////////////////////////////////////////

  for (f = IR->FirstFunction(); f; f = IR->NextFunction())
  { 
    printf("\n\n * Function '%s'",f->Name());

    ///////////////////////////////////////////////////////////
    // traverse local symbol table of f
    ///////////////////////////////////////////////////////////

    for (i = 1,sym = f->LocalSymbolTable()->FirstObject(); sym;
         i++,  sym = f->LocalSymbolTable()->NextObject());

    printf(" has %d local symbols",i);

    ///////////////////////////////////////////////////////////
    // do control flow analysis, required only once per function
    ///////////////////////////////////////////////////////////

    CFG = new ControlFlowGraph(f,IR);

    printf(" and %d basic blocks",CFG->NumberOfNodes());

    // cfglist = GetBasicBlocks(f);
    // for(BB = (BasicBlock*)cfglist->First(); BB; BB = (BasicBlock*)cfglist->Succ(BB)) {
    //   printf("\n\n**New Block **\n\n");
    //   for(stm = BB->FirstStmt(); stm ; stm = BB->NextStmt()) {
    //     stm->Write(stdout); fflush(stdout);
    //   }
    //   if(BB == (BasicBlock*)cfglist->Last()) break;
    // }

    ///////////////////////////////////////////////////////////
    // do data flow analysis, required only once per function
    ///////////////////////////////////////////////////////////

    DFA = new DataFlowAnalysis(f,IR);

    ///////////////////////////////////////////////////////////
    // traverse all IR statements, report number of uses
    ///////////////////////////////////////////////////////////

    for (stm = f->FirstStm(); stm; stm = f->NextStm())
    {
          printf("New : %d\n", stm->Class());
          fflush(stdout);
          stm->Write(stdout); fflush(stdout);
      ///////////////////////////////////////////////////////////
      // check whether number of uses can be determined
      ///////////////////////////////////////////////////////////
      
      // if(stm->Class() == 1) {
      //   List* st = f->Statements();
      //   st->Delete(stm);
      //   f->SetStatements(st);
      //   continue;
      // }
      // printf("New : %d\n", stm->Class());
      // fflush(stdout);
      // stm->Write(stdout); fflush(stdout); continue;


      if(stm->Class() == 3 ) {
        int index = 0;int flag = 0; 
        IRStm *arr[1000];
        char *label = stm->Label();
        while(!flag) {
          printf("New : %d\n", stm->Class());
          fflush(stdout);
          stm->Write(stdout); fflush(stdout);
          if(stm->Class() != 3 && stm->Class() != 4 && stm->Class() != 2) {
            flag = 1;
          }
          
          
          else if(stm->Class() == 4 && (!strcmp(label, stm->Label()))) {
              flag = 2;
          }
          
          else if(stm->Class() == 3 || stm->Class() == 2 || stm->Class() == 4) {
            int x = atoi(stm->Label()+2);
            if(x > atoi(label + 2)) {
              label = stm->Label();
            }
          }

          arr[++index] = stm;
          stm = f->NextStm();
        }

        if(flag == 2) {
          for(; index >= 0; index--) {

            printf("Remove : %d\n", arr[index]->Class());
            fflush(stdout);
            arr[index]->Write(stdout); fflush(stdout);
            List* st = f->Statements();
            st->Delete(arr[index]);
            f->SetStatements(st);
          }
        }
        index = 0;
      }

      continue;

      if ( // assignments only
          stm->Class() == IRSTM_ASGN &&

           // assignments to symbols only
          stm->LHS()->Class() == IREXP_SYMBOL &&

           // assignments to symbols not bound to memory only
          !DFA->GetDFG()->IsAddrTaken(stm->LHS()->Num()))
      {
        useset = DFA->GetUses(stm->Num());
        printf("\n * Statement '");
        stm->Write(stdout);
        printf("' (src ln: %d) has %d uses",stm->Lex()->line,useset->Size());

	///////////////////////////////////////////////////////////
        // print type of left hand side and right hand side
        ///////////////////////////////////////////////////////////

	printf("\n * Destination has type ");
	stm->LHS()->Type()->Write(stdout);

	printf("\n * Right hand side has type ");
        stm->RHS()->Type()->Write(stdout);

        ///////////////////////////////////////////////////////////
        // check whether a binary expression is assigned
        ///////////////////////////////////////////////////////////

        if (stm->RHS()->Class() == IREXP_BINARY)
        {
          ///////////////////////////////////////////////////////////
	  // emit definitions of first argument, if it is a symbol
          ///////////////////////////////////////////////////////////

          if (stm->RHS()->Arg1()->Class() == IREXP_SYMBOL &&
               // only symbols not bound to memory 
	      !DFA->GetDFG()->IsAddrTaken(stm->RHS()->Arg1()->Num()))
          {
            defset = DFA->GetDefs(stm->RHS()->Arg1()->Num());
            printf("\n * First argument expression '");
            stm->RHS()->Arg1()->Write(stdout);
            printf("' has %d definitions:",defset->Size());

	    ///////////////////////////////////////////////////////////
	    // show the def statements, "EOS" means "end of set"
	    ///////////////////////////////////////////////////////////

	    for (def = defset->First(); def != EOS; def = defset->Next())
	    {
	      printf("\n\t");

	      ///////////////////////////////////////////////////////////
	      // map statement no. "def" to an IRStm pointer
	      ///////////////////////////////////////////////////////////

	      stm = IR->IRStatement(def);

	      ///////////////////////////////////////////////////////////
	      // print statement and its source information
	      ///////////////////////////////////////////////////////////

	      stm->Write(stdout);
	      printf("  // file '%s', line %d",stm->Lex()->fname,stm->Lex()->line);
	      printf("\n\t // source line: %s",stm->Lex()->srcln);
	    }

          }
        }
      }
    }
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

