#include "Block.h"

BlockCipher::BlockCipher() : BlockCipher(GenerateRandomKey(BLOCKSIZE)) {}

BlockCipher::BlockCipher(const std::string& key)
{
    setKey(key);
}

void BlockCipher::setKey(const std::string& key)
{
    Key = key;
    setBlockLength();
}

void BlockCipher::setBlockLength()
{
    BlockLength = (Key.size()) * BLOCKSIZE;
    BlockBytes = BlockLength / BLOCKSIZE;
}

void BlockCipher::XOR(const std::vector<int>& input, const std::vector<int>& key, std::vector<int>& output)
{
    for (size_t i = 0; i < input.size(); ++i)
    {
        output[i] = input[i] ^ key[i];
    }
}

void BlockCipher::XOR(const std::vector<int>& input, const std::vector<int>& key, std::vector<int>& output, size_t StartIndex)
{
    size_t keySize = key.size();
    for (size_t i = 0; i < BlockLength; ++i)
    {
        output[StartIndex + i] = input[StartIndex + i] ^ key[i % keySize];
    }
}

void BlockCipher::TextToBinary(const std::string& text, std::vector<int>& binary) {
    for (unsigned char c : text) {
        for (int j = 7; j >= 0; --j) {
            binary.push_back((c >> j) & 1);
        }
    }
}

std::string BlockCipher::BinaryToText(const std::vector<int>& binary) {
    std::string text;
    for (size_t i = 0; i < binary.size(); i += 8) {
        unsigned char character = 0;
        for (int j = 0; j < 8; ++j) {
            character = (character << 1) | binary[i + j];
        }
        text += character;
    }
    return text;
}

std::string BlockCipher::AdjustKeyLength(int targetLength) {
    std::string adjustedKey = Key;
    while (adjustedKey.size() < targetLength) {
        adjustedKey += Key;
    }
    return adjustedKey.substr(0, targetLength);
}

void BlockCipher::CyclicLeftShift(std::vector<int>& block, int length) {
    if (length > 1) {
        int first = block[0];  
        for (int i = 0; i < length - 1; ++i) {
            block[i] = block[i + 1];  
        }
        block[length - 1] = first;  
    }
}

void BlockCipher::CyclicRightShift(std::vector<int>& block, int length) {
    if (length > 1) {
        int last = block[length - 1];
        for (int i = length - 1; i > 0; --i) {
            block[i] = block[i - 1];
        }
        block[0] = last;
    }
}

const int BlockCipher::getBLOCKSIZE()
{
    return BLOCKSIZE;
}

size_t BlockCipher::getBlockLength() const
{
    return BlockLength;
}

std::string BlockCipher::GenerateRandomKey(int length)
{
    srand(static_cast<unsigned int>(time(0)));
    std::string key;
    for (int i = 0; i < length; ++i)
    {
        key += static_cast<char>(rand() % ASCII);
    }
    return key;
}

std::vector<int> BlockCipher::GenerateRandomBinaryKey(int length)
{
    srand(static_cast<unsigned int>(time(0)));
    std::vector<int> binaryKey;
    for (int i = 0; i < length; ++i)
    {
        binaryKey.push_back(static_cast<char>(rand() % 2));
    }
    return binaryKey;
}

std::vector<int> BlockCipher::TextToBinary(const std::string& text) {
    std::vector<int> textBinary;
    for (char c : text) {
        for (int j = 7; j >= 0; --j) {
            textBinary.push_back((c >> j) & 1);
        }
    }
    return textBinary;
}
