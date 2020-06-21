void print_digits(int n) {
	int temp;
	if(n == 0)
		return;
	temp = n % 10;
	print_digits(n/10);
	printf("%d ",temp);
}


int main() {
	int n = 12345;
	print_digits(n);
}
