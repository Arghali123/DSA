#include<stdio.h>
const int MAX=3;
int main()
{
 int var[]={10,100,200};
 int i,*ptr[MAX-1];

 for(int i=0;i<MAX;i++)
 {
    ptr[i]=&var[i];
 }

 for(i=0;i<MAX;i++)
 {
    printf("Value of var[%d] at address %u is %d\n",i,ptr[i],*ptr[i]);
 }
 return 0;
}