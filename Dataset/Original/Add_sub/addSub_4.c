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
