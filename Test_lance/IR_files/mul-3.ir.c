
/* 1 "LANCEV2" */
/* $
     IR file generated by LANCE V2.0 (./myapp) on
     Saturday, Jun 20, 2020 at 21:38:29
$ */

int factorial(int );
int main();

static char *lance_static_t6 = "Factorial of %d is %d";

int factorial(int n_2)
{
 int t1;
 int t2;
 int t3;
 int t4;
 int t5;


 /* 4 "/home/anushkini/Desktop/PD/plagtool/Test_lance/mul-3.c" */
 /* $ return 1;$ */

	return 1;


 /* 3 "/home/anushkini/Desktop/PD/plagtool/Test_lance/mul-3.c" */
 /* $ if(n==1)$ */

 LL1:

 /* 5 "/home/anushkini/Desktop/PD/plagtool/Test_lance/mul-3.c" */
 /* $ return n * factorial(n-1);$ */

	t3 = n_2 - 1;
	t4 = factorial(t3);
	t5 = n_2 * t4;
	return t5;

}

int main()
{
 int num_5;
 int t7;
 int t8;


 /* 10 "/home/anushkini/Desktop/PD/plagtool/Test_lance/mul-3.c" */
 /* $ int num = 5;$ */

	num_5 = 5;

 /* 11 "/home/anushkini/Desktop/PD/plagtool/Test_lance/mul-3.c" */
 /* $ printf("Factorial of %d is %d", num, factoria ...m$ */

	t7 = factorial(num_5);
	t8 = printf(lance_static_t6,num_5,t7);

 /* 12 "/home/anushkini/Desktop/PD/plagtool/Test_lance/mul-3.c" */
 /* $ return 0;$ */

	return 0;

}
