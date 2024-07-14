//
// Created by wwinter on 2024/6/28.
//
#include "stdio.h"

extern void mergesort(int a[], int p, int q);

int
sumeqx(int arr[], int size, int x) {
    mergesort(arr, 0, size - 1);
    int l = 0, r = size - 1;
    while (l < r) {
        int sum = arr[l] + arr[r];
        if (sum == x) {
            return 1;
        } else if (sum < x) {
            ++l;
        } else {
            --r;
        }
    }
    return 0;
}

// 测试函数
void sumeqx_test() {
    // 测试1：数组中有两个元素和为x
    int arr1[] = {1, 2, 4, 4};
    int result1 = sumeqx(arr1, 4, 8);
    printf("Test 1: Expected 1, Got %d\n", result1);

    // 测试2：数组中没有两个元素和为x
    int arr2[] = {1, 2, 3, 9};
    int result2 = sumeqx(arr2, 4, 8);
    printf("Test 2: Expected 0, Got %d\n", result2);

    // 测试3：数组中有多个对和为x
    int arr3[] = {1, 2, 3, 4, 5};
    int result3 = sumeqx(arr3, 5, 6);
    printf("Test 3: Expected 1, Got %d\n", result3);

    // 测试4：空数组
    int arr4[] = {};
    int result4 = sumeqx(arr4, 0, 6);
    printf("Test 4: Expected 0, Got %d\n", result4);

    // 测试5：数组中只有一个元素
    int arr5[] = {1};
    int result5 = sumeqx(arr5, 1, 1);
    printf("Test 5: Expected 0, Got %d\n", result5);
}



