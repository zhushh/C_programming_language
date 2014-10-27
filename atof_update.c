#include <ctype.h>

/* atof: convert sting s to double */
double atof(char s[])
{
    double val, power, exponent;
    int i, sign, flag;

    for (i = 0; isspace(s[i]); ++i); /* skip white space */

    sign = (s[i] == '-') ? -1 : 1;  /* sign the value */
    if (s[i] == '+' || s[i] == '-') ++i;
    for (val = 0; isdigit(s[i]); ++i)
        val = 10.0 * val + s[i] - '0';
    if (s[i] == '.') ++i;
    for (power = 1; isdigit(s[i]); ++i) {
        val = 10.0 * val + s[i] - '0';
        power *= 10;
    }
    if (s[i] == 'e' || s[i] == 'E') ++i;
    flag = (s[i] == '-') ? -1 : 1;  /* flag the exponent */
    if (s[i] == '-' || s[i] == '+') ++i;
    for (exponent = 0; isdigit(s[i]); ++i)
        exponent = 10.0 * exponent + s[i] - '0';
    while (exponent-- > 0) {
        if (flag == 1) power /= 10;
        else power *= 10;
    }
    return sign * val / power;
}

