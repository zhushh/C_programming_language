/***********************************************************************
 *  > File Name: count_char_in_input.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Sun 10 Aug 2014 11:28:24 PM CST
***********************************************************************/

#include <stdio.h>

int main()
{
    long nc;

    nc = 0;
    while (getchar() != EOF)
        ++nc;
    printf("total input character: %ld\n", nc);
    return 0;
}
