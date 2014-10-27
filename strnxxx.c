/***********************************************************************
 *  > File Name: strncpy.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Sun 10 Aug 2014 01:58:49 PM CST
***********************************************************************/

/* strncpy: copy the first n char of t to s */
void strncpy(char *s, char *t, size_t n)
{
    while (n-- > 0 && *t)
        *s++ = *t++;
    while (n-- > 0)     /* strlen(t) < n */
        *s++ = '\0';    /* copy '\0' to full s */
}

/* strncmp: compare the first n char */
int strncmp(char *s, char *t, size_t n)
{
    for (; *s == *t; s++, t++)
        if (*s == '\0' || --n <= 0)
            return 0;
    return *s - *t;
}
/* strncat: concatenate the first n char of t to s */
void strncat(char *s, char *t, size_t n)
{
    void strncpy(char *s, char *t, size_t n);
    int strlen(char *);

    strncpy(s+strlen(s), t, n);
}
/* strlen: return the length of s */
size_t strlen(char *s)
{
    size_t l;

    l = 0;
    while (*s++)
        l++;
    return l;
}

