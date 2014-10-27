/* expand: expand shorthand notation in s1 to s2 
 * like a-z will be abcd...xyz, and 0-9 is 0123...89.
 * be prepared to handle case like a-b-c and a-z0-9 and -a-z 
 ***************************************************************/
void expand(char s1[], char s2[])
{
    int i, j, k, len;
    char start, end;

    for (len = 0; s1[len] != '\0';)     /* find the length of  string s1 */
        ++len;
    for (i = 0, j = 0; i < len - 2; ++i) {
        start = s1[i];
        while (i < len - 2 && s1[i + 1] == '-') {
            end = s1[i + 2];
            for (k = 0; k <= end - start; ++j, ++k) {
                s2[j] = start + k;
            }
            start = ++end;
            i += 2;
        }
    }
    s2[j] = '\0';
}
/* answer:  */
void expand(char s1[], char s2[]) {
    char c;
    int i, j;

    i = j = 0;
    while ((c = s[i++]) != '\0')    /* fetch a char from s1[] */
        if (s1[i] == '-' && s1[i+1] >= c) {
            i++;
            while (c < s1[i])   /* expand shorthand */
                s2[j++] = c++;
        } else {
            s2[j++] = c;    /* copy the character */
        }
    s2[j] = '\0';
}

