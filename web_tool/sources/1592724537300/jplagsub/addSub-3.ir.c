
/* 1 "LANCEV2" */
/* $
     IR file generated by LANCE V2.0 (compile) on
     Sunday, Jun 21, 2020 at 12:59:22
$ */

int main();

static char *lance_static_t1 = "%d %d\n";

int main()
{
 int a_3;
 int b_4;
 int t2;
 int t3;
 int t4;


 /* 3 "./addSub-3.c" */
 /* $ int a = 10;$ */

	a_3 = 10;

 /* 4 "./addSub-3.c" */
 /* $ int b = 15;$ */

	b_4 = 15;

 /* 5 "./addSub-3.c" */
 /* $ printf("%d %d\n",a+b, a-b);$ */

	t2 = a_3 + b_4;
	t3 = a_3 - b_4;
	t4 = printf(lance_static_t1,t2,t3);

 /* 0 "???" */
 /* $ ???$ */

	return;
}