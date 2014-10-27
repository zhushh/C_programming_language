/***********************************************************************
 *  > File Name: count_words_and_sorted_output.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Wed 13 Aug 2014 07:06:15 PM CST
***********************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXWORD     100
#define NDISTINCT   1000

struct tnode {              /* the tree node:        */
    char *word;             /* points to the next    */
    int count;              /* number of occurrences */
    struct tnode *left;     /* left child            */
    struct tnode *right;    /* right child           */
};

struct tnode *addtree(struct tnode *, char *);
int getword(char *, int);
void sortlist(void);
void treestore(struct tnode *);

struct tnode *list[NDISTINCT];  /* pointers to tree nodes */
int numTreeNode = 0;            /* number of tree nodes */

/* print distinct words sorted in decreasing order of freq. */
int main()
{
    struct tnode *root;
    char word[MAXWORD];
    int i;

    root = NULL;
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            root = addtree(root, word);
        }
    }
    treestore(root);
    sortlist();
    for (i = 0; i < numTreeNode; ++i) {
        printf("%4d:%20s\n", list[i]->count, list[i]->word);
    }
    return 0;
}

/* treestore: store in list[] pointers to tree nodes */
void treestore(struct tnode *p)
{
    if (p != NULL) {
        treestore(p->left);
        if (numTreeNode < NDISTINCT) {
            list[numTreeNode++] = p;
        }
        treestore(p->right);
    }
}

/* sortlist: sort list of pointers to tree nodes */
void sortlist(void)
{
    int gap, i, j;
    struct tnode *temp;

    /* shellsort algorithm */
    for (gap = numTreeNode/2; gap > 0; gap /= 2) {
        for (i = gap; i < numTreeNode; ++i) {
            for (j = i-gap; j >= 0; j -= gap) {
                if ((list[j]->count) >= (list[j+gap]->count)) {
                    break;
                }
                temp = list[j];
                list[j] = list[j+gap];
                list[j+gap] = temp;
            }
        }
    }
}

struct tnode *talloc(void)
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
/* addtree: add a node to tree with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    if (p == NULL) {
        p = talloc();
        p->count = 1;
        p->word = strdup(w);
        p->left = p->right = NULL;
    } else {
        if ((cond = strcmp(w, p->word)) == 0) {
            p->count++;
        } else if (cond < 0) {
            p->left = addtree(p->left, w);
        } else {
            p->right = addtree(p->right, w);
        }
    }
    return p;
}

/* getword: get next word or character from input */
int getword(char *word, int limit)
{
    int c, comment(void), getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()))
        ;
    if (c != EOF) {
        *w++ = c;
    }
    if (isalpha(c) || c == '_' || c == '#') {
        for (; --limit > 0; ++w) {
            if (!isalnum(*w = getch()) && *w != '_') {
                ungetch(*w);
                break;
            }
        }
    } else if (c == '\'' || c == '"') {
        for (; --limit > 0; w++) {
            if ((*w = getch()) == '\\') {
                *++w = getch();
            } else if (*w == c) {
                w++;
                break;
            } else if (*w == EOF) {
                break;
            }
        }
    } else if (c == '/') {
        if ((c = getch()) == '*') {
            c = comment();
        } else {
            ungetch(c);
        }
    }
    *w = '\0';
    return c;
}

#define BUFSIZE 100
static char buf[BUFSIZE];
static int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("error: too much input\n");
    else
        buf[bufp++] = c;
}

/* comment: skip over the comment */
int comment(void)
{
    int c;

    while ((c = getch()) != EOF) {
        if (c == '*') {
            if ((c = getch()) == '/') {
                break;
            }
        }
    }
    return c;
}

