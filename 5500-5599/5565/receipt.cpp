#include <iostream>

int price[9];
const int solve(int& total)
{
    int result = 0;
    for (int& i: price)
        result += i;
    return total - result;
}

int main()
{
    int total; std::cin >> total;
    for (int& i: price)
        std::cin >> i;

    std::cout << solve(total) << std::endl;
    return 0;
}
