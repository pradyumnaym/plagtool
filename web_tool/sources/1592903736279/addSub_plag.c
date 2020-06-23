////#include<stdio.h>
int add ( int a , int b ) {
	int c ;
	
	//Dead code
	int p = 0;
	int q,r;
	
	if(p) {
		q = p + 1;
		r = p + 2;
	}
	else {
		q = p + 1;
		r = p + 2;
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
