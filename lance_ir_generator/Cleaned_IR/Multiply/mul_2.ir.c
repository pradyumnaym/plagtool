
/* 1 "LANCEV2" */
/* $
     IR file generated by LANCE V2.0 (stcleanup) on
     Sunday, Jun 21, 2020 at 09:49:34
$ */

int mul(int ,int );
int main();

static char *lance_static_t7 = "Product: %d\n";

int mul(int a_2,int b_3)
{
 int res_5;
 int t5;
 int t4;


 /* 2 "/home/anushkini/Desktop/PD/plagtool/Test_lance/mul_2.c" */
 /* $ int res = 0, i;$ */

	res_5 = 0;

 /* 3 "/home/anushkini/Desktop/PD/plagtool/Test_lance/mul_2.c" */
 /* $ for(i = 0; i < b; i++) {$ */

	if (t5) goto LL1;

 LL3:

 /* 4 "/home/anushkini/Desktop/PD/plagtool/Test_lance/mul_2.c" */
 /* $ res += a;$ */

	t4 = res_5 + a_2;
	res_5 = t4;

 /* 3 "/home/anushkini/Desktop/PD/plagtool/Test_lance/mul_2.c" */
 /* $ for(i = 0; i < b; i++) {$ */

 LL1:

 /* 6 "/home/anushkini/Desktop/PD/plagtool/Test_lance/mul_2.c" */
 /* $ return res;$ */

	return res_5;

}

int main()
{
 int a_8;
 int b_9;
 int t6;
 int res_10;
 int t8;


 /* 10 "/home/anushkini/Desktop/PD/plagtool/Test_lance/mul_2.c" */
 /* $ int a = 5;$ */

	a_8 = 5;

 /* 11 "/home/anushkini/Desktop/PD/plagtool/Test_lance/mul_2.c" */
 /* $ int b = 3;$ */

	b_9 = 3;

 /* 12 "/home/anushkini/Desktop/PD/plagtool/Test_lance/mul_2.c" */
 /* $ int res = mul(a,b);$ */

	t6 = mul(a_8,b_9);
	res_10 = t6;

 /* 13 "/home/anushkini/Desktop/PD/plagtool/Test_lance/mul_2.c" */
 /* $ printf("Product: %d\n",res);$ */

	t8 = printf(lance_static_t7,res_10);

 /* 0 "???" */
 /* $ ???$ */

	return;

}
