#include<stdio.h>
int fib(int);

int main() {
	int n = 10;
	int res = fib(n);
	printf("%d\n",res);
}

int fib(int n) {
	if(n <= 1) 
		return n;
	return fib(n-1) + fib(n-2);

}