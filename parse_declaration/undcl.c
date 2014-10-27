/***********************************************************************
 *  > File Name: undcl.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Mon 11 Aug 2014 10:37:20 PM CST
***********************************************************************/

#include <stdio.h>
#include <string.h>

#define MAXTOKEN 100
extern int gettoken(void);

enum { NAME, PARENS, BRACKETS };
int tokentype;
char token[MAXTOKEN];
char out[1000];

/* undcl: convert word descriptions to declarations */
int main()
{
    int type;
    char temp[MAXTOKEN];

    while (gettoken() != EOF) {
        strcpy(out, token);
        while ((type = gettoken()) != '\n') {
            if (type == PARENS || type == BRACKETS)
                strcat(out, token);
            else if (type == '*') {
                 sprintf(temp, "(*%s)", out);
                 strcpy(out, temp);   
            } else if (type == NAME) {
                sprintf(temp, "%s %s", token, out);
                strcpy(out, temp);
            } else
                printf("invalid input at %s\n", token);
        }
        printf("%s\n", out);
    }
    return 0;
}

