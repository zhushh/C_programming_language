#include <stdio.h>

void convert(char *s);
int main()
{
	char str[100];
	printf("Enter the string within 100 character:\n");
	fgets(str, sizeof(str), stdin);
	convert(str);
	printf("%s", str);
	return 0;
}
/* convert lowercase into uppercase */
void convert(char *s)
{
	int i = 0;
	while (s[i] != '\0') {
		(s[i] >= 'A' && s[i] <= 'Z') ? s[i] = s[i] + 'a' - 'A', i++ : i++;
	}
}

