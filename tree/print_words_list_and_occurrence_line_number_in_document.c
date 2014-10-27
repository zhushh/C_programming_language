/***********************************************************************
 *  > File Name: print_words_list_and_occurrence_line_number_in_document.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Wed 13 Aug 2014 03:03:44 PM CST
***********************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXWORD 100

struct linklist {   /* link list of line number */
    int lnum;
    struct linklist *ptr;
};

struct tnode {                  /* the tree node */
    char *word;                 /* points to the text */
    struct linklist *lines;     /* line number */
    struct tnode *left;         /* left child */
    struct tnode *right;        /* right child */
};

struct tnode *addtreex(struct tnode *, char *, int);
int getword(char *, int);
int noiseword(char *);
void treeprint(struct tnode *);

/* cross-referencer */
int main()
{
    struct tnode *root;
    char word[MAXWORD];
    int linenum = 1;

    root = NULL;
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0]) && noiseword(word) == -1) {
            root = addtreex(root, word, linenum);
        } else if (word[0] == '\n') {
            linenum++;
        }
    }
    treeprint(root);
    return 0;
}

struct tnode *talloc(void);
struct linklist *lalloc(void);
void addln(struct tnode *, int);

/* addtreex: add a node with w, at or below p */
struct tnode *addtreex(struct tnode *p, char *w, int linenum)
{
    int cond;

    if (p == NULL) {
        p = talloc();
        p->word = strdup(w);
        p->lines = lalloc();
        p->lines->lnum = linenum;
        p->left = p->right = NULL;
        p->lines->ptr = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0) {
        addln(p, linenum);
    } else if (cond < 0) {
        p->left = addtreex(p->left, w, linenum);
    } else {
        p->right = addtreex(p->right, w, linenum);
    }
    return p;
}
/* addln: add a line number to the linked list */
void addln(struct tnode *p, int linenum)
{
    struct linklist *temp;

    temp = p->lines;
    while (temp->ptr != NULL && temp->lnum != linenum) {
        temp = temp->ptr;
    }
    if (temp->lnum != linenum) {
        temp->ptr = lalloc();
        temp->ptr->lnum = linenum;
        temp->ptr->ptr = NULL;
    }
}
/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p)
{
    struct linklist *temp;
    if (p != NULL) {
        treeprint(p->left);
        printf("%15s: ", p->word);
        for (temp = p->lines; temp != NULL; temp = temp->ptr) {
            printf("%4d ", temp->lnum);
        }
        printf("\n");
        treeprint(p->right);
    }
}
/* make a tnode */
struct tnode *talloc(void)
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
/* make a linklist node */
struct linklist *lalloc(void)
{
    return (struct linklist *)malloc(sizeof(struct linklist));
}
/* noiseword: identify word as a noiseword */
int noiseword(char *w)
{
    static char *nw[] = {
        "a",
        "an",
        "and",
        "are",
        "in",
        "is",
        "of",
        "or",
        "that",
        "the",
        "this",
        "to"
    };

    int cond, mid;
    int low = 0;
    int high = sizeof(nw) / sizeof(char *) - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        if ((cond = strcmp(w, nw[mid])) < 0) {
            high = mid - 1;
        } else if (cond > 0) {
            low = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
    int c, d, comment(void), getch(void);
    void ungetch(int);
    char *w = word;

    while ((c = getch()) == ' ' || c == '\t')
        ;               /* can't use "while (issapce(c = getch()))" instead */
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

