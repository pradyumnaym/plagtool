int fib(int n) {
	if(n <= 1) 
		return n;
	return fib(n-1) + fib(n-2);

}

int main() {
	int p = 1;
	int q = p + 1;
	int r = p + 2;
	int n = 10;
	int res = fib(n);
	printf("%d\n",res);
}
