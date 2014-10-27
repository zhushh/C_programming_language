/***********************************************************************
 *  > File Name: reverse_output_line.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Mon 11 Aug 2014 02:03:30 AM CST
***********************************************************************/

#include <stdio.h>
#define MAXLINE 1000

int getline(char s[], int maxline);
void reverse(char s[]);

/* reverse input lines, a line at a time */
int main()
{
    char line[MAXLINE];

    while (getline(line, MAXLINE) > 0) {
        reverse(line);
        printf("%s", line);
    }
    return 0;
}

/* getline: get line into s, and return the length */
int getline(char s[], int limit) {
    int i, c;

    i = 0;
    while (--limit > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = '\n';
    s[i] = '\0';
    return i;
}
/* reverse: reverse string s in place */
void reverse(char s[])
{
    int i, j;
    char c;
    
    i = 0;
    while (s[i] != '\0')    /* find the end of string */
        ++i;
    --i;
    if (s[i] == '\n')   /* leave newline in place */
        --i;
    for (j = 0; j < i; ++j, --i) {
        c = s[j];
        s[j] = s[i];
        s[i] = c;
    }
}

