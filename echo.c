/***********************************************************************
 *  > File Name: echo.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Sun 10 Aug 2014 08:45:31 PM CST
***********************************************************************/

#include <stdio.h>

/* echo command-line arguments; 1st version */
int main(int argc, char *argv[])
{
    int i;

    for (i = 1; i < argc; i++)
        printf("%s%s", argv[i], (i < argc - 1) ? " " : "");
    printf("\n");
    return 0;
}

/*
 * echo command-line arguments; 2nd version *
 
int main(int argc, char *argv[]) {
    while (--argc > 0)
        printf("%s%s", *++argv, (argc > 1) ? " " : "");
    // printf((argc > 1) ? "%s " : "%s", *++argv);
    printf("\n");
    return 0;
}
*/
