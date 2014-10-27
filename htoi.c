/* HTOI: convert hexadecimal string to integer */

int htoi(char s[]) {
    enum loop {NO, YES};
    enum loop OK = YES;
    int i, hexdigit, inhex, num;

    i = 0;
    if (s[i] == '0') {  /* skip optional 0x or 0X */
        ++i;
        if (s[i] == 'x' || s[i] == 'X')
            ++i;
    }

    num = 0;
    for (; OK == YES; ++i) {
        if (s[i] >= '0' && s[i] <= '9')
            hexdigit = s[i] - '0';
        else if (s[i] >= 'a' && s[i] <= 'f')
            hexdigit = s[i] - 'a' + 10;
        else if (s[i] >= 'A' && s[i] <= 'F')
            hexdigit = s[i] - 'A' + 10;
        else
            OK = NO;

        if (OK == YES)
            num = 16 * num + hexdigit;
    }
    return num;
}
