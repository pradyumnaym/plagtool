
/* 1 "LANCEV2" */
/* $
     IR file generated by LANCE V2.0 (./myapp) on
     Saturday, Jun 20, 2020 at 21:38:29
$ */

int fib(int );
int main();

static char *lance_static_t9 = "%d\n";

int fib(int n_2)
{
 int t1;
 int t2;
 int t3;
 int t4;
 int t5;
 int t6;
 int t7;


 /* 3 "/home/anushkini/Desktop/PD/plagtool/Test_lance/fib.c" */
 /* $ return n;$ */

	return n_2;


 /* 2 "/home/anushkini/Desktop/PD/plagtool/Test_lance/fib.c" */
 /* $ if(n <= 1)$ */

 LL1:

 /* 4 "/home/anushkini/Desktop/PD/plagtool/Test_lance/fib.c" */
 /* $ return fib(n-1) + fib(n-2);$ */

	t3 = n_2 - 1;
	t4 = fib(t3);
	t5 = n_2 - 2;
	t6 = fib(t5);
	t7 = t4 + t6;
	return t7;

}

int main()
{
 int n_5;
 int t8;
 int res_6;
 int t10;


 /* 9 "/home/anushkini/Desktop/PD/plagtool/Test_lance/fib.c" */
 /* $ int n = 10;$ */

	n_5 = 10;

 /* 10 "/home/anushkini/Desktop/PD/plagtool/Test_lance/fib.c" */
 /* $ int res = fib(n);$ */

	t8 = fib(n_5);
	res_6 = t8;

 /* 11 "/home/anushkini/Desktop/PD/plagtool/Test_lance/fib.c" */
 /* $ printf("%d\n",res);$ */

	t10 = printf(lance_static_t9,res_6);

 /* 0 "???" */
 /* $ ???$ */

	return;

}
