/***********************************************************************
 *  > File Name: 1_10.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Sun 10 Aug 2014 11:45:04 PM CST
***********************************************************************/

#include <stdio.h>

/* replace tabs and backsapces with visible characters */
int main()
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t')
            printf("\\t");
        else if (c == '\b')
            printf("\\b");
        else if (c == '\\')
            printf("\\\\");
        else
            putchar(c);
    }
    return 0;
}
