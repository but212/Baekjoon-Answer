#include <stdio.h>
#include <stdbool.h>

int Dp[1000001];

inline bool div0(int i, int n) { return i % n == 0; }
inline int min(int x, int y)
{
    if (x > y)  return y;
    else        return x;
}
inline int getMin(int i, int n)
{
    return min(Dp[i], Dp[i / n] + 1);
}

int getCalc(int n)
{
    Dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        Dp[i] = Dp[i-1] + 1;
        if (div0(i, 2)) Dp[i] = getMin(i, 2);
        if (div0(i, 3)) Dp[i] = getMin(i, 3);
    }

    return Dp[n];
}

int main(void)
{
    int n; scanf("%d", &n);
    printf("%d\n", getCalc(n));
    return 0;
}
