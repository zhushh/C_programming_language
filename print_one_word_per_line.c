/***********************************************************************
 *  > File Name: print_one_word_per_line.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Mon 11 Aug 2014 12:01:41 AM CST
***********************************************************************/

#include <stdio.h>

#define IN 1        /* inside a word */
#define OUT 0       /* outside a word */

/* print input one word per line */
int main()
{
    int c, state;

    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                putchar('\n');      /* finish the word */
                state = OUT;
            }
        } else if (state == OUT) {
            state = IN;     /* beginning of word */
            putchar(c);
        } else {            /* inside a word */
            putchar(c);
        }
    }
}
