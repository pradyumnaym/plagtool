
/* 1 "LANCEV2" */
/* $
     IR file generated by LANCE V2.0 (stcleanup) on
     Tuesday, Jun 23, 2020 at 14:48:01
$ */

int add(int ,int );
int sub(int ,int );
int main();

static char *lance_static_t9 = "%d %d\n";

int add(int a_2,int b_3)
{
 int c_5;
 int p_6;
 int t1;
 int t4;
 int t5;


 /* 6 "./addSub_plag_3.c" */
 /* $ int p = 0;$ */

	p_6 = 0;

 /* 9 "./addSub_plag_3.c" */
 /* $ while(p != 0) {$ */

 LL3:
	t1 = p_6 != 0;
	t4 = !t1;
	if (t4) goto LL1;

 LL2:
	goto LL3;

 LL1:

 /* 14 "./addSub_plag_3.c" */
 /* $ c = a + b ;$ */

	t5 = a_2 + b_3;
	c_5 = t5;

 /* 15 "./addSub_plag_3.c" */
 /* $ return c ;$ */

	return c_5;

}

int sub(int a_9,int b_10)
{
 int c_12;
 int t6;


 /* 21 "./addSub_plag_3.c" */
 /* $ c = a - b ;$ */

	t6 = a_9 - b_10;
	c_12 = t6;

 /* 22 "./addSub_plag_3.c" */
 /* $ return c ;$ */

	return c_12;

}

int main()
{
 int a_14;
 int b_15;
 int t7;
 int c_16;
 int t8;
 int d_17;
 int t10;


 /* 26 "./addSub_plag_3.c" */
 /* $ int a = 10;$ */

	a_14 = 10;

 /* 27 "./addSub_plag_3.c" */
 /* $ int b = 15;$ */

	b_15 = 15;

 /* 28 "./addSub_plag_3.c" */
 /* $ int c = add(a,b);$ */

	t7 = add(a_14,b_15);
	c_16 = t7;

 /* 29 "./addSub_plag_3.c" */
 /* $ int d = sub(a,b);$ */

	t8 = sub(a_14,b_15);
	d_17 = t8;

 /* 30 "./addSub_plag_3.c" */
 /* $ printf("%d %d\n",c,d);$ */

	t10 = printf(lance_static_t9,c_16,d_17);

 /* 0 "???" */
 /* $ ???$ */

	return;

}