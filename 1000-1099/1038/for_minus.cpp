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
    int KM1 = k - 1;

    if (!(k > 1))
        return num - 1;

    int FirstNum = KM1;
    for (int b = getBC(KM1, KM1); num > b;
         num -= b, FirstNum++, b = getBC(FirstNum, KM1));

    return FirstNum * lpow10[KM1] + makeNum(FirstNum - 1, KM1, num);
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

inline void program_print(int n)
{
    memset(Cache, -1, sizeof(Cache));
    std::cout << solve(n) << std::endl
}

int main(void)
{
    int n; std::cin >> n; n++;
    program_print(n);
    return 0;
}
