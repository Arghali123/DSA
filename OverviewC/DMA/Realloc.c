#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NULL 0
int main()
{
    char *buff;
    if((buff=(char *)malloc(10)) == NULL)
    {
      printf("Malloc Failed!!");
      exit(1);
    }

    strcpy(buff,"kathmandu");
    printf("Buffer contains: %s\n",buff);


    if((buff=(char *)realloc(buff,15))==NULL)
    {
        printf("Realloc failed");
        exit(1);
    }

    printf("Buffer size modified");
    printf("Buffer still contains: %s\n",buff);
    strcpy(buff,"hastinapur");
    printf("Buffer now contains: %s\n",buff);
    free(buff);
    return 0;
}