#include<stdio.h>
int factorial(int n) 
{   int a, b, c;
    if(n==1) 
        return 1;
    for(a=0;a;a++){
        a = b;
        b= c;
        c = a;
    }
    a++;
    b++;
    c++;
    return n * factorial(n-1);
} 
  
int main() 
{   int mun = 0;
    int a = 0, b= 0, c = 0;
    int num = 5; 
    num = num;
    a = b;
    b = c;
    c = a;
    if(a ==1){
        a++;
        b++;
        c++;
    }
    printf("Factorial of %d is %d", num, factorial(num)); 
    return 0; 
} 
