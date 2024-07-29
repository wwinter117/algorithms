//
// Created by wwinter on 2024/6/24.
//

//
//  -p10 循环不变式：
// 每次循环开始时，前i个元素由原来数组中元素组成，并且已经排序
// 证明循环不变式：初始化、保持、终止
//
void insert_sort(int *a, int size) {
    for (int i = 1; i < size; ++i) {
        int value = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > value) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = value;
    }
}

//
// 2.1-3 线性查找
// 循环不变式：每次循环开始时，对于所有下标k，0 <= k < size，有arr[k] != v
//
int
linersearch(int arr[], int size, int v) {
    int i;
    for (i = 0; i < size; ++i) {
        if (arr[i] == v) {
            return i;
        }
    }
    return -1;
}

//
// 递归版本的插入排序
//
void
insertsort2(int arr[], int size) {
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
