
/* 1 "LANCEV2" */
/* $
     IR file generated by LANCE V2.0 (stcleanup) on
     Sunday, Jun 21, 2020 at 09:49:34
$ */

void print_digits(int );
int main();

static char *lance_static_t6 = "%d ";

void print_digits(int n_2)
{
 int temp_4;
 int t3;
 int t4;
 int t7;
 int t8;


 /* 4 "/home/anushkini/Desktop/PD/plagtool/Test_lance/pd-1.c" */
 /* $ return;$ */

	return;


 /* 3 "/home/anushkini/Desktop/PD/plagtool/Test_lance/pd-1.c" */
 /* $ if(n == 0)$ */

 LL1:

 /* 5 "/home/anushkini/Desktop/PD/plagtool/Test_lance/pd-1.c" */
 /* $ temp = n % 10;$ */

	t3 = n_2 % 10;
	temp_4 = t3;

 /* 6 "/home/anushkini/Desktop/PD/plagtool/Test_lance/pd-1.c" */
 /* $ print_digits(n/10);$ */

	t4 = n_2 / 10;
	print_digits(t4);

 /* 7 "/home/anushkini/Desktop/PD/plagtool/Test_lance/pd-1.c" */
 /* $ printf("%d ",temp);$ */

	t7 = printf(lance_static_t6,temp_4);

 /* 0 "???" */
 /* $ ???$ */

	return;

}

int main()
{
 int n_7;
 int t9;


 /* 12 "/home/anushkini/Desktop/PD/plagtool/Test_lance/pd-1.c" */
 /* $ int n = 12345;$ */

	n_7 = 12345;

 /* 13 "/home/anushkini/Desktop/PD/plagtool/Test_lance/pd-1.c" */
 /* $ print_digits(n);$ */

	print_digits(n_7);

 /* 0 "???" */
 /* $ ???$ */

	return;

}
