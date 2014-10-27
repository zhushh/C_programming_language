#include <stdio.h>
#include <string.h>
#define MAXLINE 1000 /* maxinum character per line */

int _getline(char line[], int lim);
int strindex(char source[], char searchfor[]);

/* find the index */
int main()
{
    char s[MAXLINE], t[MAXLINE];

    _getline(t, MAXLINE);
    while (_getline(s, MAXLINE) > 0)
        if (strindex(s, t) >= 0) {
            printf("%d\n", strindex(s, t));
        } else {
            printf("Not found\n");
        }

    return 0;
}

/* getline function */
int _getline(char s[], int lim)
{
    int i, c;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

/* strindex: return index t is rightmost occurence in s */
int strindex(char s[], char t[])
{
    int i, j, k;

    for (i = strlen(s) - 1; i >= 0; --i) {
        for (j = i, k = strlen(t) - 1; k >= 0 && s[j] == t[k]; --j, --k);
        if (k == -1)    // return index if find the substring
            return i - strlen(t) + 1;
    }
    return -1;
}

