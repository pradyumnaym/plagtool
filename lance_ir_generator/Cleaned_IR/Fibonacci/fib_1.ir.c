
/* 1 "LANCEV2" */
/* $
     IR file generated by LANCE V2.0 (stcleanup) on
     Sunday, Jun 21, 2020 at 09:49:34
$ */

int fib(int );
int main();

static char *lance_static_t11 = "%d\n";

int fib(int n_2)
{
 int t3;
 int t4;
 int t5;
 int t6;
 int t7;


 /* 3 "/home/anushkini/Desktop/PD/plagtool/Test_lance/fib_1.c" */
 /* $ return n;$ */

	return n_2;


 /* 2 "/home/anushkini/Desktop/PD/plagtool/Test_lance/fib_1.c" */
 /* $ if(n <= 1)$ */

 LL1:

 /* 4 "/home/anushkini/Desktop/PD/plagtool/Test_lance/fib_1.c" */
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
 int n_8;
 int t10;
 int res_9;
 int t12;


 /* 12 "/home/anushkini/Desktop/PD/plagtool/Test_lance/fib_1.c" */
 /* $ int n = 10;$ */

	n_8 = 10;

 /* 13 "/home/anushkini/Desktop/PD/plagtool/Test_lance/fib_1.c" */
 /* $ int res = fib(n);$ */

	t10 = fib(n_8);
	res_9 = t10;

 /* 14 "/home/anushkini/Desktop/PD/plagtool/Test_lance/fib_1.c" */
 /* $ printf("%d\n",res);$ */

	t12 = printf(lance_static_t11,res_9);

 /* 0 "???" */
 /* $ ???$ */

	return;

}