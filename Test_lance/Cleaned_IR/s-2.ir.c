
/* 1 "LANCEV2" */
/* $
     IR file generated by LANCE V2.0 (./myapp) on
     Saturday, Jun 20, 2020 at 21:55:51
$ */

int main();

static char *lance_static_t4 = "The swapped numbers are %d and %d";

int main()
{
 int a_3;
 int b_4;
 int t1;
 int t2;
 int t3;
 int t5;


 /* 2 "/home/anushkini/Desktop/PD/plagtool/Test_lance/s-2.c" */
 /* $ int a = 3;$ */

	a_3 = 3;

 /* 3 "/home/anushkini/Desktop/PD/plagtool/Test_lance/s-2.c" */
 /* $ int b = 5;$ */

	b_4 = 5;

 /* 5 "/home/anushkini/Desktop/PD/plagtool/Test_lance/s-2.c" */
 /* $ a = a ^ b;$ */

	t1 = a_3 ^ b_4;
	a_3 = t1;

 /* 6 "/home/anushkini/Desktop/PD/plagtool/Test_lance/s-2.c" */
 /* $ b = a^b;$ */

	t2 = a_3 ^ b_4;
	b_4 = t2;

 /* 7 "/home/anushkini/Desktop/PD/plagtool/Test_lance/s-2.c" */
 /* $ a = a^ b;$ */

	t3 = a_3 ^ b_4;
	a_3 = t3;

 /* 9 "/home/anushkini/Desktop/PD/plagtool/Test_lance/s-2.c" */
 /* $ printf("The swapped numbers are %d and %d",a,b);$ */

	t5 = printf(lance_static_t4,a_3,b_4);

 /* 0 "???" */
 /* $ ???$ */

	return;

}
