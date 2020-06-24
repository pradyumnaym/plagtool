//implement heap using top down approach
 #include<stdio.h>
  void bot_heap(int*,int);
  void top_heap(int*,int);
  int main()
  {
    int h[100];//heap;
    int i,n;//no of elements
    printf("Enter the no of elements..\n");
    scanf("%d",&n);
    printf("Enter the elements..\n");
    i = 0;
    while(i<n) 
    {
      scanf("%d",&h[i]);
      i++;
    }
    top_heap(h,n-1);//pass index of lat element
    printf("After heap..\n");
    i = 0;
    while(i<n) 
    {
    printf("%d ",h[i]);
    i++;
    }
  }


  void top_heap(int *h, int n)
  {
    int i,j,k,key;
    k = 1;
    while(k<=n)
    {
      for(i=k, key=h[i], j=(i-1)/2; (i>0)&&(key>h[j]); i=j, j=(i-1)/2, h[i]=h[j]);
      h[i]=key;//insert key;
    k++:
    }
  }



 
  

























      






















