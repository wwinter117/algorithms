//
// Created by wwinter on 2024/6/24.
//
#include "../common/util.h"
#include "stdio.h"

void
insertsort(int arr[], int size) {
    if (size <= 1) {
        return;
    }
    insertsort(arr, size - 1);
    int last = arr[size - 1];
    for (int i = size - 1; i >= 0; --i) {
        if (arr[i - 1] > last) {
            arr[i] = arr[i - 1];
        } else {
            arr[i] = last;
            break;
        }
    }
}

void
insertsort_test() {
    int a1[9] = {1};
    int a2[9] = {1, 5, 2, 7, 8, 5, 3, 2, 7};
    printf("insert merge before:\n");
    printf("a1: ");
    print_array(a1, 1);
    printf("a2: ");
    print_array(a2, 9);

    insertsort(a1, 1);
    insertsort(a2, 9);

    printf("insert merge after:\n");
    printf("a1: ");
    print_array(a1, 1);
    printf("a2: ");
    print_array(a2, 9);
}