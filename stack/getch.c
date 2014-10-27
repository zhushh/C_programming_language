/***********************************************************************
 *  > File Name: getch.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Sat 09 Aug 2014 04:53:08 PM CST
***********************************************************************/

#ifndef GETCH_C
#define GETCH_C

#include <stdio.h>
#define BUFSIZE 100

static char buf[BUFSIZE];
static int bufp;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many character\n");
    else
        buf[bufp++] = c;
}

#endif
