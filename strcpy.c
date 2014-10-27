/***********************************************************************
 *  > File Name: strcpy.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Sun 10 Aug 2014 01:19:56 PM CST
***********************************************************************/

/* strcpy: copy t to s; array subscript version */
void strcpy(char *s, char *t)
{
    int i;

    i = 0;
    while ((s[i] = t[i]) != '\0')
        ++i;
}
/* strcpy: copy t to s; pointer version */
void strcpy(char *s, char *t)
{
    int i;

    i = 0;
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}
/* strcpy: pointer version 2 */
void strcpy(char *s, char *t)
{
    while ((*s++ = *t++) != '\0');
}
/* strcpy: pointer version 3 */
void strcpy(char *s, char *t)
{
    while (*s++ = *t++)
        ;
}

