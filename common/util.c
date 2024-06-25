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