/***********************************************************************
 *  > File Name: count_line.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Sun 10 Aug 2014 11:30:50 PM CST
***********************************************************************/

#include <stdio.h>

int main()
{
    long nc;
    char c;

    for (nc = 0;(c = getchar()) != EOF;)
        if (c == '\n')
            ++nc;
    printf("total lines: %ld\n", nc);
    return 0;
}
