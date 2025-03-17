#include <stdio.h>
#include <stdlib.h>

int mergeAndCount(int arr[], int temp[], int left, int right) {
    int invCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        invCount += mergeAndCount(arr, temp, left, mid);
        invCount += mergeAndCount(arr, temp, mid + 1, right);

        int i = left, j = mid + 1, k = left;

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                invCount += (mid - i + 1);  
            }
        }

        while (i <= mid) {
            temp[k++] = arr[i++];
        }

        while (j <= right) {
            temp[k++] = arr[j++];
        }

        for (i = left; i <= right; i++) {
            arr[i] = temp[i];
        }
    }
    return invCount;
}

int countInversions(int arr[], int n) {
    int temp[n];
    return mergeAndCount(arr, temp, 0, n - 1);
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = countInversions(arr, n);

    printf("Number of inversions: %d\n", result);

    return 0;
}
