
/* 1 "LANCEV2" */
/* $
     IR file generated by LANCE V2.0 (stcleanup) on
     Wednesday, Jun 24, 2020 at 10:14:25
$ */

int add(int ,int );
int sub(int ,int );
int main();

static char *lance_static_t11 = "%d %d\n";

int add(int a_2,int b_3)
{
 int c_5;
 int p_6;
 int t1;
 int t2;
 int t3;
 int t6;
 int t7;


 /* 9 "./addSub_plag_2.c" */
 /* $ for(p = 0; p < 0; p++) {$ */

	p_6 = 0;
	t1 = p_6 < 0;
	t6 = !t1;
	if (t6) goto LL1;

 LL3:
 LL2:
	t2 = p_6;
	t3 = t2 + 1;
	p_6 = t3;
	t1 = p_6 < 0;
	if (t1) goto LL3;

 LL1:

 /* 14 "./addSub_plag_2.c" */
 /* $ c = a + b ;$ */

	t7 = a_2 + b_3;
	c_5 = t7;

 /* 15 "./addSub_plag_2.c" */
 /* $ return c ;$ */

	return c_5;

}

int sub(int a_9,int b_10)
{
 int c_12;
 int t8;


 /* 21 "./addSub_plag_2.c" */
 /* $ c = a - b ;$ */

	t8 = a_9 - b_10;
	c_12 = t8;

 /* 22 "./addSub_plag_2.c" */
 /* $ return c ;$ */

	return c_12;

}

int main()
{
 int a_14;
 int b_15;
 int t9;
 int c_16;
 int t10;
 int d_17;
 int t12;


 /* 26 "./addSub_plag_2.c" */
 /* $ int a = 10;$ */

	a_14 = 10;

 /* 27 "./addSub_plag_2.c" */
 /* $ int b = 15;$ */

	b_15 = 15;

 /* 28 "./addSub_plag_2.c" */
 /* $ int c = add(a,b);$ */

	t9 = add(a_14,b_15);
	c_16 = t9;

 /* 29 "./addSub_plag_2.c" */
 /* $ int d = sub(a,b);$ */

	t10 = sub(a_14,b_15);
	d_17 = t10;

 /* 30 "./addSub_plag_2.c" */
 /* $ printf("%d %d\n",c,d);$ */

	t12 = printf(lance_static_t11,c_16,d_17);

 /* 0 "???" */
 /* $ ???$ */

	return;

}
