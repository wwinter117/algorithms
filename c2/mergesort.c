//
// Created by wwinter on 2024/6/24.
//
#include "../common/util.h"

void
merge(int a[], int p, int mid, int q) {
    int llenth = mid - p + 1, rlenth = q - mid;
    int l[llenth], r[rlenth];
    for (int j = 0; j < llenth; ++j) {
        l[j] = a[p + j];
    }
    for (int j = 0; j < rlenth; ++j) {
        r[j] = a[mid + 1 + j];
    }

    int j = p, x = 0, y = 0;
    for (; j <= q; ++j) {
        if (x == llenth || y == rlenth) {
            break;
        }
        if (l[x] < r[y]) {
            a[j] = l[x];
            ++x;
        } else {
            a[j] = r[y];
            ++y;
        }
    }
    if (x == llenth) {
        while (j <= q) {
            a[j] = r[y];
            ++j;
            ++y;
        }
    }
    if (y == rlenth) {
        while (j <= q) {
            a[j] = l[x];
            ++j;
            ++x;
        }
    }
}

void
mergesort(int a[], int p, int q) {
    if (p < q) {
        int mid = (p + q) / 2;
        mergesort(a, p, mid);
        mergesort(a, mid + 1, q);
        merge(a, p, mid, q);
    }
}

void mergesort_test() {
    // 测试各种数组情况
    int arr1[] = {};
    int expected1[] = {};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    mergesort(arr1, 0, size1 - 1);
    testArray(arr1, size1, "空数组排序结果", expected1, sizeof(expected1) / sizeof(expected1[0]));

    int arr2[] = {5};
    int expected2[] = {5};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    mergesort(arr2, 0, size2 - 1);
    testArray(arr2, size2, "只有一个元素的数组排序结果", expected2, sizeof(expected2) / sizeof(expected2[0]));

    int arr3[] = {1, 2, 3, 4, 5};
    int expected3[] = {1, 2, 3, 4, 5};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    mergesort(arr3, 0, size3 - 1);
    testArray(arr3, size3, "已经排序的数组排序结果", expected3, sizeof(expected3) / sizeof(expected3[0]));

    int arr4[] = {5, 4, 3, 2, 1};
    int expected4[] = {1, 2, 3, 4, 5};
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    mergesort(arr4, 0, size4 - 1);
    testArray(arr4, size4, "倒序排序的数组排序结果", expected4, sizeof(expected4) / sizeof(expected4[0]));

    int arr5[] = {3, 1, 2, 3, 1};
    int expected5[] = {1, 1, 2, 3, 3};
    int size5 = sizeof(arr5) / sizeof(arr5[0]);
    mergesort(arr5, 0, size5 - 1);
    testArray(arr5, size5, "包含重复元素的数组排序结果", expected5, sizeof(expected5) / sizeof(expected5[0]));

    int arr6[] = {3, 5, 1, 4, 2};
    int expected6[] = {1, 2, 3, 4, 5};
    int size6 = sizeof(arr6) / sizeof(arr6[0]);
    mergesort(arr6, 0, size6 - 1);
    testArray(arr6, size6, "一般情况的数组排序结果", expected6, sizeof(expected6) / sizeof(expected6[0]));
}
