/* itoa: convert n to characters in s,
 * including handle with the max negative number
 * since the max negative number can not be
 * represented as the max positive number by n = -n.
 */
#define abs(x) ((x) < 0 ? -(x) : (x))
void itoa(int n, char s[])
{
    int i, sign;

    sign = n;  /* record sign */
    i = 0;
    do {           /* generate digits in reverse order */
        s[i++] = abs(n % 10) + '0';  /* get next digit */
    } while ((n /= 10) != 0);        /* delete it */

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);  /* reverse s */
}

void reverse(char s[]) {
    int i, j, c;
    for (i = 0; s[i] != '\0'; ++i)
        ;
    --i;
    if (s[i] == '\n')
        --i;
    for (j = 0; j < i; ++j, --i) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

