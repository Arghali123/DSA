#include <stdio.h>

// Recursive function to find the maximum element
int findMaxRecursive(int arr[], int n) {
    // Base case: If only one element is left, it is the maximum
    if (n == 1) {
        return arr[0];
    }

    // Find the maximum in the rest of the array (excluding the last element)
    int maxOfRest = findMaxRecursive(arr, n - 1);

    // Compare the last element with the maximum of the rest of the array
    // and return the larger one
    return (arr[n - 1] > maxOfRest) ? arr[n - 1] : maxOfRest;
}

int main() {
    int arr[] = {10, 324, 45, 90, 12};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements

    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int maxElement = findMaxRecursive(arr, n);
    printf("The maximum element in the array is: %d\n", maxElement);

    return 0;
}