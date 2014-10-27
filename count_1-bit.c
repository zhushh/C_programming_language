#include <stdio.h>

/* count 1 bit of integer x on binary */
int bitCount(unsigned int x);
int main()
{
	int x;
	printf("Enter an integer: ");
	scanf("%d", &x);
	x = bitCount(x);
	printf("%d\n", x);
	return 0;
}
int bitCount(unsigned int x)
{
	int count;
	for (count = 0; x != 0; x &= (x - 1))
	    count++;
	return count;
}
/* bitcount: count the 1-bits in x
int bitCount(unsigned x) {
    int b;
    for (b = 0; x != 0; x >>= 1)
        if (x & 01)
            b++;
    return b;
}
*/
