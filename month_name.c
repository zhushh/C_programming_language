/***********************************************************************
 *  > File Name: month_name.c
 *  > Author: zhushuhuang
 *  > Mail: zsh5318@gmail.com
 *  > Created Time: Sun 10 Aug 2014 07:10:28 PM CST
***********************************************************************/

/* month_name: return name of n-th month */
char *month_name(int n) {
    static char *name[] = {
        "Illegal month",
        "January", "February", "Match",
        "April", "May", "June", "July",
        "August", "September", "October",
        "November", "December"
    };
    return (n < 1 || n > 12) ? name[0] : name[n];
}