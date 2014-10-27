/***********************************************************************
 *  > File Name: getline.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Fri 08 Aug 2014 07:22:38 PM CST
***********************************************************************/

#include <stdio.h>

/* getline: get line into s, and return the length */
int getline(char s[], int limit) {
    int i, c;

    i = 0;
    while (--limit > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = '\n';
    s[i] = '\0';
    return i;
}

/* getline: get line into s, return the length; pointer version */
int getline(char *s, int limit)
{
    int c;
    char *t = s;

    while (--limit > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - t;
}

