//
// Created by wwinter on 2024/7/25.
//

//
// 2-2 冒泡排序
//
void
bubblesort(int a[], int size) {
    int temp;
    int flag = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = size - 1; j > i; ++j) {
            if (a[j - 1] > a[j]) {
                temp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = temp;
                flag = 1;
            }
        }
        if (!flag) {
            break;
        }
    }
}