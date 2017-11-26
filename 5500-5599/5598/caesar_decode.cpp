#include <iostream>
#include <string>

char caesar_decode(char c)
{
    switch(c) {
        case 'C':
            return 'Z';
            break;
        case 'B':
            return 'Y';
            break;
        case 'A':
            return 'X';
            break;
        default:
            return c - 3;
    }
}

int main()
{
    std::string Input, Output;
    getline(std::cin, Input);

    for (const auto& i : Input)
        Output += caesar_decode(i);
    
    std::cout << Output << std::endl;
    return 0;
}
