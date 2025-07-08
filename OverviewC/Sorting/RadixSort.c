#include <stdio.h>

// Function prototypes
void radixSort(int [], int);
void countSort(int [], int, int);

int main() 
{
    int arr[] = {10, 21, 17, 34, 44, 11, 654, 123};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    radixSort(arr, n);

    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

void countSort(int arr[], int n, int place) 
{
    int output[n];
    int freq[10] = {0};  // Digits 0–9

    // Count frequency
    for (int i = 0; i < n; i++)
        freq[(arr[i] / place) % 10]++;

    // Cumulative count
    for (int i = 1; i < 10; i++)
        freq[i] += freq[i - 1];

    // Build output array
    for (int i = n - 1; i >= 0; i--) 
    {
        int digit = (arr[i] / place) % 10;
        output[freq[digit] - 1] = arr[i];
        freq[digit]--;
    }

    // Copy to original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) 
{
    // Find the maximum number to determine number of digits
    int maxx = arr[0];
    for (int i = 1; i < n; i++) 
    {
        if (arr[i] > maxx)
            maxx = arr[i];
    }

    // Apply counting sort for each digit (place: 1, 10, 100, ...)
    for (int place = 1; maxx / place > 0; place *= 10)
        countSort(arr, n, place);
}
