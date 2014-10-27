/***********************************************************************
 *  > File Name: remove_trail_white_and_blank_line.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Mon 11 Aug 2014 01:51:36 AM CST
***********************************************************************/

#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
int remove(char s[]);

/* remove trailing blanks and tabs, and delete blank lines */
int main()
{
    char line[MAXLINE];

    while (getline(line, MAXLINE) > 0) {
        if (remove(line) > 0)
            printf("%s", line);
    }
    return 0;
}
/* remove trailing blanks and tabs from character string s */
int remove(char s[])
{
    int i;

    i = 0;
    while (s[i] != '\n')    /* find newline character */
        ++i;
    --i;                    /* back off from '\n' */
    while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
        --i;
    if (i >= 0) {           /* is it a nonblank line? */
        ++i;
        s[i] = '\n';        /* puts newline character back */
        ++i;
        s[i] = '\0';        /* terminal the string */
    }
    return i;
}
int getline(char *s, int limit)
{
    int c;
    char *b = s;

    while (--limit > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - b;
}
