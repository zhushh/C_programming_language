/***********************************************************************
 *  > File Name: ls.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Sun 17 Aug 2014 07:19:20 PM CST
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *dirp;

    if (argc != 2)
        fprintf(stderr, "a single argument (the directory name) is required\n");
    if ( (dp = opendir(argv[1])) == NULL)
        fprintf(stderr, "can't open %s\n", argv[1]);
    while ( (dirp = readdir(dp)) != NULL) {
        printf("%s\n", dirp->d_name);
    }

    closedir(dp);
    exit(0);
}
