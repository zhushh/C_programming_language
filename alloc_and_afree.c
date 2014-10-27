/***********************************************************************
 *  > File Name: alloc_and_afree.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Sun 10 Aug 2014 12:59:45 PM CST
***********************************************************************/

#define ALLOCSIZE 10000     /* size of avaliable space */

static char allocbuf[ALLOCSIZE];   /* storage for alloc */
static char * allocp = allocbuf;   /* next free position */

char * alloc(int n)     /* return pointer to n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {   /* it fits */
        allocp += n;
        return allocp - n;      /* old p */
    } else {        /* not enough room */
        return 0;
    }
}
void afree(char *p)     /* free storage pointed to by p */
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}
