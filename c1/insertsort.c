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
    int i = size - 1;
    while (i > 0 && arr[i - 1] > last) {
        arr[i] = arr[i - 1];
        --i;
    }
    arr[i] = last;
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

// 辅助函数：初始化和测试数组
void testArray(int arr[], int size, const char *description, int expected[], int expected_size) {
    printf("%s: ", description);
    insertsort(arr, size);
    print_array(arr, size);
    if (compare_arrays(arr, size, expected, expected_size)) {
        printf("OK\n");
    } else {
        printf("FAILED!\n");
    }
}

void insertsort_test() {
    // 测试各种数组情况
    int arr1[] = {};
    int expected1[] = {};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    testArray(arr1, size1, "空数组排序结果", expected1, sizeof(expected1) / sizeof(expected1[0]));

    int arr2[] = {5};
    int expected2[] = {5};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    testArray(arr2, size2, "只有一个元素的数组排序结果", expected2, sizeof(expected2) / sizeof(expected2[0]));

    int arr3[] = {1, 2, 3, 4, 5};
    int expected3[] = {1, 2, 3, 4, 5};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    testArray(arr3, size3, "已经排序的数组排序结果", expected3, sizeof(expected3) / sizeof(expected3[0]));

    int arr4[] = {5, 4, 3, 2, 1};
    int expected4[] = {1, 2, 3, 4, 5};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    testArray(arr4, size4, "倒序排序的数组排序结果", expected4, sizeof(expected4) / sizeof(expected4[0]));

    int arr5[] = {3, 1, 2, 3, 1};
    int expected5[] = {1, 1, 2, 3, 3};
    int size5 = sizeof(arr5) / sizeof(arr5[0]);
    testArray(arr5, size5, "包含重复元素的数组排序结果", expected5, sizeof(expected5) / sizeof(expected5[0]));

    int arr6[] = {3, 5, 1, 4, 2};
    int expected6[] = {1, 2, 3, 4, 5};
    int size6 = sizeof(arr6) / sizeof(arr6[0]);
    testArray(arr6, size6, "一般情况的数组排序结果", expected6, sizeof(expected6) / sizeof(expected6[0]));
}
