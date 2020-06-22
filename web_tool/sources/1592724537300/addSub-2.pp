# 1 "./addSub-2.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "./addSub-2.c"

void add_sub(int a, int b, int *ans) {
 ans[0] = a+b;
 ans[1] = a-b;
}

int main() {
 int a = 10;
 int b = 15;
 int ans[2];
 add_sub(a,b,ans);
 printf("%d %d\n",ans[0],ans[1]);
}
