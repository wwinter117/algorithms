//
// Created by wwinter on 2024/6/28.
//
#include "stdio.h"

int
bisearch(int arr[], int l, int r, int key) {
    int index = -1;
    int mid = (l + r) / 2;
    while (l <= r) {
        int midv = arr[mid];
        if (midv == key) {
            index = mid;
            break;
        } else if (midv > key) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
        mid = (l + r) / 2;
    }
    return index;
}

int
bisearch2(int arr[], int l, int r, int key) {
    if (l > r) {
        return -1;
    }
    int mid = (l + r) / 2;
    if (arr[mid] == key) {
        return mid;
    }
    if (arr[mid] > key) {
        return bisearch2(arr, l, mid - 1, key);
    }
    return bisearch2(arr, mid + 1, r, key);
}

void
bisearch_test() {
    // 测试1：空数组
    int arr1[] = {};
    printf("Test 1: %d\n", bisearch(arr1, 0, 0, 5) == -1);
    printf("Test 1: %d\n", bisearch2(arr1, 0, 0, 5) == -1);

    // 测试2：数组中只有一个元素且该元素是目标值
    int arr2[] = {5};
    printf("Test 2: %d\n", bisearch(arr2, 0, 0, 5) == 0);
    printf("Test 2: %d\n", bisearch2(arr2, 0, 0, 5) == 0);

    // 测试3：数组中只有一个元素且该元素不是目标值
    int arr3[] = {1};
    printf("Test 3: %d\n", bisearch(arr3, 0, 0, 5) == -1);
    printf("Test 3: %d\n", bisearch2(arr3, 0, 0, 5) == -1);

    // 测试4：目标值在数组的开头
    int arr4[] = {1, 2, 3, 4, 5};
    printf("Test 4: %d\n", bisearch(arr4, 0, 4, 1) == 0);
    printf("Test 4: %d\n", bisearch2(arr4, 0, 4, 1) == 0);

    // 测试5：目标值在数组的结尾
    int arr5[] = {1, 2, 3, 4, 5};
    printf("Test 5: %d\n", bisearch(arr5, 0, 4, 5) == 4);
    printf("Test 5: %d\n", bisearch2(arr5, 0, 4, 5) == 4);

    // 测试6：目标值在数组的中间
    int arr6[] = {1, 2, 3, 4, 5};
    printf("Test 6: %d\n", bisearch(arr6, 0, 4, 3) == 2);
    printf("Test 6: %d\n", bisearch2(arr6, 0, 4, 3) == 2);

    // 测试7：目标值不在数组中
    int arr7[] = {1, 2, 3, 4, 5};
    printf("Test 7: %d\n", bisearch(arr7, 0, 4, 6) == -1);
    printf("Test 7: %d\n", bisearch2(arr7, 0, 4, 6) == -1);

}