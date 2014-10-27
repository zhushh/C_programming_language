/***********************************************************************
 *  > File Name: dcl_and_dirdcl.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Mon 11 Aug 2014 10:23:34 PM CST
***********************************************************************/

#include <stdio.h>
#include <string.h>

enum { NAME, PARENS, BRACKETS };
extern int gettoken(void);
extern int tokentype;
extern char token[];
extern char name[];
extern char out[];

void dcl(void);
void dirdcl(void);

/* dcl: parse a declarator */
void dcl(void)
{
    int ns;

    for (ns = 0; gettoken() == '*';)    /* count *'s */
        ns++;
    dirdcl();
    while (ns-- > 0)
        strcat(out, " pointer to");
}
/* dirdcl: parse a direct declarator */
void dirdcl(void)
{
    int type;

    if (tokentype == '(') {
        dcl();
        if (tokentype != ')')
            printf("error: missing )\n");
    } else if (tokentype == NAME)
        strcpy(name, token);
    else
        printf("error: unexpected name or (dcl)\n");
    while ((type=gettoken()) == PARENS || type == BRACKETS) {
        if (type == PARENS)
            strcat(out, " function returning");
        else {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
    }
}

