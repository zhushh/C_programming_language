/***********************************************************************
 *  > File Name: qsort_with_opt_2.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Mon 11 Aug 2014 04:55:20 PM CST
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMERIC 1   /* numeric sort */
#define DECR    2   /* sort in decreasing order */
#define LINES 1000  /* max # of lines to be sorted */

int numcmp(char *, char *);
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines, int decr);
void qsort(void *v[], int left, int right,
            int (*comp)(void *, void *));
static char option = 0;

/* sort input lines */
int main(int argc, char *argv[])
{
    char *lineptr[LINES];   /* pointers to text lines */
    int nlines;
    int c, rc = 0;

    while (--argc > 0 && (*++argv)[0] == '-') {
        while (c = *++argv[0])
            switch (c) {
                case 'n':       /* numeric sort */
                    option |= NUMERIC;
                    break;
                case 'r':       /* sort in decreasing order */
                    option |= DECR;
                    break;
                default:
                    printf("sort: illegal option %c\n", c);
                    argc = 1;
                    rc = -1;
                    break;
            }
    }
    if (argc)
        printf("Usage: sort -nr \n");
    else
        if ((nlines = readlines(lineptr, LINES)) > 0) {
            if (option & NUMERIC)
                qsort((void **)lineptr, 0, nlines - 1,
                    (int (*)(void *, void *))numcmp);
            else
                qsort((void **)lineptr, 0, nlines - 1,
                    (int (*)(void *, void *))strcmp);
            writelines(lineptr, nlines, option & DECR);
        } else {
            printf("input too big to sort \n");
            rc = -1;
        }
    return rc;
}

#define MAXLEN 1000

int getline(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL) {
            return -1;
        } else {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}
/* getline: get line into s, return length */
int getline(char *s, int limit)
{
    int c;
    char *b = s;

    while (--limit > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - b;
}

#define BUFSIZE 10000
char buf[BUFSIZE];
char *bufp = buf;
/* alloc: allocate memory with length */
char *alloc(int len)
{
    if (buf + BUFSIZE - bufp >= len) {
        bufp += len;
        return bufp - len;
    } else {
        printf("error: memory lack! can't allocate room\n");
        return NULL;
    }
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines, int decr)
{
    int i;

    if (decr)       /* print in decreasing order */
        for (i = nlines - 1; i >= 0; --i)
            printf("%s\n", lineptr[i]);
    else            /* print in increasing order */
        for (i = 0; i < nlines; ++i)
            printf("%s\n", lineptr[i]);
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(void *v[], int left, int right,
            int (*comp)(void *, void *))
{
    void swap(void *v[], int i, int j);
    int last, i;

    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; ++i) {
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    }
    swap(v, last, left);
    qsort(v, left, last - 1, comp);
    qsort(v, last + 1, right, comp);
}
/* swap: swap v[i] and v[j] */
void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 > v2)
        return 1;
    else if (v1 < v2)
        return -1;
    else
        return 0;
}

