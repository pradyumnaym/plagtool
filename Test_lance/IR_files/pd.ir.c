
/* 1 "LANCEV2" */
/* $
     IR file generated by LANCE V2.0 (./myapp) on
     Saturday, Jun 20, 2020 at 21:38:30
$ */

int print_digits(int );
int main();

static char *lance_static_t3 = "%d ";

static char *lance_static_t8 = "%d\n";

int print_digits(int n_2)
{
 int temp_4;
 int t1;
 int t6;
 int t2;
 int t4;
 int t5;


 /* 4 "/home/anushkini/Desktop/PD/plagtool/Test_lance/pd.c" */
 /* $ temp = n % 10;$ */

	t2 = n_2 % 10;
	temp_4 = t2;

 /* 5 "/home/anushkini/Desktop/PD/plagtool/Test_lance/pd.c" */
 /* $ printf("%d ",temp);$ */

	t4 = printf(lance_static_t3,temp_4);

 /* 6 "/home/anushkini/Desktop/PD/plagtool/Test_lance/pd.c" */
 /* $ n = n / 10;$ */

	t5 = n_2 / 10;
	n_2 = t5;

 /* 3 "/home/anushkini/Desktop/PD/plagtool/Test_lance/pd.c" */
 /* $ while(n >= 10) {$ */

 LL1:

 /* 8 "/home/anushkini/Desktop/PD/plagtool/Test_lance/pd.c" */
 /* $ return temp;$ */

	return temp_4;

}

int main()
{
 int n_7;
 int t7;
 int l_8;
 int t9;


 /* 13 "/home/anushkini/Desktop/PD/plagtool/Test_lance/pd.c" */
 /* $ int n = 12345;$ */

	n_7 = 12345;

 /* 14 "/home/anushkini/Desktop/PD/plagtool/Test_lance/pd.c" */
 /* $ int l = print_digits(n);$ */

	t7 = print_digits(n_7);
	l_8 = t7;

 /* 15 "/home/anushkini/Desktop/PD/plagtool/Test_lance/pd.c" */
 /* $ printf("%d\n",l);$ */

	t9 = printf(lance_static_t8,l_8);

 /* 0 "???" */
 /* $ ???$ */

	return;

}
