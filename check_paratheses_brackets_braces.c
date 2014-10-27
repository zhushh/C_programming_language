/***********************************************************************
 *  > File Name: check_paratheses_brackets_braces.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Mon 11 Aug 2014 12:14:01 PM CST
***********************************************************************/

#include <stdio.h>

int brace, brack, paren;

void in_quote(int c);
void in_comment(void);
void search(int c);

/* rudimentary syntax checker for C program */
int main()
{
    int c;
    extern int brace, brack, paren;

    while ((c = getchar()) != EOF) {
        if (c == '/') {
            if ((c = getchar()) == '*')
                in_comment();
            else
                search(c);
        } else if (c == '\'' || c == '"')
            in_quote(c);
        else
            search(c);

        if (brace < 0) {
            printf("Unbalanced braces\n");
            brace = 0;
        } else if (brack < 0) {
            printf("Unbalanced brackets\n");
            brack = 0;
        } else if (paren < 0) {
            printf("Unbalanced parentheses\n");
            paren = 0;
        }
    }
    if (brace > 0)
        printf("Unbalanced braces\n");
    if (brack > 0)
        printf("Unbalanced brackets\n");
    if (paren > 0)
        printf("Unbalanced parentheses\n");
    return 0;
}

/* search: searchh forrudimentary syntax error */
void search(int c)
{
    extern int brace, brack, paren;

    if (c == '{')
        ++brace;
    else if (c == '}')
        --brace;
    else if (c == '[')
        ++brack;
    else if (c == ']')
        --brack;
    else if (c == '(')
        ++paren;
    else if (c == ')')
        --paren;
}

/* in_comment: inside of a valid comment */
void in_comment(void)
{
    int c, d;

    c = getchar();
    d = getchar();
    while (c != '*' || d != '/') {
        c = d;
        d = getchar();
    }
}

/* in_quote: inside quote */
void in_quote(int c)
{
    int d;

    while ((d = getchar()) != c)
        if (d == '\\')
            getchar();
}

