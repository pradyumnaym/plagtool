
/* 1 "LANCEV2" */
/* $
     IR file generated by LANCE V2.0 (./myapp) on
     Saturday, Jun 20, 2020 at 21:55:51
$ */

int factorial(int );
int main();

static char *lance_static_t6 = "Factorial of %d is %d";

int factorial(int n_2)
{
 int res_4;
 int i_5;
 int t1;
 int t2;
 int t3;
 int t4;
 int t5;


 /* 3 "/home/anushkini/Desktop/PD/plagtool/Test_lance/f_7.c" */
 /* $ int res = 1, i;$ */

	res_4 = 1;

 /* 4 "/home/anushkini/Desktop/PD/plagtool/Test_lance/f_7.c" */
 /* $ for (i = 2; i <= n; i++)$ */

	i_5 = 2;
	if (t5) goto LL1;

 LL3:

 /* 5 "/home/anushkini/Desktop/PD/plagtool/Test_lance/f_7.c" */
 /* $ res *= i;$ */

	t4 = res_4 * i_5;
	res_4 = t4;

 /* 4 "/home/anushkini/Desktop/PD/plagtool/Test_lance/f_7.c" */
 /* $ for (i = 2; i <= n; i++)$ */

 LL2:
	t2 = i_5;
	t3 = t2 + 1;
	i_5 = t3;
	if (t1) goto LL3;

 LL1:

 /* 6 "/home/anushkini/Desktop/PD/plagtool/Test_lance/f_7.c" */
 /* $ return res;$ */

	return res_4;

}

int main()
{
 int num_7;
 int t7;
 int t8;


 /* 11 "/home/anushkini/Desktop/PD/plagtool/Test_lance/f_7.c" */
 /* $ int num = 5;$ */

	num_7 = 5;

 /* 12 "/home/anushkini/Desktop/PD/plagtool/Test_lance/f_7.c" */
 /* $ printf("Factorial of %d is %d", num, factoria ...m$ */

	t7 = factorial(num_7);
	t8 = printf(lance_static_t6,num_7,t7);

 /* 13 "/home/anushkini/Desktop/PD/plagtool/Test_lance/f_7.c" */
 /* $ return 0;$ */

	return 0;

}
