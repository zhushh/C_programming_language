/***********************************************************************
 *  > File Name: strlen.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Sun 10 Aug 2014 12:51:13 PM CST
***********************************************************************/

/* strlen: return length of string s */
size_t strlen(char *s) {
    size_t len;

    for (len = 0; *s != '\0'; s++)
        len++;
    return len;
}
/* strlen: version 2 */
size_t strlen(char *s)
{
    char *p = s;

    while (*p != '\0')
        ++p;
    return p - s;
}
