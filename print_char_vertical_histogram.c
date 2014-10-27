/***********************************************************************
 *  > File Name: print_char_vertical_histogram.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Mon 11 Aug 2014 12:38:12 AM CST
***********************************************************************/

#include <stdio.h>

#define MAXHIST 15      /* max length of histogram */
#define MAXWORD 11      /* max length of a word */
#define IN 1            /* inside a word */
#define OUT 0           /* outside a word */

/* print vertical histogram */
int main()
{
    int c, i, j, nc, state;
    int maxvalue;
    int ovflow;
    int wl[MAXWORD];
    state = OUT;
    nc = 0;
    ovflow = 0;
    for (i = 0; i < MAXWORD; ++i)
        wl[i] = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            if (nc > 0) {
                if (nc < MAXWORD)
                    ++wl[nc];
                else
                    ++ovflow;
            }
            nc = 0;
        } else if (state == OUT) {
            state = IN;
            nc = 1;
        } else {
            ++nc;
        }
    }
    maxvalue = 0;
    for (i = 0; i < MAXWORD; ++i)
        if (maxvalue < wl[i])
            maxvalue = wl[i];

    for (i = MAXHIST; i > 0; --i) {
        printf("             ");
        for (j = 1; j < MAXWORD; ++j)
            if (wl[j] *MAXHIST / maxvalue >= i)
                printf("   *");
            else
                printf("    ");
        putchar('\n');
    }
    for (i = 1; i < MAXWORD * 8; ++i)
        putchar('-');
    printf("\nword length: ");
    for (i = 1; i < MAXWORD; ++i)
        printf("%4d", i);
    putchar('\n');
    printf("word number: ");
    for (i = 1; i < MAXWORD; ++i)
        printf("%4d", wl[i]);
    putchar('\n');
    if (ovflow > 0)
        printf("There is/are %d word(s) >= %d\n", ovflow, MAXWORD);
    return 0;
}

