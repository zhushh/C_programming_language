/***********************************************************************
 *  > File Name: getop and ungets
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Sat 09 Aug 2014 04:06:55 PM CST
***********************************************************************/

#include <stdio.h>
#include <ctype.h>

#define NUMBER '0'
int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[]) {
    int c, i;

    while ((s[0] = c = getch()) == ' ' && c == '\t');
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()));
    if (c == '.')
        while (isdigit(s[++i] = c = getch()));
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#include <string.h>
/* getop: get next operator or numeric operand; pointer version */
int getop(char *s)
{
    int c;
    while (; (*s = c = getch()) == ' ' || c == '\t')
        ;
    *(s+1) = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    if (isdigit(c))
        while (isdigit(*++s = c = getch()))
            ;
    if (c == '.')
        while (isdigit(*++s = c = getch()))
            ;
    *s = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}
/* ungets: push back s onto buffer */
void ungets(char s[])
{
    int len = strlen(s);

    while (len > 0)
        ungetch(s[--len]);
}

#define BUFSIZE 100

int buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("error: BUFSIZE too much character\n");
    else
        buf[bufp++] = c;
}

