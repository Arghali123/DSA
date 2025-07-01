# Categories of user defined functions
Depending on the number of arguments,types of arguments and return type of the function,the user defined functions can be categorized as below:
- Function returning value and passing arguments.
- Function returning no value and passing arguments.
- Function returning value and passing no arguments.
- Function returning no value and passing no arguments.

## Function returning value and passing arguments
```
#include<stdio.h>
int product(int,int);//Function prototype
int main()
{
 int a,b,c;
 printf("Enter two numbers: ");
 scanf("%d%d",&a,&b);
 c=product(a,b);//function calling
 printf("The product of two numbers is: %d",c);
 return 0;
}

int product(int a,int b)//Function definition
{
    return a*b;
}
```

## Function returning no value and passing arguments
```
#include<stdio.h>
void product(int,int);//Function prototype
int main()
{
    int a,b;
    printf("Enter two numbers: ");
    scanf("%d%d",&a,&b);
    product(a,b);//Function calling
    return 0;
}

void product(int a,int b)//Function definition
{
   int p;
   p=a*b;
   printf("The product of two numbers: %d",p);
}
```

## Function retuning value and passing no arguments
```
#include<stdio.h>
int product();//Function prototype
int main()
{
    int c;
    c=product();//Function calling
    printf("The product of two numbers: %d",c);
    return 0;
}
int product()
{
 int a,b,p;
 printf("Enter two numbers: ");
 scanf("%d%d",&a,&b);
 p=a*b;
 return (p);
}
```

## Function returning no value and passing no arguments
```
#include<stdio.h>
void product();//function prototype
int main()
{
  product();//function calling
  return 0;
}

void product()
{
    int a,b,p;
    printf("Enter two numbers: ");
    scanf("%d%d",&a,&b);
    p=a*b;
    printf("The sum of two numbers: %d",p);
}
```