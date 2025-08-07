#include<stdio.h>
void Trangle(int);
int main()
{
 Trangle(5);
 return 0;
}
void Trangle(int n)
{
    if(n<=0)
    {
        return;
    }else
    {
        Trangle(n-1);
    }
    for(int i=1;i<=n;i++)
    {
        printf("* ");
    }
    printf("\n");
}