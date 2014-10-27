#include <stdio.h>

#define MAXLINE 1000

int _getline(char line[], int maxline);
void max_copy(char to[], char from[], int num);

int main() {
    int len, sum_len;
    char line[MAXLINE];

    sum_len = 0;
    while ((len = _getline(line, MAXLINE)) > 0) {
        printf("%s", line);
        sum_len += len;
        if (len < MAXLINE - 1) {
            printf("\nstring len = %d\n", sum_len);
            sum_len = 0;
        } else if (len == MAXLINE - 1 && line[MAXLINE - 2] == '\n') {
            printf("\nstring len = %d\n", sum_len);
            sum_len = 0;
        }
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

