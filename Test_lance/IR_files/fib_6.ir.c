
/* 1 "LANCEV2" */
/* $
     IR file generated by LANCE V2.0 (./myapp) on
     Saturday, Jun 20, 2020 at 21:55:51
$ */

int fib(int );
int main();

static char *lance_static_t2 = "%d\n";

int main()
{
 int n_4;
 int t1;
 int res_5;
 int t3;


 /* 4 "/home/anushkini/Desktop/PD/plagtool/Test_lance/fib_6.c" */
 /* $ int n = 10;$ */

	n_4 = 10;

 /* 5 "/home/anushkini/Desktop/PD/plagtool/Test_lance/fib_6.c" */
 /* $ int res = fib(n);$ */

	t1 = fib(n_4);
	res_5 = t1;

 /* 6 "/home/anushkini/Desktop/PD/plagtool/Test_lance/fib_6.c" */
 /* $ printf("%d\n",res);$ */

	t3 = printf(lance_static_t2,res_5);

 /* 0 "???" */
 /* $ ???$ */

	return;

}

int fib(int n_7)
{
 int t4;
 int t5;
 int t6;
 int t7;
 int t8;
 int t9;
 int t10;


 /* 11 "/home/anushkini/Desktop/PD/plagtool/Test_lance/fib_6.c" */
 /* $ return n;$ */

	return n_7;


 /* 10 "/home/anushkini/Desktop/PD/plagtool/Test_lance/fib_6.c" */
 /* $ if(n <= 1)$ */

 LL1:

 /* 12 "/home/anushkini/Desktop/PD/plagtool/Test_lance/fib_6.c" */
 /* $ return fib(n-1) + fib(n-2);$ */

	t6 = n_7 - 1;
	t7 = fib(t6);
	t8 = n_7 - 2;
	t9 = fib(t8);
	t10 = t7 + t9;
	return t10;

}
