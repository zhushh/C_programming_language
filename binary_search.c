// find number x in the array v.
// wrong program!!!(also it looks like it is right)
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low < high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid + 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}
// explain:
// if x does not exit in the array v
// but is always between low and high,
// then this program will be running-time error
// for example:
//     array v is: 1 2 3 4 6 7 8 9
//     and x is: 5
//     then n is: 8
// the program will be running-time error
// the loop will not end since low and 
// high will always is 4 and 6 

// modify code:

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    mid = 0;
    while (low < high) {
        mid = (low + high) / 2;
        if (x < v[mid]) high = mid - 1;  // now is subtract
        if (x > v[mid]) low = mid + 1;
        if (x == v[mid]) return mid;
    }
    return -1;
}

// another binary search:
int binsearch(int a[], int low, int high, int x)
{
    int mid;
    while (low < high) {
        mid = (low + high) / 2;
        if (x < a[mid]) high = mid - 1;
        if (x > a[mid]) low = mid + 1;
        if (x == a[mid]) return mid;
    }
    return -1;
}
// one fatal peril in the above program is overflow.
// look if low is 10^9 and high is 10^9 + 1;
// then the sum of low and high will overflow
// we can modify the code as follow:

int binsearch(int a[], int low, int high, int x)
{
    int mid;
    while (low < high) {
        mid = low + (high - low) / 2;
        if (x < a[mid]) high = mid - 1;
        if (x > a[mid]) low = mid + 1;
        if (x == a[mid]) return mid;
    }
    return -1;
}
// mid = low + (high - low) / 2;
// then mid will always between low and high

