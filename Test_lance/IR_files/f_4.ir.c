
/* 1 "LANCEV2" */
/* $
     IR file generated by LANCE V2.0 (./myapp) on
     Saturday, Jun 20, 2020 at 21:55:51
$ */

int factorial(int );
int main();

static char *lance_static_t9 = "Factorial of %d is %d";

int main()
{
 int mun_4;
 int a_5;
 int b_6;
 int c_7;
 int num_8;
 int t1;
 int t8;
 int t10;
 int t11;
 int t2;
 int t3;
 int t4;
 int t5;
 int t6;
 int t7;


 /* 6 "/home/anushkini/Desktop/PD/plagtool/Test_lance/f_4.c" */
 /* $ int num = 5;$ */

	num_8 = 5;

 /* 7 "/home/anushkini/Desktop/PD/plagtool/Test_lance/f_4.c" */
 /* $ num = num;$ */

	num_8 = num_8;

 /* 11 "/home/anushkini/Desktop/PD/plagtool/Test_lance/f_4.c" */
 /* $ while(a ==1){$ */

 LL1:

 /* 15 "/home/anushkini/Desktop/PD/plagtool/Test_lance/f_4.c" */
 /* $ printf("Factorial of %d is %d", num, factoria ...m$ */

	t10 = factorial(num_8);
	t11 = printf(lance_static_t9,num_8,t10);

 /* 16 "/home/anushkini/Desktop/PD/plagtool/Test_lance/f_4.c" */
 /* $ return 0;$ */

	return 0;

}

int factorial(int n_10)
{
 int a_12;
 int b_13;
 int c_14;
 int t12;
 int t13;
 int t14;
 int t15;
 int t16;
 int t17;
 int t18;
 int t19;
 int t20;
 int t21;
 int t22;
 int t23;
 int t24;
 int t25;


 /* 22 "/home/anushkini/Desktop/PD/plagtool/Test_lance/f_4.c" */
 /* $ return 1;for(a=0;a;a++){a = b;b= c;c = a;$ */

	return 1;

 LL5:

 /* 23 "/home/anushkini/Desktop/PD/plagtool/Test_lance/f_4.c" */
 /* $ }a++;b++;c++;return n * factorial(n-1);$ */

	t23 = n_10 - 1;
	t24 = factorial(t23);
	t25 = n_10 * t24;
	return t25;

}
