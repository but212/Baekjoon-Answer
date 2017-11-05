#include <string>
#include <iostream>

typedef unsigned long ulong;
typedef unsigned short ushort;

const std::string colors[10] = {
    "black",  "brown",
    "red",    "orange",
    "yellow", "green",
    "blue",   "violet",
    "grey",   "white"
};

const ushort colorSearch(std::string color)
{
    ushort i = 0;
    for (const auto col: colors) {
        if (color == col)
            break;
        i++;
    }

    return i;
}

inline ulong solve(std::string color0, std::string color1, std::string color2)
{
    ulong value = colorSearch(color0) * 10 + colorSearch(color1);
    ushort powexp = colorSearch(color2);
    ulong ulpow10[10] = {
        1, 10, 100, 1000, 10000, 100000,
        1000000, 10000000, 100000000, 1000000000
    };

    return value * ulpow10[powexp];
}

int main()
{
    std::string s0, s1, s2;
    std::cin >> s0;
    std::cin >> s1;
    std::cin >> s2;

    std::cout << solve(s0, s1, s2) << std::endl;
    
    return 0;
}
