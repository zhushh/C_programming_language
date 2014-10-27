#include <stdio.h>

#define MAXLINE 1000

int _getline(char line[], int maxline);
void max_copy(char to[], char from[], int num);

int main() {
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = _getline(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            max_copy(longest, line, sizeof(longest));
        }
    }
    if (max > 0) {
        printf("The longest string is : %s", longest);
    }
    return 0;
}

int _getline(char s[], int limit) {
    int c, i;

    for (i = 0; i < limit-1 && (c=getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
void max_copy(char dest[], char src[], int max) {
    int i;

    i = 0;
    while (i < max && (dest[i] = src[i]) != '\0')
        ++i;
}

