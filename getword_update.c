/***********************************************************************
 *  > File Name: getword_update.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Wed 13 Aug 2014 05:18:43 PM CST
***********************************************************************/

#include <stdio.h>
#include <ctype.h>

/* getword: get next word or character from input */
int getword(char *word, int limit)
{
    int c, d, comment(void), getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (isalpha(c) || c == '_' || c == '#') {
        for (; --limit > 0; w++) {
            if (!alnum(*w = getch()) && *w != '_') {
                ungetch(*w);
                break;
            }
        }
    } else if (c == '\'' || c == '"') {
        for (; --limit > 0; w++) {
            if ((*w = getch()) == '\\') {
                *++w = getch();
            } else if (*w == c) {
                w++;
                break;
            } else if (*w == EOF) {
                break;
            }
        }
    } else if (c == '/') {
        if ((c = getch()) == '*') {
            c = comment();
        } else {
            ungetch(c);
        }
    }
    *w = '\0';
    return c;
}

#define BUFSIZE 1000

static char buf[BUFSIZE];
static int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("error: too much input\n");
    else
        buf[bufp++] = c;
}

/* comment: skip over comment and return a character */
int comment(void)
{
    int c;

    while ((c = getch()) != EOF) {
        if (c == '*') {
            if ((c = getch()) == '/') {
                break;
            } else {
                ungetch(c);
            }
        }
    }
    return c;
}

