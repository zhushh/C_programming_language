/***********************************************************************
 *  > File Name: strcat.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Sun 10 Aug 2014 01:46:32 PM CST
***********************************************************************/

/* strcat: concatenate t to the end of string s */
void strcat(char *s, char *t)
{
    while (*s)    /* end loop if *s == '\0' */
        s++;
    while (*s++ = *t++)
        ;
}
