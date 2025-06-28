#include<stdio.h>
int main()
{
    int i;
    int a[]={1,23,17,4,-5,100};
    int *ptr;
    ptr=&a[0];
    for(i=0;i<6;i++)
    {
        printf("a[%d]= %d\n",i,a[i]);
        printf("ptr+ %d= %d\n\n",i,*(ptr+i));
    }
    return 0;
}