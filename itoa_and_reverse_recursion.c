/***********************************************************************
 *  > File Name: itoa_recursion.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Sat 09 Aug 2014 10:38:58 PM CST
***********************************************************************/

#include <math.h>

/* itoa: convert n to character in s; recursive */
void itoa(int n, char s[]) {
    static int i;

    if (n / 10) {
        itoa(n / 10, s);
    } else {
        i = 0;
        if (n < 0)
            s[i++] = '-';
    }
    s[i++] = fabs(n) % 10 + '0';
    s[i] = '\0';
}

#include <string.h>

/* reverse: reverse string s in place */
void reverse(char s[]) {
    void reverser(char s[], int i, int len);
    reverser(s, 0, strlen(s));
}

/* reverse: reverse string s in place; recursive */
void reverser(char s[], int i, int len) {
    int c, j;

    j = len - (i + 1);
    if (i < j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        reverser(s, ++i, len);
    }
}

