//
// Created by wwinter on 2024/6/24.
//
#include <stdio.h>

void print_array(int a[], int size) {
    printf("{ ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", a[i]);
    }
    printf("}\n");
}


// 比较两个数组是否相等
int compare_arrays(int arr1[], int size1, int arr2[], int size2) {
    if (size1 != size2) {
        return 0; // false
    }
    for (int i = 0; i < size1; i++) {
        if (arr1[i] != arr2[i]) {
            return 0; // false
        }
    }
    return 1; // true
}

void testArray(int arr[], int size, const char *description, int expected[], int expected_size) {
    printf("%s: ", description);
    print_array(arr, size);
    if (compare_arrays(arr, size, expected, expected_size)) {
        printf("OK\n");
    } else {
        printf("FAILED!\n");
    }
}