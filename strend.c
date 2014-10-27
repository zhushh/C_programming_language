/***********************************************************************
 *  > File Name: strend.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Sun 10 Aug 2014 01:53:10 PM CST
***********************************************************************/

/* strend: return 1 if string t occurs at the end of s */
int strend(char *s, char *t)
{
    char *bs = s;   /* remember beginning of strs */
    char *bt = t;

    for (; *s; s++)     /* end of string s */
        ;
    for (; *t; t++)     /* end of string t */
        ;
    for (; *s == *t; s--, t--)
        if (s == bs || t == bt)
            break;      /* at the beginning of a str */
    if (*s == *t && t == bt && *s != '\0')
        return 1;
    else
        return 0;
}
