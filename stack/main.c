/***********************************************************************
 *  > File Name: main.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Sat 09 Aug 2014 04:27:59 PM CST
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#define MAXOP 100

int main(void) {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
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
                if (op2 == 0.0)
                    printf("error: zero divisor\n");
                else
                    push(pop() / op2);
                break;
            case '\n':
                printf("Answer is:\t%.8g\n", pop());
                break;
            default:
                printf("error: unkown command %s\n", s);
                break;
        }
    }
    return 0;
}

