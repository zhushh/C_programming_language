/***********************************************************************
 *  > File Name: getin.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Sun 10 Aug 2014 12:17:01 PM CST
***********************************************************************/

#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

/* getin: get next integer from input into *pn */
int getin(int *pn) {
    int c, d, sign;

    while (isspace(c = getch))      /* skip wihte space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);                 /* it's not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        d = c;                      /* remember sign char */
        if (!isdigit(c = getch())) {
            if (c != EOF)
                ungetch(c);         /* push back not digit */
            ungetch(d);             /* push back sign char */
            return d;               /* return sign char */
        }
    }
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = *pn * 10 + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

#define BUFSIZE 100

int buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("error: too much character\n");
    else
        buf[bufp++] = c;
}

