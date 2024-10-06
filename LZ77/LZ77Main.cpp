#include <iostream>
#include <vector>
#include <string>
#include "LZ77.h"

int main()
{
    LZ77 lz77;

    std::string inputString;
    std::cout << "Enter the data to compress: ";
    std::getline(std::cin, inputString);

    std::vector<char> input(inputString.begin(), inputString.end());
    std::vector<char> compressed;
    std::vector<char> decompressed;

    lz77.Encrypt(input, compressed);
    std::cout << "Compressed data:" << std::endl;
    for (char c : compressed) {
        std::cout << (int)(unsigned char)c << " ";
    }
    std::cout << std::endl;

    for (size_t i = 0; i < compressed.size(); i += 3) {
        int offset = (unsigned char)compressed[i];
        int length = (unsigned char)compressed[i + 1];
        char symbol = compressed[i + 2];

        std::cout << "(" << offset << "," << length << "," << symbol << ")";
    }
    std::cout << std::endl;

    lz77.Decrypt(compressed, decompressed);
    std::cout << "Decompressed data: ";
    for (char c : decompressed) {
        std::cout << c;
    }
    std::cout << std::endl;

    return 0;
}
