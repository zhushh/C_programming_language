#include <stdio.h>
#include <stdlib.h>

// decreasing sort array
void bubble_sort(int a[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = n - 1; j > i; j--) {
            if (a[j] < a[j - 1]) {   // swap element
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
    }
}

int main(void) {
    int i, n;
    scanf("%d", &n);
    int* a = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    bubble_sort(a, n);
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    free(a);
    return 0;
}
