#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];  
    int i = low - 1;  

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;  
            swap(&arr[i], &arr[j]);  
        }
    }
    swap(&arr[i + 1], &arr[high]);  
    return i + 1;  
}

int quickselect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pi = partition(arr, low, high);  

        if (pi == k) {
            return arr[pi];
        }
        else if (pi > k) {
            return quickselect(arr, low, pi - 1, k);
        }
        else {
            return quickselect(arr, pi + 1, high, k);
        }
    }
    return -1;  
}

int main() {
    int n, k;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of k (to find the kth smallest element): ");
    scanf("%d", &k);

    if (k < 1 || k > n) {
        printf("Invalid value of k.\n");
        return 1;  
    }

    int kth_smallest = quickselect(arr, 0, n - 1, k - 1);

    printf("The %dth smallest element is %d\n", k, kth_smallest);

    return 0;
}
