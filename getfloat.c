/***********************************************************************
 *  > File Name: getfloat.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Sun 10 Aug 2014 12:36:59 PM CST
***********************************************************************/

#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

/* getfloat: get next floating-point number from input */
int getfloat(float *pn) {
    int c, sign;
    float power;

    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' 
        && c != '-' && c != '.') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = *pn * 10.0 + (c - '0');
    if (c == '.')
        c = getch();
    for (power = 1.0; isdigit(c); c = getch()) {
        *pn = *pn * 10.0 + (c - '0');
        power *= 10.0;
    }
    *pn *= sign / power;
    if (c != EOF)
        ungetch(c);
    return c;
}
