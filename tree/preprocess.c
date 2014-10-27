/***********************************************************************
 *  > File Name: preprocess.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Wed 13 Aug 2014 11:27:30 PM CST
***********************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "hash.h"

#define MAXWORD 100

void error(int, char *);
int getch(void);
void ungetch(int);
void ungets(char *);
void getdef(void);
int getword(char *, int);
void skipblanks(void);

int main() {
    char w[MAXWORD];
    struct nlist *p;

    while (getword(w, MAXWORD) != EOF) {
        if (strcmp(w, "#") == 0)    /* beginning of direct. */
            getdef();
        else if (!isalpha(w[0]))
            printf("%s", w);        /* cannot be defined */
        else if ((p = lookup(w)) == NULL)
            printf("%s", w);        /* not defined */
        else
            ungets(p->defn);        /* push definition */
    }
    return 0;
}

/* getdef: get definition and install it */
void getdef(void)
{
    int i;
    char def[MAXWORD], dir[MAXWORD], name[MAXWORD];

    skipblanks();
    if (!isalpha(getword(dir, MAXWORD))) {
        error(dir[0], "getdef: expecting a directive after #");
    } else if (strcmp(dir, "define") == 0) {
        skipblanks();
        if (!isalpha(getword(name, MAXWORD))) {
            error(name[0], "getdef: non-alph - name expected");
        } else {
            skipblanks();
            for (i = 0; i < MAXWORD - 1; i++) {
                if ((def[i] = getch()) == EOF || def[i] == '\n') {
                    break;      /* end of definition */
                }
            }
            def[i] = '\0';
            if (i <= 0) {       /* no definition */
                error('\n', "getdef: incomplete define");
            } else {            /* install definition */
                install(name, def);
            }
        }
    } else if (strcmp(dir, "undef") == 0) {
        skipblanks();
        if (!isalpha(getword(name, MAXWORD))) {
            error(name[0], "getdef: non-alph in undef");
        } else {
            undef(name);
        }
    } else if (strcmp(dir, "include") == 0) {
        printf("#%s", dir);     /* donot cope with the include file */
    } else {
        error(dir[0], "getdef: expecting a directive after #");
    }
}

/* error: print error message and skip the rest of the line */
void error(int c, char *s)
{
    printf("error: %s\n", s);
    while (c != EOF || c != '\n')
        c = getch();
}

/* skipblanks: skip blank and tab characters */
void skipblanks(void)
{
    int c;

    while ((c = getch()) == ' ' || c == '\t')
        putchar(c);
    ungetch(c);
}

/* getword: get next word or character from input */
int getword(char *word, int limit)
{
    int c, comment(void), getch(void);
    void ungetch(int);
    char *w = word;

    skipblanks();
    c = getch();
    if (c != EOF) {
        *w++ = c;
    }
    if (isalpha(c) || c == '_') {
        for (; --limit > 0; ++w) {
            if (!isalnum(*w = getch()) && *w != '_') {
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
            *--w = comment();
            w++;
        } else {
            ungetch(c);
        }
    }
    *w = '\0';
    return c;
}

/* ungets: push back string s into buf */
void ungets(char *s)
{
    int len = strlen(s);

    while (len > 0)
        ungetch(s[--len]);
}

#define BUFSIZE 10000

static char buf[BUFSIZE];
static int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("error: Input too much character\n");
    else
        buf[bufp++] = c;
}
/* comment: skip over the comment */
int comment(void)
{
    int c;

    while ((c = getch()) != EOF) {
        if (c == '*') {
            if ((c = getch()) == '/')
                break;
        }
    }
    if (c != EOF)
        c = getch();
    return c;
}

