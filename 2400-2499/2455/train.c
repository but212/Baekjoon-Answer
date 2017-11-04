#include <stdio.h>
#define size 4

const int maxCalc(unsigned int iter, int* in, int* out, int max, int total)
{
    short condition = (((short)iter == 0) << 1) | ((short)max < total);

    if (condition & 2) {
        return max;
    }
    if (condition & 1) {
        return maxCalc(iter - 1, in + 1, out + 1, total, total + (*(in + 1) - *(out + 1)));
    } else {
        return maxCalc(iter - 1, in + 1, out + 1, max, total + (*(in + 1) - *(out + 1)));
    }
}

int main()
{
    int in[size], out[size];

    for (int i = 0; i < size; i++)
        scanf("%d %d", &out[i], &in[i]);

    printf("%d\n", maxCalc(size, in, out, in[0], in[0]));

    return 0;
}
