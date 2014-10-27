/* itob: convert n into s whose base is b */
#define abs(x) ((x) < 0 ? -x : x)
void itob(int n, char s[], int b)
{
    char simbol[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int sign, i;

    sign = n;
    i = 0;
    do {
        if (abs(n % b) < 10)
            s[i++] = abs(n % b) + '0';
        else
            s[i++] = simbol[abs(n % b) % 10];
    } while ((n /= b) != 0);

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

