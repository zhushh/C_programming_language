/***********************************************************************
 *  > File Name: lower.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Sun 17 Aug 2014 04:04:29 PM CST
***********************************************************************/

#include <stdio.h>
#include <ctype.h>

int main()
{
    int c;

    while ((c = getchar()) != EOF) {
        putchar(tolower(c));
    }
    return 0;
}
