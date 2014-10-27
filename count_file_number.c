/***********************************************************************
 *  > File Name: count_file_number.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Mon 11 Aug 2014 01:43:10 AM CST
***********************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    DIR *dp;
    struct dirent *dirp;
    int sum;

    if (argc != 2)
        printf("a single argument (the directory name) is required!");
    if ((dp = opendir(argv[1])) == NULL)
        printf("error: can't open %s", argv[1]);

    sum = 0;
    while ((dirp = readdir(dp)) != NULL)
        sum++;
    printf("%s contains %d files\n", argv[1], sum);
    closedir(dp);
    return 0;
}
