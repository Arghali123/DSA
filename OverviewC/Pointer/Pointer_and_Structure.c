#include<stdio.h>
int main()
{
      
    struct Products
    {
        char name[30];
        int manufac;
        float net;
    }item[2],*ptr;

    for(ptr=item;ptr<item+2;ptr++)
    {
      printf("Enter product name: ");
      scanf(" %[^\n]",ptr->name);

      printf("Enter year of manufacture: ");
      scanf("%d",&ptr->manufac);

      printf("Ennter the net weight:");
      scanf("%f",&ptr->net);
    }
    for(ptr=item;ptr<item+2;ptr++)
    {
        printf("Name: %s,Manufacture: %d,net: %f\n",ptr->name,ptr->manufac,ptr->net);
    }
   return 0; 
}