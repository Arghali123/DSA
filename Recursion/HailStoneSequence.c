#include<stdio.h>
void hailStoneSequence(int n,int count)
{
  if(count==10)
  {
    return;
  }
  if(n%2==0)
  {
   printf("%d ",n);
   n=n/2;
   count++;
   hailStoneSequence(n,count);
  }else 
  {
    printf("%d ",n);
    n=(n*3)+1;
    count++;
    hailStoneSequence(n,count);
  }
}
int main()
{
    int n;
    printf("Enter a positive number: ");
    scanf("%d",&n);
    hailStoneSequence(n,0);
    return 0;
}