//
// Created by wwinter on 2024/6/28.
//
#include "../common/util.h"


void
insertsort2(int arr[], int size) {
    if (size <= 1) {
        return;
    }
    for (int i = 1; i < size; ++i) {
        int value = arr[i];
        int index = i - 1;
        while (index >= 0 && arr[index] > value) {
            arr[index + 1] = arr[index];
            --index;
        }
        arr[index + 1] = value;
    }
}

void insertsort2_test() {
    int arr1[] = {};
    int expected1[] = {};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    insertsort2(arr1, size1);
    testArray(arr1, size1, "空数组排序结果", expected1, sizeof(expected1) / sizeof(expected1[0]));

    int arr2[] = {5};
    int expected2[] = {5};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    insertsort2(arr2, size2);
    testArray(arr2, size2, "只有一个元素的数组排序结果", expected2, sizeof(expected2) / sizeof(expected2[0]));

    int arr3[] = {1, 2, 3, 4, 5};
    int expected3[] = {1, 2, 3, 4, 5};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    insertsort2(arr3, size3);
    testArray(arr3, size3, "已经排序的数组排序结果", expected3, sizeof(expected3) / sizeof(expected3[0]));

    int arr4[] = {5, 4, 3, 2, 1};
    int expected4[] = {1, 2, 3, 4, 5};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    insertsort2(arr4, size4);
    testArray(arr4, size4, "倒序排序的数组排序结果", expected4, sizeof(expected4) / sizeof(expected4[0]));

    int arr5[] = {3, 1, 2, 3, 1};
    int expected5[] = {1, 1, 2, 3, 3};
    int size5 = sizeof(arr5) / sizeof(arr5[0]);
    insertsort2(arr5, size5);
    testArray(arr5, size5, "包含重复元素的数组排序结果", expected5, sizeof(expected5) / sizeof(expected5[0]));

    int arr6[] = {3, 5, 1, 4, 2};
    int expected6[] = {1, 2, 3, 4, 5};
    int size6 = sizeof(arr6) / sizeof(arr6[0]);
    insertsort2(arr6, size6);
    testArray(arr6, size6, "一般情况的数组排序结果", expected6, sizeof(expected6) / sizeof(expected6[0]));
}