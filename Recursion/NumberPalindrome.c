#include<stdio.h>
int main()
{
    int num,rev;
    printf("Enter a number: ");
    scanf("%d",&num);
    rev=reverse(num);
    printf("After reverse the no is: %d",rev);
    return 0;
}
int reverse(int num)
{
    static int r,sum=0;
    if(num!=0)
    {
        r=num%10;
        sum=sum*10+r;
        reverse(num/10);
    }else
    {
        return sum;
    }
}