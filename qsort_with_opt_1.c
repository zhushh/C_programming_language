/***********************************************************************
 *  > File Name: qsort_generic.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Mon 11 Aug 2014 03:44:38 PM CST
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAXLINES    5000    /* max #lines to be sorted */
char *lineptr[MAXLINES];    /* pointer to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(void *lineptr[], int left, int right, 
            int (*comp)(void *, void *));
int numcmp(char *, char *);
int strcmp(char *, char *);
void strcpy(char *, char *);

/* sort input lines */
int main(int argc, char *argv[])
{
    int nlines;         /* number of input lines read */
    int numeric = 0;    /* 1 if numeric sort */
    char opt[] = "-n";
    
    if (argc > 1 && strcmp(argv[1], opt) == 0)
        numeric = 1;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort((void**)lineptr, 0, nlines - 1,
            (int (*)(void *, void *))(numeric ? numcmp : strcmp));
        writelines(lineptr, nlines);    
        return 0;
    } else {
        printf("input too big to be sorted\n");
        return 1;
    }
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
void writelines(char *lineptr[], int nlines)
{
    while (nlines > 0)
        printf("%s\n", lineptr[--nlines]);
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
/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int strcmp(char *s, char *t)
{
    for (; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}
/* strcpy: copy t to s */
void strcpy(char *s, char *t)
{
    while (*s++ = *t++)
        ;
}

