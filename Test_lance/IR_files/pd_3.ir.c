
/* 1 "LANCEV2" */
/* $
     IR file generated by LANCE V2.0 (./myapp) on
     Saturday, Jun 20, 2020 at 21:38:29
$ */

int DigitPrinter(int );
int main();

static char *lance_static_t3 = "%d ";

static char *lance_static_t8 = "%d\n";

int DigitPrinter(int num_2)
{
 int digit_4;
 int t1;
 int t6;
 int t2;
 int t4;
 int t5;


 /* 4 "/home/anushkini/Desktop/PD/plagtool/Test_lance/pd_3.c" */
 /* $ digit = num % 10;$ */

	t2 = num_2 % 10;
	digit_4 = t2;

 /* 5 "/home/anushkini/Desktop/PD/plagtool/Test_lance/pd_3.c" */
 /* $ printf("%d ",digit);$ */

	t4 = printf(lance_static_t3,digit_4);

 /* 6 "/home/anushkini/Desktop/PD/plagtool/Test_lance/pd_3.c" */
 /* $ num = num / 10;$ */

	t5 = num_2 / 10;
	num_2 = t5;

 /* 3 "/home/anushkini/Desktop/PD/plagtool/Test_lance/pd_3.c" */
 /* $ while(num >= 10) {$ */

 LL1:

 /* 8 "/home/anushkini/Desktop/PD/plagtool/Test_lance/pd_3.c" */
 /* $ return digit;$ */

	return digit_4;

}

int main()
{
 int num_7;
 int t7;
 int l_digit_8;
 int t9;


 /* 13 "/home/anushkini/Desktop/PD/plagtool/Test_lance/pd_3.c" */
 /* $ int num = 12345;$ */

	num_7 = 12345;

 /* 14 "/home/anushkini/Desktop/PD/plagtool/Test_lance/pd_3.c" */
 /* $ int l_digit = DigitPrinter(num);$ */

	t7 = DigitPrinter(num_7);
	l_digit_8 = t7;

 /* 15 "/home/anushkini/Desktop/PD/plagtool/Test_lance/pd_3.c" */
 /* $ printf("%d\n",l_digit);$ */

	t9 = printf(lance_static_t8,l_digit_8);

 /* 0 "???" */
 /* $ ???$ */

	return;

}
