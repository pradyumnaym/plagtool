# 1 "./addSub_4.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "./addSub_4.c"

int add ( int n1 , int n2 ) {
 int n3;
 n3 = n1 + n2;
 return n3;
}

int sub ( int n1, int n2 ) {
 int n3;
 n3 = n1 - n2;
 return n3;
}

int main() {
 int n1 = 10;
 int n2 = 15;
 int n3 = add(n1,n2);
 int n4 = sub(n1,n2);
 printf("%d %d\n",n1,n2);
}
