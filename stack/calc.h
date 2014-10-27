/***********************************************************************
 *  > File Name: calc.h
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Sat 09 Aug 2014 04:35:18 PM CST
***********************************************************************/

#ifndef _CALC_H_
#define _CALC_H_

#define NUMBER '0'  /* signal that a number was found */
void push(double);  /* push: push a number onto a stack */
double pop(void);   /* pop: pop a number and return top value from stack */
int getop(char []); /* getop: get an operator */
int getch(void);    /* getch: get a (possibly push-back) character */
void ungetch(int);  /* ungetch: push character back on input */

#endif

