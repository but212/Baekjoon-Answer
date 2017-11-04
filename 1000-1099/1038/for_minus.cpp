#include <iostream>
#include <cstring>

long lpow10[10] = {
    1, 10, 100, 1000, 10000, 100000,
    1000000, 10000000, 100000000, 1000000000
};

int Cache[11][11];

int getBC(int n, int k)
{
    if (n == k || k == 0)
        return 1;
    if (Cache[n][k] != -1)
        return Cache[n][k];

    return Cache[n][k] = getBC(n-1, k-1) + getBC(n-1, k);
}

const long makeNum(int n, int k, int num)
{
    int x = k - 1;

    if (!(k > 1))
        return num - 1;

    int FirstNum = x;
    for (int b = getBC(x, x); num > b;
         num -= b, FirstNum++, b = getBC(FirstNum, x));

    return FirstNum * lpow10[x] + makeNum(FirstNum - 1, x, num);
}

inline long solve(int n)
{
    for (int b, digit = 1; digit < 11; digit++) { // 1..10
        b = getBC(10, digit);
        if (n > b) n -= b;
        else return makeNum(9, digit, n);
    }
    return -1;
}

int main()
{
    memset(Cache, -1, sizeof(Cache));
    int n; std::cin >> n; n++;
    std::cout << solve(n) << std::endl;
    return 0;
}
