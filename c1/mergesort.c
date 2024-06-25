//
// Created by wwinter on 2024/6/24.
//
#include "../common/util.h"
#include "stdio.h"

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

void
mergesort_test() {
    int a1[9] = {1};
    int a2[9] = {1, 5, 2, 7, 8, 5, 3, 2, 7};
    printf("merge before:\n");
    printf("a1: ");
    print_array(a1, 1);
    printf("a2: ");
    print_array(a2, 9);

    mergesort(a1, 0, 0);
    mergesort(a2, 0, 8);

    printf("merge after:\n");
    printf("a1: ");
    print_array(a1, 1);
    printf("a2: ");
    print_array(a2, 9);
}