
/* 1 "LANCEV2" */
/* $
     IR file generated by LANCE V2.0 (stcleanup) on
     Sunday, Jun 21, 2020 at 09:49:34
$ */

int factl(int );
int main();

static char *lance_static_t6 = "Factorial of %d is %d";

int factl(int n_2)
{
 int res_4;
 int i_5;
 int t1;
 int t2;
 int t3;
 int t5;
 int t4;


 /* 3 "/home/anushkini/Desktop/PD/plagtool/Test_lance/f_5.c" */
 /* $ int res = 1, i;$ */

	res_4 = 1;

 /* 8 "/home/anushkini/Desktop/PD/plagtool/Test_lance/f_5.c" */
 /* $ for (i = 2; i <= n; i++) {$ */

	i_5 = 2;
	if (t5) goto LL1;

 LL3:

 /* 13 "/home/anushkini/Desktop/PD/plagtool/Test_lance/f_5.c" */
 /* $ res *= i;$ */

	t4 = res_4 * i_5;
	res_4 = t4;

 /* 8 "/home/anushkini/Desktop/PD/plagtool/Test_lance/f_5.c" */
 /* $ for (i = 2; i <= n; i++) {$ */

 LL2:
	t2 = i_5;
	t3 = t2 + 1;
	i_5 = t3;
	if (t1) goto LL3;

 LL1:

 /* 19 "/home/anushkini/Desktop/PD/plagtool/Test_lance/f_5.c" */
 /* $ return res;$ */

	return res_4;

}

int main()
{
 int t7;
 int t8;


 /* 24 "/home/anushkini/Desktop/PD/plagtool/Test_lance/f_5.c" */
 /* $ printf("Factorial of %d is %d", 5, fact(5));$ */

	t7 = fact(5);
	t8 = printf(lance_static_t6,5,t7);

 /* 0 "???" */
 /* $ ???$ */

	return;

}
