
/* 1 "LANCEV2" */
/* $
     IR file generated by LANCE V2.0 (./myapp) on
     Saturday, Jun 20, 2020 at 21:55:51
$ */

int main();

static char *lance_static_t1 = "Enter the number of terms: ";

static char *lance_static_t4 = "%d";

static char *lance_static_t7 = "Fibonacci Series: ";

static char *lance_static_t11 = "%d, ";

static char *lance_static_t15 = "%d\n";

int main()
{
 int i_3;
 int n_4;
 int t1_5;
 int t2_6;
 int nextTerm_7;
 int t3;
 int *t5;
 int t6;
 int t8;
 int t9;
 int t10;
 int t14;
 int t16;
 int t12;
 int t13;


 /* 3 "/home/anushkini/Desktop/PD/plagtool/Test_lance/fib-3.c" */
 /* $ int i, n, t1 = 0, t2 = 1, nextTerm;$ */

	t1_5 = 0;
	t2_6 = 1;

 /* 4 "/home/anushkini/Desktop/PD/plagtool/Test_lance/fib-3.c" */
 /* $ printf("Enter the number of terms: ");$ */

	t3 = printf(lance_static_t1);

 /* 5 "/home/anushkini/Desktop/PD/plagtool/Test_lance/fib-3.c" */
 /* $ scanf("%d", &n);$ */

	t5 = &n_4;
	t6 = scanf(lance_static_t4,t5);

 /* 6 "/home/anushkini/Desktop/PD/plagtool/Test_lance/fib-3.c" */
 /* $ printf("Fibonacci Series: ");$ */

	t8 = printf(lance_static_t7);

 /* 8 "/home/anushkini/Desktop/PD/plagtool/Test_lance/fib-3.c" */
 /* $ for (i = 1; i <= n; ++i) {$ */

	if (t14) goto LL1;

 LL3:

 /* 9 "/home/anushkini/Desktop/PD/plagtool/Test_lance/fib-3.c" */
 /* $ printf("%d, ", t1);$ */

	t12 = printf(lance_static_t11,t1_5);

 /* 10 "/home/anushkini/Desktop/PD/plagtool/Test_lance/fib-3.c" */
 /* $ nextTerm = t1 + t2;$ */

	t13 = t1_5 + t2_6;
	nextTerm_7 = t13;

 /* 11 "/home/anushkini/Desktop/PD/plagtool/Test_lance/fib-3.c" */
 /* $ t1 = t2;$ */

	t1_5 = t2_6;

 /* 12 "/home/anushkini/Desktop/PD/plagtool/Test_lance/fib-3.c" */
 /* $ t2 = nextTerm;$ */

	t2_6 = nextTerm_7;

 /* 8 "/home/anushkini/Desktop/PD/plagtool/Test_lance/fib-3.c" */
 /* $ for (i = 1; i <= n; ++i) {$ */

 LL1:

 /* 15 "/home/anushkini/Desktop/PD/plagtool/Test_lance/fib-3.c" */
 /* $ printf("%d\n",nextTerm);$ */

	t16 = printf(lance_static_t15,nextTerm_7);

 /* 0 "???" */
 /* $ ???$ */

	return;

}
