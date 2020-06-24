# 1 "./Obf.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "./Obf.c"

int add ( int a , int b ) {
 int c ;

 int u1,u2,u3;
 u1 = 1;
 u2 = 2;
 u3 = u1 + u2 + 3;

 c = a + b ;

 u1 = 1;
 u2 = 2;
 u3 = u1 + u2 + 3;

 return c ;
}

int sub ( int a, int b ) {
 int c ;

 int u1,u2,u3;
 u1 = 1;
 u2 = 2;
 u3 = u1 + u2 + 3;

 c = a - b ;

 u1 = 1;
 u2 = 2;
 u3 = u1 + u2 + 3;

 return c ;
}

int main() {
 int a = 10;
 int b = 15;
 int c = add(a,b);
 int d = sub(a,b);
 int u1,u2,u3;

 u1 = 1;
 u2 = 2;
 u3 = u1 + u2 + 3;

 printf("%d %d\n",c,d);

 u1 = 1;
 u2 = 2;
 u3 = u1 + u2 + 3;
}
