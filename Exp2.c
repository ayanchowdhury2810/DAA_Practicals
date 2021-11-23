#include <stdio.h>

void insertion_sort(int *arr,int n);

void insertion_sort(int *arr,int n) {
    int i, j, temp;
    for (i = 1; i < n; i ++) {
        temp = arr[i];
        j = i-1;
        while (j >= 0) {
            if (arr[j] > temp) {
                arr[j+1] = arr[j];
            } else {
                break;
            }
            j --;
        }
        arr[j+1] = temp;
    }
}

void main() {
    int arr[] = {5, 4, 3, 2, 1}, n = sizeof(arr)/sizeof(int), i;
    for (i = 0; i < n; i ++) {
        printf("%d ", arr[i]);
    }
    insertion_sort(arr, n);
    printf("\n");
    for (i = 0; i < n; i ++) {
        printf("%d ", arr[i]);
    }
}