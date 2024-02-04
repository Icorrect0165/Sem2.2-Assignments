#include <stdio.h>

// Function to calculate the sum of elements in an array
int summation(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }
    return sum;
}

// Function to find the maximum element in an array
int maximum(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int n;

    // Input the size of the array
    printf("Enter the size of the array (n): ");
    scanf("%d", &n);

    // Declare an array of length n
    int arr[n];

    // Input array elements from the user
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    // Call summation and maximum functions
    int sum_result = summation(arr, n);
    int max_result = maximum(arr, n);

    // Display the outputs
    printf("Sum of elements: %d\n", sum_result);
    printf("Maximum element: %d\n", max_result);

    return 0;
}
