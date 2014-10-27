/***********************************************************************
 *  > File Name: count_blank_tab_and_newline.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Sun 10 Aug 2014 11:37:03 PM CST
***********************************************************************/

#include <stdio.h>

int main()
{
    int c, nb, nt, nl;

    nb = nt = nl = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++nb;
        if (c == '\t')
            ++nt;
        if (c == '\n')
            ++nl;
    }
    printf("blank = %d, tab = %d, newline = %d\n", nb, nt, nl);
    return 0;
}
