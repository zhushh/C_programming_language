/***********************************************************************
 *  > File Name: 1_9.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Sun 10 Aug 2014 11:41:07 PM CST
***********************************************************************/

#include <stdlib.h>
#include <stdio.h>

#define NONBLANK 'a'
/* replace string of blanks with a single blank */
int main()
{
    int c, lastc;

    lastc = NONBLANK;
    while ((c = getchar()) != EOF) {
        if (c != ' ')
            putchar(c);
        else
            if (lastc != ' ')
                putchar(c);
        lastc = c;
    }
    return 0;
}
