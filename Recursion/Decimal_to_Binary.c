#include<stdio.h>
void decimalToBinary(int n);
int main()
{
    int n;
    printf("Enter the decimal number: ");
    scanf("%d",&n);
    decimalToBinary(n);
    return 0;
}
void decimalToBinary(int n)
{
    int x;
    if(n==1)
    {
        printf("1 ");
        return;
    }
    if(n%2==0)
    {
        x=0;
    }else
    {
        x=1;
    }
    decimalToBinary(n/2);
    printf("%d ",x);
}