/***********************************************************************
 *  > File Name: cat_2.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Sun 17 Aug 2014 05:46:12 PM CST
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>

/* cat: concatenate files, version 2 */
int main(int argc, char *argv[])
{
    FILE *fp;
    void filecopy(FILE *, FILE *);
    char *prog = argv[0];   /* program name for error */

    if (argc == 1) {    /* not argument, copy standard input */
        filecopy(stdin, stdout);
    } else {
        while (--argc > 0) {
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                exit(1);
            } else {
                filecopy(fp, stdout);
                fclose(fp);
            }
        }
    }
    if (ferror(stdout)) {
        fprintf(stderr, "%s: wrong writing stdout\n", prog);
        exit(2);
    }
    exit(0);
}
/* filecopy: copy file ifp to file ofp */
void filecopy(FILE *ifp, FILE *ofp)
{
    int c;

    while ((c = getc(ifp)) != EOF) {
        putc(c, ofp);
    }
}

