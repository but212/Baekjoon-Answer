#include <iostream>

#define size 4

constexpr int maxCalc(unsigned int iter, int* in, int* out, int max, int total)
{
    if (iter == 0) {
        return max;
    }

    if (max < total) {
        return maxCalc(iter - 1, in + 1, out + 1, total, total + (*(in + 1) - *(out + 1)));
    }
    else {
        return maxCalc(iter - 1, in + 1, out + 1, max, total + (*(in + 1) - *(out + 1)));
    }
}

int main()
{
    int in[size], out[size];
    for (int i = 0; i < size; i++) {
        std::cin >> out[i] >> in[i];
    }
    
    std::cout << maxCalc(size, in, out, in[0], in[0]) << std::endl;

    return 0;
}
