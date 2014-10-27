/***********************************************************************
 *  > File Name: print_pattern_with_option_new.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Sun 17 Aug 2014 06:57:59 PM CST
***********************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000    /* maximum input line length */
int main(int argc, char *argv[])
{
    char pattern[MAXLINE];
    int c, except = 0, number = 0;
    FILE *fp;
    void fpat(FILE *fp, char *fname, char *pattern, 
        int except, int number);

    while (--argc > 0 && (*++argv)[0] == '-') {
        while (c = *++argv[0]) {
            switch (c) {
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    printf("find: illegal option %c\n", c);
                    argc = 0;
                    break;
            }
        }
    }
    if (argc >= 1) {
        strncpy(pattern, *argv, MAXLINE);
    } else {
        printf("Usage: find [-x] [-n] pattern [file ...]\n");
        exit(1);
    }
    if (argc == 1) {            /* read standard input */
        fpat(stdin, "", pattern, except, number);
    } else {
        while (--argc > 0) {    /* get a file name */
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "find: can't open %s\n", *argv);
                exit(1);
            } else {    /* named file have been opened */
                fpat(fp, *argv, pattern, except, number);
                fclose(fp);
            }
        }
    }
    return 0;
}
/* fpat: find pattern */
void fpat(FILE *fp, char *fname, char *pattern,
            int except, int number)
{
    char line[MAXLINE];
    long linenum = 0;

    while (fgets(line, MAXLINE, fp) != NULL) {
        ++linenum;
        if ((strstr(line, pattern) != NULL) != except) {
            if (*fname) {           /* have a file name */
                printf("%s - ", fname);
            }
            if (number) {           /* print line number */
                printf("%ld: ", linenum);
            }
            printf("%s", line);
        }
    }
}

