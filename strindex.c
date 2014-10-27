/***********************************************************************
 *  > File Name: strindex.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Fri 08 Aug 2014 07:28:10 PM CST
***********************************************************************/

#include <stdio.h>

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[]) {
    int i, j, k;

    for (i = 0; s[i] != '\0'; ++i) {
        for (j = 0, k = i; t[j] != '\0' && t[j] = s[k];) {
            ++j;
            ++k;
        }
        if (j > 0 && t[j] == '\0')
            return i;
    }
    return -1;
}
/* strindex: return index of t in s, -1 if none */
int strindex(char *s, char *t)
{
    char *b = s;
    char *p, *r;

    for (; *s != '\0'; s++) {
        for (p = s, r = t; *r != '\0' && *p == *r; p++, r++)
            ;
        if (r > t && *r == '\0')
            return s - b;
    }
    return -1;
}

