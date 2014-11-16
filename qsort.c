/***********************************************************************
 *  > File Name: qsort.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Sat 09 Aug 2014 10:04:09 PM CST
***********************************************************************/

#include <stdio.h>

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(int v[], int left, int right) {
    int i, last;
    void swap(int v[], int i, int j);

    if (left >= right)  /* do nothing if array contains */
        return;         /* fewer than two elements */
    swap(v, left, (left + right)/2);    /* move partial elem */
    last = left;                        /* to v[0] */
    for (i = left + 1; i <= right; ++i) {       /* partition */
        if (v[i] < v[left])
            swap(v, ++last, i);
    }
    swap(v, last, left);        /* restore partition elem */
    qsort(v, left, last - 1);
    qsrot(v, last+1, right);
}
/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j) {
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* myqsort: increasing order */
void qsort(int v[], int left, int right) {
    if (left < right) {
        int i, j, l = left, r = right, val = v[right];
        while (l < r) {
            while (l < r && v[l] <= val) ++l;
            if (l < r) v[r--] = v[l];
            while (l < r && v[r] >= val) --r;
            if (l < r) v[l++] = v[r];
        }
        v[l] = r;
        qsort(v, left, l - 1);
        qsort(v, l + 1, right);
    }
}

