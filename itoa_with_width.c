/* itoa: convert n into s with specific width */
#define abs(x) ((x) < 0 ? -x : x)
void itoa(int n, char s[], int width)
{
    int i, sign;

    sign = n;  /* record sign */
    i = 0;
    do {           /* generate digits in reverse order */
        s[i++] = abs(n % 10) + '0';  /* get next digit */
    } while ((n /= 10) != 0);        /* delete it */
    if (i < width - 1)
        for (; i < width - 1; ++i)   /* pad blank */
            s[i] = ' ';
    sign < 0 ? s[i] = '-' : s[i] = ' ';
    reverse(s);
}

