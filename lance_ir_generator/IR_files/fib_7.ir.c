
/* 1 "LANCEV2" */
/* $
     IR file generated by LANCE V2.0 (./myapp) on
     Saturday, Jun 20, 2020 at 21:55:51
$ */

int fib(int );
int main();

static char *lance_static_t20 = "%d\n";

int fib(int n_2)
{
 int t1;
 int t2;
 int t3;
 int t4;
 int t5;
 int t6;
 int t7;


 /* 3 "/home/anushkini/Desktop/PD/plagtool/Test_lance/fib_7.c" */
 /* $ return n;$ */

	return n_2;


 /* 2 "/home/anushkini/Desktop/PD/plagtool/Test_lance/fib_7.c" */
 /* $ if(n <= 1)$ */

 LL1:

 /* 4 "/home/anushkini/Desktop/PD/plagtool/Test_lance/fib_7.c" */
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
 int pym_7;
 int t9;
 int avk_8;
 int t10;
 int rn_9;
 int t11;
 int t12;
 int t13;
 int t19;
 int t21;
 int t14;
 int t15;
 int t16;
 int t17;
 int t18;


 /* 9 "/home/anushkini/Desktop/PD/plagtool/Test_lance/fib_7.c" */
 /* $ int n = 10;$ */

	n_5 = 10;

 /* 10 "/home/anushkini/Desktop/PD/plagtool/Test_lance/fib_7.c" */
 /* $ int res = fib(n);$ */

	t8 = fib(n_5);
	res_6 = t8;

 /* 14 "/home/anushkini/Desktop/PD/plagtool/Test_lance/fib_7.c" */
 /* $ if(pym){$ */

	if (t11) goto LL2;


 /* 20 "/home/anushkini/Desktop/PD/plagtool/Test_lance/fib_7.c" */
 /* $ for(pym = 0;pym;pym++){$ */

 LL3:

 /* 25 "/home/anushkini/Desktop/PD/plagtool/Test_lance/fib_7.c" */
 /* $ printf("%d\n",res);$ */

	t21 = printf(lance_static_t20,res_6);

 /* 0 "???" */
 /* $ ???$ */

	return;

}