/* reverse: reverse string s in place */
void reverse(char s[])
{
    int i, j;
    char c;
    
    i = 0;
    while (s[i] != '\0')    /* find the end of string */
        ++i;
    --i;
    if (s[i] == '\n')   /* leave newline in place */
        --i;
    for (j = 0; j < i; ++j, --i) {
        c = s[j];
        s[j] = s[i];
        s[i] = c;
    }
}

