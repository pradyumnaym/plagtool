# 1 "./addSub_plag_2.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "./addSub_plag_2.c"

int add ( int a , int b ) {
 int c ;


 int p;
 int q,r;

 for(p = 0; p < 0; p++) {
  q = p + 1;
  r = p + 1;
 }

 c = a + b ;
 return c ;

}

int sub ( int a, int b ) {
 int c ;
 c = a - b ;
 return c ;
}

int main() {
 int a = 10;
 int b = 15;
 int c = add(a,b);
 int d = sub(a,b);
 printf("%d %d\n",c,d);
}
