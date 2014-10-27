#include <stdio.h>

int escape(char *s1, char *s2);
int main()
{
    char t[100], s[150];
    int i = 0, max;
    while (scanf("%c", &t[i]) != EOF) {
        i++;
    }
    max = escape(s, t);
    for (i = 0; i < max; i++) {
        printf("%c", s[i]);
    }
    printf("\n");
    return 0;
}

// make the tab and new line key visiable
int escape(char *s1, char *s2)
{
    int i, j;
    for (i = 0, j = 0; s2[i] != '\0'; i++, j++) {
        switch (s2[i]) {
            case '\t': s1[j] = '\\'; s1[++j] = 't'; break;
            case '\n': s1[j] = '\\'; s1[++j] = 'n'; break;
            default: s1[j] = s2[i]; break;
        }
    }
    return j;
}


