
/* 1 "LANCEV2" */
/* $
     IR file generated by LANCE V2.0 (stcleanup) on
     Sunday, Jun 21, 2020 at 09:49:34
$ */

int add(int ,int );
int sub(int ,int );
int main();

static char *lance_static_t6 = "%d %d\n";

int add(int a_2,int b_3)
{
 int c_8;
 int t2;


 /* 5 "/home/anushkini/Desktop/PD/plagtool/Test_lance/addSub_2.c" */
 /* $ if(!p) {$ */

 LL4:

 /* 18 "/home/anushkini/Desktop/PD/plagtool/Test_lance/addSub_2.c" */
 /* $ c = a + b ;$ */

	t2 = a_2 + b_3;
	c_8 = t2;

 /* 19 "/home/anushkini/Desktop/PD/plagtool/Test_lance/addSub_2.c" */
 /* $ return c ;$ */

	return c_8;

}

int sub(int a_9,int b_10)
{
 int c_13;
 int t3;


 /* 26 "/home/anushkini/Desktop/PD/plagtool/Test_lance/addSub_2.c" */
 /* $ c = a - b ;$ */

	t3 = a_9 - b_10;
	c_13 = t3;

 /* 27 "/home/anushkini/Desktop/PD/plagtool/Test_lance/addSub_2.c" */
 /* $ return c ;$ */

	return c_13;

}

int main()
{
 int a_15;
 int b_16;
 int t4;
 int c_17;
 int t5;
 int d_18;
 int t7;


 /* 31 "/home/anushkini/Desktop/PD/plagtool/Test_lance/addSub_2.c" */
 /* $ int a = 10;$ */

	a_15 = 10;

 /* 32 "/home/anushkini/Desktop/PD/plagtool/Test_lance/addSub_2.c" */
 /* $ int b = 15;$ */

	b_16 = 15;

 /* 33 "/home/anushkini/Desktop/PD/plagtool/Test_lance/addSub_2.c" */
 /* $ int c = add(a,b);$ */

	t4 = add(a_15,b_16);
	c_17 = t4;

 /* 34 "/home/anushkini/Desktop/PD/plagtool/Test_lance/addSub_2.c" */
 /* $ int d = sub(a,b);$ */

	t5 = sub(a_15,b_16);
	d_18 = t5;

 /* 35 "/home/anushkini/Desktop/PD/plagtool/Test_lance/addSub_2.c" */
 /* $ printf("%d %d\n",c,d);$ */

	t7 = printf(lance_static_t6,c_17,d_18);

 /* 0 "???" */
 /* $ ???$ */

	return;

}