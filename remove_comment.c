/***********************************************************************
 *  > File Name: remove_comment.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Mon 11 Aug 2014 11:56:46 AM CST
***********************************************************************/

#include <stdio.h>

void rcomment(int c);
void in_comment(void);
void echo_quote(int c);

/* remove all comments from a valid C program */
int main()
{
    int c;

    while ((c = getchar()) != EOF)
        rcomment(c);
    return 0;
}

/* rcomment: read each character, remove the  comments */
void rcomment(int c)
{
    int d;

    if (c == '/') {
        if ((d = getchar()) == '*') {
            in_comment();       /* beginninng comment */
        } else if (d == '/') {
            putchar(c);     /* another slash */
            rcomment(d);
        } else {
            putchar(c);     /* not a comment */
            putchar(d);
        }
    } else if (c == '\'' || c == '\"') {
        echo_quote(c);      /* quote begins */
    } else {
        putchar(c);         /* not a comment */
    }
}

/* in_comment: inside of a valid comment */
void in_comment(void)
{
    int c, d;

    c = getchar();                  /* prev character */
    d = getchar();                  /* curr character */
    while (c != '*' || d != '/') {  /* search for end */
        c = d;
        d = getchar();
    }
}

/* echo_quote: echo characters within quotes */
void echo_quote(int c)
{
    int d;

    putchar(c);
    while ((d = getchar()) != c) {  /* search for end */
        putchar(d);
        if (d == '\\')
            putchar(getchar());     /* ingnore escape seq */
    }
    putchar(d);
}

