/***********************************************************************
 *  > File Name: print_line_longer_than_LONGLINE.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Mon 11 Aug 2014 01:33:31 AM CST
***********************************************************************/

#include <stdio.h>
#define MAXLINE 1000
#define LONGLINE 80

int getline(char s[], int max);

int main()
{
    int len;
    char line[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0) {
        if (len > LONGLINE)
            printf("%s", line);
    }
    return 0;
}
int getline(char s[], int limit)
{
    int c, i;
    
    i = 0;
    while (--limit > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}
