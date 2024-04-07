#include <stdio.h>

// Recursive function to perform binary search
int binarySearch(int arr[], int left, int right, int target) {
    // Base case: if left index is greater than right index, element not found
    if (left > right) {
        return -1;
    }

    // Calculate mid index
    int mid = left + (right - left) / 2;

    // If target is found at mid, return mid
    if (arr[mid] == target) {
        return mid;
    }
    // If target is smaller than the middle element, then it's in left subarray
    else if (target < arr[mid]) {
        return binarySearch(arr, left, mid - 1, target); // Recursive call for left subarray
    }
    // If target is larger than the middle element, then it's in right subarray
    else {
        return binarySearch(arr, mid + 1, right, target); // Recursive call for right subarray
    }
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 12;

    // Perform binary search
    int index = binarySearch(arr, 0, n - 1, target);

    // Display the result
    if (index != -1) {
        printf("Element %d found at index %d\n", target, index);
    } else {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}
