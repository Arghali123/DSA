#include<stdio.h>
#include<time.h>

int *getRandom()
{
    static int r[10];  // Static array to hold random numbers
    int i;
    srand((unsigned)time(NULL));  // Seed random number generator
    for(i = 0; i < 10; i++)
    {
        r[i] = rand();           // Store random number
        printf("%d\t", r[i]);    // Print it immediately
    }
    printf("\n");
    return r;  // Return pointer to static array
}

int main()
{
    int *p;
    int i;
    p = getRandom();  // Get pointer to array of random numbers
    for(i = 0; i < 10; i++)
    {
        printf("*(p+[%d]): %d\n", i, *(p + i));  // Print values using pointer
    }
    return 0;
}
