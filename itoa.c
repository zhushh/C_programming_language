/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
    void reverse(char str[]);
    int i, sign;
    if ((sign == n) < 0)  /* record sign */
        n = -n;           /* make n positive */
    i = 0;
    do {      /* generate digits in reverse order */
        s[i++] = n % 10 + '0';  /* get next digit */
    } while ((n /= 10) > 0);    /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int i, j;
    char c;
    
    i = 0;
    while (s[i] != '\0')    /* find the end of string */
        ++i;
    --i;
    if (s[i] == '\n')   /* leave newline in place */
        --i;
    for (j = 0; j < i; ++j, --i) {
        c = s[j];
        s[j] = s[i - j];
        s[i] = c;
    }
}

/* itoa: convert n to characters in s; pointer version */
void reverse(char *);

void itoa(int n, char *s)
{
    int sign;
    char *t = s;

    if ((sign = n) < 0)
        n = -n;
    do {
        *s++ = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        *s++ = '-';
    *s = '\0';
    reverse(t);
}

#include <string.h>

/* reverse: reverse string s in place */
void  reverse(char *s)
{
    int c;
    char *t;

    for (t = s + strlen(s) - 1; s < t; s++, t--) {
        c = *s;
        *s = *t;
        *t = c;
    }
}

