#include "c2/algorithm_c1.h"
#include "stdio.h"

int main() {
    printf("Start Running: ...\n");
#ifdef C2_2_3_2
    mergesort_test();
#elif defined(C2_2_3_4)
    insertsort_test();
#elif defined(C2_2_3_5)
    bisearch_test();
#elif defined(C2_2_3_6)
    insertsort2_test();
#elif defined(C2_2_3_7)
    sumeqx_test();
#else
    printf("No function specified.\n");
#endif
    printf("End\n");
    return 0;
}
