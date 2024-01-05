//
//  main.cpp
//  translator_binary
//
//  Created by Kyrylo Kastornov on 23.12.2023.
//
#include <iostream>
#include <bitset>

bool isBinary(const std::string& input)
{
    for (char c : input)
    {
        if (c != '0' && c != '1' && c != ' ' && c != '\n' && c != '\r')
        {
            return false;
        }
    }

    return true;
}

std::string binaryToText(const std::string& binaryCode)
{
    std::string result;

    std::string processedCode;
    for (char c : binaryCode)
    {
        if (c != ' ')
        {
            processedCode.push_back(c);
        }
    }

    if (processedCode.length() % 8 != 0)
    {
        std::cout << "Неправильна довжина бінарного коду.\n";
        return result;
    }

    for (size_t i = 0; i < processedCode.length(); i += 8)
    {
        std::bitset<8> bits(processedCode.substr(i, 8));
        result.push_back(static_cast<char>(bits.to_ulong()));
    }

    return result;
}


int main()
{
    std::string binaryCode;

    do
    {
        std::cout << "Введіть бінарний код: ";
        std::getline(std::cin, binaryCode);

        if (!isBinary(binaryCode))
        {
            std::cout << "Введені дані не є бінарним кодом. Повторіть введення.\n";
        }
    } while (!isBinary(binaryCode));

    std::string text = binaryToText(binaryCode);

    if (!text.empty())
    {
        std::cout << "Результат перекладу: " << text << "\n";
    }

    return 0;
}
