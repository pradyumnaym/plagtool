
/* 1 "LANCEV2" */
/* $
     IR file generated by LANCE V2.0 (stcleanup) on
     Sunday, Jun 21, 2020 at 09:49:34
$ */

int add(int ,int );
int sub(int ,int );
int main();

static char *lance_static_t35 = "%d %d\n";

int add(int n1_2,int n2_3)
{
 int n3_5;
 int t16;


 /* 4 "/home/anushkini/Desktop/PD/plagtool/Test_lance/addSub_5.c" */
 /* $ for(a = 0;a;a++){$ */

 LL1:

 /* 15 "/home/anushkini/Desktop/PD/plagtool/Test_lance/addSub_5.c" */
 /* $ n3 = n1 + n2;$ */

	t16 = n1_2 + n2_3;
	n3_5 = t16;

 /* 16 "/home/anushkini/Desktop/PD/plagtool/Test_lance/addSub_5.c" */
 /* $ return n3;$ */

	return n3_5;

}

int sub(int n1_9,int n2_10)
{
 int n3_12;
 int t17;
 int t20;


 /* 22 "/home/anushkini/Desktop/PD/plagtool/Test_lance/addSub_5.c" */
 /* $ n3 = n1 - n2;$ */

	t17 = n1_9 - n2_10;
	n3_12 = t17;

 /* 24 "/home/anushkini/Desktop/PD/plagtool/Test_lance/addSub_5.c" */
 /* $ for(a = 0;a;a++){$ */

	if (t20) goto LL4;

 LL4:

 /* 35 "/home/anushkini/Desktop/PD/plagtool/Test_lance/addSub_5.c" */
 /* $ return n3;$ */

	return n3_12;

}

int main()
{
 int n1_17;
 int n2_18;
 int t33;
 int t34;
 int t36;


 /* 39 "/home/anushkini/Desktop/PD/plagtool/Test_lance/addSub_5.c" */
 /* $ int n1 = 10;$ */

	n1_17 = 10;

 /* 40 "/home/anushkini/Desktop/PD/plagtool/Test_lance/addSub_5.c" */
 /* $ int n2 = 15;$ */

	n2_18 = 15;

 /* 41 "/home/anushkini/Desktop/PD/plagtool/Test_lance/addSub_5.c" */
 /* $ int n3 = add(n1,n2);$ */

	t33 = add(n1_17,n2_18);

 /* 42 "/home/anushkini/Desktop/PD/plagtool/Test_lance/addSub_5.c" */
 /* $ int n4 = sub(n1,n2);$ */

	t34 = sub(n1_17,n2_18);

 /* 43 "/home/anushkini/Desktop/PD/plagtool/Test_lance/addSub_5.c" */
 /* $ printf("%d %d\n",n1,n2);$ */

	t36 = printf(lance_static_t35,n1_17,n2_18);

 /* 0 "???" */
 /* $ ???$ */

	return;

}
