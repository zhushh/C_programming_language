/***********************************************************************
 *  > File Name: stack.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Sat 09 Aug 2014 04:41:33 PM CST
***********************************************************************/

#ifndef STACK_C
#define STACK_C

#include <stdio.h>
#include "calc.h"
#define MAXVAL 100

static int sp = 0;
static double val[MAXVAL];

void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g", f);
}

double pop(void) {
    if (sp > 0)
        return val[--sp];
    else
        printf("error: empty stack\n");
    return 0.0;
}

#endif
