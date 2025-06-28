//We can also use an array of pointers to character to store a list of strings as follows:

#include<stdio.h>
const int MAX=4;
int main()
{
 char *name[]={
    "Daenish",
    "Aman",
    "Niraj",
    "Dipak"
 };
 for(int i=0;i<MAX;i++)
 {
   printf("Value of names[%d]= %s\n",i,name[i]);
 }
 return 0;
}