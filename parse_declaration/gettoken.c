/***********************************************************************
 *  > File Name: gettoken.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Mon 11 Aug 2014 10:30:30 PM CST
***********************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUFSIZE 1000
enum { NAME, PARENS, BRACKETS };
extern int tokentype;
extern char token[];
extern char name[];

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("error: too much input!\n");
    else
        buf[bufp++] = c;
}

int gettoken(void)  /* return next token */
{
    int c, getch(void);
    void ungetch(int c);
    char *p = token;

    while ((c = getch()) == ' ' || c == '\t')
        ;
    if (c == '(') {
        if ((c = getch()) == ')') {
            strcpy(token, "()");
            return tokentype = PARENS;
        } else {
            ungetch(c);
            return tokentype = '(';
        }
    } else if (c == '[') {
        for (*p++ = c; (*p++ = getch()) != ']';)
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    } else if (isalpha(c)) {
        for (*p++ = c; isalnum(c = getch());)
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    } else
        return tokentype = c;
}

