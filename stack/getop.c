/***********************************************************************
 *  > File Name: getop.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Sat 09 Aug 2014 04:48:35 PM CST
***********************************************************************/

#ifndef GETOP_C
#define GETOP_C

#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char s[]) {
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';

    i = 0;
    if (!isdigit(c) && c != '.')
        return c;           /* not a number          */

    if (isdigit(c))         /* collect integer part  */
        while (isdigit(s[++i] = c = getch()));
    if (c == '.')           /* collect fraction part */
        while (isdigit(s[++i] = c = getch()));
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#endif
