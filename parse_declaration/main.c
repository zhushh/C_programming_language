/***********************************************************************
 *  > File Name: parse_declaration.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Mon 11 Aug 2014 09:33:13 PM CST
***********************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN    100
enum { NAME, PARENS, BRACKETS };

extern void dcl(void);
extern void dirdcl(void);
extern int gettoken(void);

int tokentype;              /* type of last token */
char token[MAXTOKEN];       /* last token string */
char name[MAXTOKEN];        /* identifier name */
char datatype[MAXTOKEN];    /* data type = char, int, etc. */

char out[1000];

/* convert declaration to words */
int main()
{
    while (gettoken() != EOF) {
        strcpy(datatype, token);
        out[0] = '\0';
        dcl();
        if (tokentype != '\n')
            printf("syntax error\n");
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}

