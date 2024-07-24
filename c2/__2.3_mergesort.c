//
// Created by wwinter on 2024/7/24.
//

//
// p19: 归并排序
//
void merge(int a[], int p, int q, int r);

void
mergesort(int a[], int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergesort(a, l, mid);
        mergesort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
}

void merge(int a[], int p, int q, int r) {
    int n1 = q - p + 1, n2 = r - q;
    int la[n1], ra[n2];
    for (int i = 0; i < n1; ++i) {
        la[i] = a[p + i];
    }
    for (int i = 0; i < n2; ++i) {
        ra[i] = a[q + 1 + i];
    }
    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
        if (la[i] <= ra[j]) {
            a[k] = la[i];
            ++i;
        } else {
            a[k] = ra[j];
            ++j;
        }
        ++k;
    }
    while (i < n1) {
        a[k] = la[i];
        ++i;
        ++k;
    }
    while (j < n2) {
        a[k] = ra[j];
        ++j;
        ++k;
    }
}