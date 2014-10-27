/***********************************************************************
 *  > File Name: count_the_number_of_each_words.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Wed 13 Aug 2014 01:56:10 PM CST
***********************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXWORD 100
struct tnode {      /* the tree node: */
    char *word;             /* point to the text */
    int count;              /* number of occurrences */
    struct tnode *left;     /* left child */
    struct tnode *right;    /* right child */
};

int getword(char *, int);
struct tnode *addtree(struct tnode *, char *);
void tree_print(struct tnode *);

/* word frequency count */
int main()
{
    struct tnode *root;
    char word[MAXWORD];
    
    root = NULL;
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            root = addtree(root, word);
        }
    }
    tree_print(root);
    return 0;
}

#include <stdlib.h>

struct tnode *talloc(void);
char *strdup(char *);

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    if (p == NULL) {            /* add a new word has arrived */
        p = talloc();           /* make a new node */
        p->word = strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else {
        if ((cond = strcmp(w, p->word)) == 0) {
            p->count++;         /* repeated word */
        } else if (cond < 0) {      /* less than into left subtree */
            p->left = addtree(p->left, w);
        } else {                    /* greater than into right subtree */
            p->right = addtree(p->right, w);
        }
    }
    return p;
}
/* tree_print: in-order print of tree p */
void tree_print(struct tnode *p)
{
    if (p != NULL) {
        tree_print(p->left);
        printf("%4d %s\n", p->count, p->word);
        tree_print(p->right);
    }
}
/* talloc: make a node */
struct tnode *talloc(void)
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
/* strdup: make a duplicate of w */
char *strdup(char *w)
{
    char *t;
    t = (char *)malloc(strlen(w) + 1);  /* +1 for '\0' */
    if (t != NULL) {
        strcpy(t, w);
    }
    return t;
}

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
    int c, d, comment(void), getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (isalpha(c) || c == '_' || c == '#') {
        for (; --lim > 0; w++)
            if (!isalnum(*w = getch()) && *w != '_') {
                ungetch(*w);
                break;
            }
    } else if (c == '\'' || c == '"') {
        for (; --lim > 0; w++)
            if ((*w = getch()) == '\\')
                *++w = getch();
            else if (*w == c) {
                w++;
                break;
            } else if (*w == EOF)
                break;
    } else if (c == '/') {
        if ((d = getch()) == '*')
            c = comment();
        else
            ungetch(d);
    }
    *w = '\0';
    return c;
}

#define BUFSIZE 1000

char buf[BUFSIZE];
int bufp = 0;

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

/* comment: skip over comment and return a character */
int comment(void)
{
    int c;
    while ((c = getch()) != EOF)
        if (c == '*') {
            if ((c = getch()) == '/')
                break;
            else
                ungetch(c);
        }
    return c;
}

