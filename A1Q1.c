
#include <stdio.h>

int findMaximumInBitonicArray(int arr[], int n) {
    int low = 0, high = n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if ((mid == 0 || arr[mid - 1] < arr[mid]) && 
            (mid == n - 1 || arr[mid] > arr[mid + 1])) {
            return arr[mid];
        }
        
        if (mid > 0 && arr[mid - 1] < arr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return -1;
}

int main() {
    int n;
    
    printf("Enter the number of elements in the bitonic array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements of the bitonic array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int maxElement = findMaximumInBitonicArray(arr, n);
    printf("The maximum element in the bitonic array is: %d\n", maxElement);
    
    return 0;
}


