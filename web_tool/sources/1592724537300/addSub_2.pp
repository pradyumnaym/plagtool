# 1 "./addSub_2.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "./addSub_2.c"

int add ( int a , int b ) {
 int p, q, r;
 int c ;
 p = 1;
 if(!p) {
  p = q;
  q = r;
 }
 else if(p) {
  p = q;
  q = r;
 }
 else {
  p = q;
  q = r;
 }

 c = a + b ;
 return c ;
}

int sub ( int a, int b ) {
 int k ;
 int c ;
 k = 1 ;
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
