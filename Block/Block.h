#pragma once
#include "Crypto.h"
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iterator>

class BlockCipher : public Crypto {
protected:
    std::string Key;
    size_t BlockLength;
    size_t BlockBytes;
    static const int BLOCKSIZE = 8;  
    static const int MAX_BINARY_LENGTH = 1600;
    static const int ASCII = 256;

    void XOR(const std::vector<int>& input, const std::vector<int>& key, std::vector<int>& output);
    void XOR(const std::vector<int>& input, const std::vector<int>& key, std::vector<int>& output, size_t StartIndex);
    void TextToBinary(const std::string& text, std::vector<int>& binary);
    std::string BinaryToText(const std::vector<int>& binary);
    std::string AdjustKeyLength(int targetLength);
    void CyclicLeftShift(std::vector<int>& block, int length);
    void CyclicRightShift(std::vector<int>& block, int length);

    template <typename Iterator>
    void CyclicLeftShift(Iterator blockStart, int length);

    template <typename Iterator>
    void CyclicRightShift(Iterator blockStart, int length);

public:
    BlockCipher();
    BlockCipher(const std::string& key);
    void setKey(const std::string& key);
    void setBlockLength();
    size_t getBlockLength() const;
    static const int getBLOCKSIZE();
    static std::string GenerateRandomKey(int length);
    static std::vector<int> GenerateRandomBinaryKey(int length);
    static std::vector<int> TextToBinary(const std::string& text);
};

template <typename Iterator>
void BlockCipher::CyclicLeftShift(Iterator blockStart, int length) {
    if (length > 1) {
        auto first = *blockStart;
        for (int i = 0; i < length - 1; ++i) {
            *(blockStart + i) = *(blockStart + i + 1);
        }
        *(blockStart + length - 1) = first;
    }
}

template <typename Iterator>
void BlockCipher::CyclicRightShift(Iterator blockStart, int length) {
    if (length > 1) {
        auto last = *(blockStart + length - 1);
        for (int i = length - 1; i > 0; --i) {
            *(blockStart + i) = *(blockStart + i - 1);
        }
        *blockStart = last;
    }
}
