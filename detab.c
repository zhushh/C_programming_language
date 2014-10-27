/***********************************************************************
 *  > File Name: replace_tab_with_blanks.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Mon 11 Aug 2014 02:17:06 AM CST
***********************************************************************/

#include <stdio.h>

#define TABINC 8    /* tab increment size */

/* replace tabs with the proper number of blanks */
int main()
{
    int c, nb, pos;

    nb = 0;         /* number of blanks neccessary */
    pos = 1;        /* position of character in line */
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            nb = TABINC - (pos - 1) % TABINC;   /* '%' precedence is high than '-' */
            while (nb > 0) {
                putchar(' ');
                ++pos;
                --nb;
            }
        } else if (c == '\n') {
            putchar(c);
            pos = 1;
        } else {
            putchar(c);
            ++pos;
        }
    }
    return 0;
}
