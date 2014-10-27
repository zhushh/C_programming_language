/***********************************************************************
 *  > File Name: print_a_set_of_files.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Sun 17 Aug 2014 08:33:26 PM CST
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAXBOT  3   /* maximum # lines at bottom page */
#define MAXHDR  5   /* maximum # lines at head of page */
#define MAXLINE 100 /* maximum size of one line */
#define MAXPAGE 6   /* maximum # lines on one page */

/* print: print files - each new one on a new page */
int main(int argc, char *argv[])
{
    FILE *fp;
    void fileprint(FILE *fp, char *fname);

    if (argc == 1) {
        fileprint(stdin, "");
    } else {
        while (--argc > 0) {
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "print: can't open %s\n", *argv);
                exit(1);
            } else {
                fileprint(fp, *argv);
                fclose(fp);
            }
        }
    }
    return 0;
}
/* fileprint: print file fname */
void fileprint(FILE *fp, char *fname)
{
    int lineno, pageno = 1;
    char line[MAXLINE];
    int heading(char *fname, int pageno);

    lineno = heading(fname, pageno++);
    while (fgets(line, MAXLINE, fp) != NULL) {
        if (lineno == 1) {
            fprintf(stdout, "\f");
            lineno = heading(fname, pageno++);
        }
        fputs(line, stdout);
        if (++lineno > MAXPAGE - MAXBOT) {
            lineno = 1;
        }
    }
    fprintf(stdout, "\f");
}

/* heading: put heading and enough blank lines */
int heading(char *fname, int pageno)
{
    int ln = 3;

    fprintf(stdout, "\n\n");
    fprintf(stdout, "%s     page %d\n", fname, pageno);
    while (ln++ < MAXHDR) {
        fprintf(stdout, "\n");
    }
    return ln;
}

