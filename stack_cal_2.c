#include <stdio.h>
#include <stdlib.h>   /* for atoi */

#define MAXOP  100  /* maxinum operand and operator */
#define NUMBER '0'  /* signal that number was found */

int getop(char []);
void push(double);
double pop(void);

int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atoi(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 == 0)
                    printf("error: zero is divisor\n");
                else
                    push(pop() / op2);
                break;
            case '%':
                op2 = pop();
                if (op2 - 0.000001 > 0.0000001 && op2 - 1.0 < 0.00000001)
                    printf("error: zero is divisior\n");
                else if (op2 + 1.0 > 0.00000001 && op2 - 0.0000001 < 0.00000001)
                    printf("error: zero is divisior\n");
                else
                    push((int)pop() % (int)op2);
                break;
            case '\n':
                printf("Answer is :\t%.8g\n", pop());
                break;
            default :
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

#define MAXVAL 100   /* maxinum depth of val stack */

int sp = 0;          /* next free stack position */
double val[MAXVAL];  /* value stack */

/*push: push f onto a stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("stack full, can't push %lf", f);
}
/* pop: pop and return top from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
        printf("error: stack empty\n");
    return 0.0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    s[1] = '\0';
    if (!isdigit(c) && c != '-' && c != '.')
        return c;   /* not a number */

    i = 0;
    if (c == '-') {
        if (isdigit(c = getch()) || c == '.') {
            s[++i] = c;     /* negative number */
        } else {
            if (c != EOF)
                ungetch(c);
            return '-';     /* minus sign */
        }
    }
    if (isdigit(c))     /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')       /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];    /* buffer for ungetch */
int bufp = 0;         /* next free position in buf */

int getch(void)  /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)  /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
