/***********************************************************************
 *  > File Name: print_non_graphic_character_with_octal.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Sun 17 Aug 2014 04:30:26 PM CST
***********************************************************************/

#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100 /* max number of chars in one line */
#define OCTLEN  6   /* length of an octal value */

/* print arbitrary input in a sensible way */
int main()
{
    int c, pos;
    int inc(int pos, int n);

    pos = 0;
    while ((c = getchar()) != EOF) {
        if (iscntrl(c) || c == ' ') {
            pos = inc(pos, OCTLEN);
            printf(" \\%03o ", c);
            if (c == '\n') {
                pos = 0;
                putchar('\n');
            }
        } else {
            pos = inc(pos, 1);
            putchar(c);
        }
    }
    return 0;
}

/* inc: increment position counter for output */
int inc(int pos, int n)
{
    if (pos + n < MAXLINE) {
        return pos+n;
    } else {
        putchar('\n');
        return n;
    }
}

