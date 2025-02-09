#include<stdio.h>
int main()
{
  int array[]={1,2,3,4,5,6,7,8,9};
  int searchelement=7;
  int start=0;
  int end=sizeof(array)/sizeof(array[0])-1;
  int mid=(start+end)/2;
  while(start<=end)
  {
    if(array[mid]==searchelement)
    {
      printf("found\n");
      break;
    }
    else if(array[mid]<searchelement)
    {
      start=mid+1;
    }
    else
    {
      end=mid-1;
    }
      mid=(start+end)/2;

  }
  return 0;
}