
/* 1 "LANCEV2" */
/* $
     IR file generated by LANCE V2.0 (compile) on
     Saturday, Jun 20, 2020 at 21:55:50
$ */

void add_sub(int ,int ,int *);
int main();

static char *lance_static_t12 = "%d %d\n";

void add_sub(int a_2,int b_3,int *ans_4)
{
 int t1;
 char *t2;
 int t3;
 char *t4;
 int *t5;
 int t6;
 char *t7;
 int t8;
 char *t9;
 int *t10;


 /* 2 "/home/anushkini/Desktop/PD/plagtool/Test_lance/addSub-2.c" */
 /* $ ans[0] = a+b;$ */

	t1 = a_2 + b_3;
	t4 = (char *)ans_4;
	t3 = 0 * 4;
	t2 = t4 + t3;
	t5 = (int *)t2;
	*t5 = t1;

 /* 3 "/home/anushkini/Desktop/PD/plagtool/Test_lance/addSub-2.c" */
 /* $ ans[1] = a-b;$ */

	t6 = a_2 - b_3;
	t9 = (char *)ans_4;
	t8 = 1 * 4;
	t7 = t9 + t8;
	t10 = (int *)t7;
	*t10 = t6;

 /* 0 "???" */
 /* $ ???$ */

	return;
}

int main()
{
 int a_7;
 int b_8;
 int ans_9[2];
 int t11;
 char *t13;
 int t14;
 char *t15;
 int *t16;
 char *t17;
 int t18;
 char *t19;
 int *t20;
 int t21;


 /* 7 "/home/anushkini/Desktop/PD/plagtool/Test_lance/addSub-2.c" */
 /* $ int a = 10;$ */

	a_7 = 10;

 /* 8 "/home/anushkini/Desktop/PD/plagtool/Test_lance/addSub-2.c" */
 /* $ int b = 15;$ */

	b_8 = 15;

 /* 10 "/home/anushkini/Desktop/PD/plagtool/Test_lance/addSub-2.c" */
 /* $ add_sub(a,b,ans);$ */

	add_sub(a_7,b_8,ans_9);

 /* 11 "/home/anushkini/Desktop/PD/plagtool/Test_lance/addSub-2.c" */
 /* $ printf("%d %d\n",ans[0],ans[1]);$ */

	t15 = (char *)ans_9;
	t14 = 0 * 4;
	t13 = t15 + t14;
	t16 = (int *)t13;
	t19 = (char *)ans_9;
	t18 = 1 * 4;
	t17 = t19 + t18;
	t20 = (int *)t17;
	t21 = printf(lance_static_t12,*t16,*t20);

 /* 0 "???" */
 /* $ ???$ */

	return;
}