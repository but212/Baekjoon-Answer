#include <stdio.h>

inline int m100(int n) { return n % 100; }
inline int minCalc(int N, int M)
{
    int min = N - m100(N);
    while (min % M != 0)
        min++;
    return m100(min);
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    int min = minCalc(N, M);

    if (min < 10)
        printf("0%d\n", min);
    else
        printf("%d\n", min);

    return 0;
}
