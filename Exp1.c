#include <stdio.h>

void merge_sort(int *arr, int n);
void merge(int *arr, int n, int *left_arr, int *right_arr);

void merge_sort(int *arr, int n) {
    if (n <= 1) {
        return;
    }
    int mid = n/2, left_arr[mid], right_arr[n-mid], i, j = 0;
    for (i = 0;  i < n; i ++) {
        if (i < mid) {
            left_arr[i] = arr[i];
        } else {
            right_arr[j] = arr[i];
            j ++;
        }
    }
    merge_sort(left_arr, mid);
    merge_sort(right_arr, n-mid);
    merge(arr, n, left_arr, right_arr);
}

void merge(int *arr, int n, int *left_arr, int *right_arr) {
    int left_size = n/2, right_size = n-left_size, i = 0, l = 0, r = 0;
    while (l < left_size && r < right_size) {
        if (left_arr[l] < right_arr[r]) {
            arr[i] = left_arr[l];
            i ++;
            l ++;
        } else {
            arr[i] = right_arr[r];
            i ++;
            r ++;
        }
    }
    while (l < left_size) {
        arr[i] = left_arr[l];
        i ++;
        l ++;
    }
    while (r < right_size) {
        arr[i] = right_arr[r];
        i ++;
        r ++;
    }
}

void main() {
    int arr[] = {1, 5, 2, 4, 3}, n = sizeof(arr)/sizeof(int), i;
    for (i = 0; i < n; i ++) {
        printf("%d ", arr[i]);
    }
    merge_sort(arr, n);
    printf("\n");
    for (i = 0; i < n; i ++) {
        printf("%d ", arr[i]);
    }
}