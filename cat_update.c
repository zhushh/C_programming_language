/***********************************************************************
 *  > File Name: cat_update.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Sun 17 Aug 2014 10:04:45 PM CST
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/syscall.h>

/* error: print an error message and die */
void error(char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    fprintf(stderr, "error: ");
    vfprintf(stderr, fmt, ap);
    fprintf(stderr, "\n");
    va_end(ap);
    exit(1);
}

/* cat: concatenate files - read / write / open / close */
int main(int argc, char *argv[])
{
    int fd;
    void filecopy(int ifd, int ofd);

    if (argc == 1) {
        filecopy(0, 1);
    } else {
        while (--argc > 0) {
            if ((fd = open(*++argv, O_RDONLY)) == 1) {
                error("cat: can't open %s", *argv);
            } else {
                filecopy(fd, 1);
                close(fd);
            }
        }
    }
    return 0;
}

#define BUFSIZE 1000
/* filecopy: copy file ifd to file ofd */
void filecopy(int ifd, int ofd)
{
    int n;
    char buf[BUFSIZE];

    while ((n = read(ifd, buf, BUFSIZE)) > 0) {
        if (write(ofd, buf, n) != n) {
            error("cat: write error");
        }
    }
}

