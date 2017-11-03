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

inline ulong value(std::string color0, std::string color1)
{
    return colorSearch(color0) * 10 + colorSearch(color1);
}

inline ulong cPower(std::string color)
{
    ulong exponent = colorSearch(color);
    ulong base = 10, result = 1;

    while(exponent) {
        if (exponent & 1)
            result *= base;
        exponent >>= 1;
        base *= base;
    }
    
    return result;
}

inline ulong finCalc(std::string color0, std::string color1, std::string color2)
{
    return value(color0, color1) * cPower(color2);
}

int main()
{
    std::string s0, s1, s2;
    std::cin >> s0;
    std::cin >> s1;
    std::cin >> s2;

    std::cout << finCalc(s0, s1, s2) << std::endl;
    
    return 0;
}
