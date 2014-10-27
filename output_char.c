#include <stdio.h>

int main() {
    int i, count;

    i = 'A';
    for (count = 0; count < 2000; ++count, ++i) {
        putchar(i);
        if (i == 'Z')
            i = 'A' - 1;
    }
    return 0;
}
