
/* 1 "LANCEV2" */
/* $
     IR file generated by LANCE V2.0 (compile) on
     Saturday, Jun 20, 2020 at 21:38:30
$ */

void swap(int *,int *);
int main();

static char *lance_static_t4 = "The swapped numbers are %d and %d";

void swap(int *a_2,int *b_3)
{
 int temp_5;


 /* 4 "/home/anushkini/Desktop/PD/plagtool/Test_lance/s_1.c" */
 /* $ temp = *a;$ */

	temp_5 = *a_2;

 /* 5 "/home/anushkini/Desktop/PD/plagtool/Test_lance/s_1.c" */
 /* $ *a = *b;$ */

	*a_2 = *b_3;

 /* 6 "/home/anushkini/Desktop/PD/plagtool/Test_lance/s_1.c" */
 /* $ *b = temp;$ */

	*b_3 = temp_5;

 /* 0 "???" */
 /* $ ???$ */

	return;
}

int main()
{
 int a_7;
 int b_8;
 int *t1;
 int *t2;
 int t3;
 int t5;


 /* 10 "/home/anushkini/Desktop/PD/plagtool/Test_lance/s_1.c" */
 /* $ int a = 3;$ */

	a_7 = 3;

 /* 11 "/home/anushkini/Desktop/PD/plagtool/Test_lance/s_1.c" */
 /* $ int b = 5;$ */

	b_8 = 5;

 /* 13 "/home/anushkini/Desktop/PD/plagtool/Test_lance/s_1.c" */
 /* $ swap(&a, &b);$ */

	t1 = &a_7;
	t2 = &b_8;
	swap(t1,t2);

 /* 14 "/home/anushkini/Desktop/PD/plagtool/Test_lance/s_1.c" */
 /* $ printf("The swapped numbers are %d and %d",a,b);$ */

	t5 = printf(lance_static_t4,a_7,b_8);

 /* 0 "???" */
 /* $ ???$ */

	return;
}
