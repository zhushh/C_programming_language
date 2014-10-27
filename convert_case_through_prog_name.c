/***********************************************************************
 *  > File Name: convert_case_through_prog_name.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Sun 17 Aug 2014 04:07:54 PM CST
***********************************************************************/

#include <stdio.h>
#include <ctype.h>

int strcmp(char *s, char *t)
{
    while (*s++ == *t++ && *s != '\0')
        if (*s == '\0' && *t == '\0')
            return 0;
    return *s - *t;
}
/* lower: convert upper case to lower case */
/* upper: convert lower case to upper case */
int main(int argc, char *argv[])
{
    int c;

    printf("%s\n", argv[0]);
    if (strcmp(argv[0], "lower") == 0) {
        while ((c = getchar()) != EOF) {
            putchar(tolower(c));
        }
    } else if ((strcmp(argv[0], "upper")) == 0) {
        while ((c = getchar()) != EOF) {
            putchar(toupper(c));
        }
    } else {
        while ((c = getchar()) != EOF) {
            putchar(c);
        }
    }
    return 0;
}

