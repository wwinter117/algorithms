//
// Created by wwinter on 2024/7/24.
//

//
// 2.2-2 选择排序
//
void
selectionsort(int a[], int size) {
    int i, mi, temp;
    for (i = 0; i < size - 1; ++i) {
        mi = i;
        for (int j = i + 1; j < size; ++j) {
            if (a[j] < a[mi]) {
                mi = j;
            }
        }
        temp = a[i];
        a[i] = a[mi];
        a[mi] = temp;
    }
}