#include <stdio.h>

// Recursive function to find the LCM
int findLCM(int a, int b, int currentMultiple) {
    // Base case: If currentMultiple is divisible by both a and b, it's the LCM
    if (currentMultiple % a == 0 && currentMultiple % b == 0) {
        return currentMultiple;
    } else {
        // Recursive step: Increment currentMultiple and call the function again
        return findLCM(a, b, currentMultiple + 1);
    }
}

int main() {
    int num1, num2, lcmResult;

    printf("Enter two positive integers: ");
    scanf("%d %d", &num1, &num2);

    // Ensure num1 is always smaller or equal to num2 for simpler logic in recursion
    // This is optional, but can make the initial currentMultiple choice more intuitive
    if (num1 > num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    // Start the recursion with the larger of the two numbers as the initial multiple
    lcmResult = findLCM(num1, num2, num2);

    printf("The LCM of %d and %d is %d.\n", num1, num2, lcmResult);

    return 0;
}
