/* setbits: set n bits of x at position p with bits of y */
unsigned setbits(unsigned x, int p, int n, unsigned y) {
    return x & ~(~(~0 << n) << (p+1-n)) |
        (y & ~(~0 << n)) << (p+1-n);
}

/* invert: invert the n bits of x that begin at position p */
unsigned invert(unsigned x, int p, int n) {
    return x ^ (~(~0 << n) << (p+1-n));
}

/* rightrot: rotate x to the right by n position */
unsigned rightrot(unsigned x, int n) {
    int wordlength(void);
    int rbit;

    while (n-- > 0) {
        rbit = (x & 1) << (worldlength() - 1);
        x = x >> 1;
        x = x | rbit;
    }
}

/* rightrot2: rotate x to the right by n position */
unsigned rightrot_(unsigned x, int n) {
    int wordlength();
    unsigned rbits;

    if ((n = n % wordlength()) > 0) {
        rbits = ~(~0 << n) & x;   /* n rightmost bits of x */
        rbits = rbits << (wordlength() - n);
        x = x >> n;
        x = x | rbits;
    }
    return x;
}
/* wordlength: computes word length of the machine */
int wordlength(void) {
    int i;
    unsigned v = (unsigned)~0;

    for (i = 1; (v = v >> 1) > 0; ++i)
        ;
    return i;
}
