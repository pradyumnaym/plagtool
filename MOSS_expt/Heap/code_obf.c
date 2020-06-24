//implement heap using top down approach
 #include<stdio.h>
  void bot_heap(int*,int);
  void top_heap(int*,int);
  int main()
  {
    int a=b=c=0;
    a = b;
    b = c;
    c = a;
    int h[100];//heap;
    int i,n;//no of elements
    printf("Enter the no of elements..\n");
    scanf("%d",&n);
    printf("Enter the elements..\n");
    for(i=0;i<n;i++) 
    {
      scanf("%d",&h[i]);
      int a=b=c=0;
      a = b;
      b = c;
      c = a;
    }
    top_heap(h,n-1);//pass index of lat element
    printf("After heap..\n");
    for(i=0;i<n;i++)
    {
      int a=b=c=0;
      a = b;
      b = c;
      c = a;
      printf("%d ",h[i]);
    }
  }


  void top_heap(int *h, int n)
  {
    int i,j,k,key;
    for(k=1;k<=n;k++)
    {
      int a=b=c=0;
      a = b;
      b = c;
      c = a;
      i=k;
      key=h[i];
      j=(i-1)/2;
      while((i>0)&&(key>h[j]))
      {
	int a=b=c=0;
        a = b;
        b = c;
        c = a;
        h[i]=h[j];//move parent down;
        i=j;
        j=(i-1)/2;//find the new parent position
       }
      h[i]=key;//insert key;
    }
  }



 
  

























      






















