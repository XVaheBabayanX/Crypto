#include <iostream>
#include "Stream.h"

StreamCipher::StreamCipher() {}

StreamCipher::StreamCipher(const std::string& key) : Key(key) {}

void StreamCipher::setKey(const std::string& key)
{
    Key = key;
}

void StreamCipher::XOR(const std::vector<int>& input, const std::vector<int>& key, std::vector<int>& output)
{
    for (size_t i = 0; i < input.size(); ++i)
    {
        output[i] = input[i] ^ key[i];
    }
}

void StreamCipher::TextToBinary(const std::string& text, std::vector<int>& binary)
{
    for (char c : text)
    {
        for (int j = 7; j >= 0; --j)
        {
            binary.push_back((c >> j) & 1);
        }
    }
}

std::string StreamCipher::BinaryToText(const std::vector<int>& binary)
{
    std::string text;
    int charCode = 0;
    for (size_t i = 0; i < binary.size(); i += 8)
    {
        for (int j = 0; j < 8; ++j)
        {
            charCode = (charCode << 1) | binary[i + j];
        }
        text += static_cast<char>(charCode);
        charCode = 0;
    }
    return text;
}

std::string StreamCipher::AdjustKeyLength(int targetLength) {
    std::string adjustedKey = Key;
    while (adjustedKey.size() < targetLength) {
        adjustedKey += Key;
    }
    return adjustedKey.substr(0, targetLength);
}

void StreamCipher::Encrypt(const std::string& input, std::string& output)
{
    std::string adjustedKey = AdjustKeyLength(input.size());
    std::vector<int> binaryInput, binaryKey, binaryOutput(input.size() * 8);
    TextToBinary(input, binaryInput);
    TextToBinary(adjustedKey, binaryKey);
    XOR(binaryInput, binaryKey, binaryOutput);
    output = BinaryToText(binaryOutput);
}

void StreamCipher::Decrypt(const std::string& input, std::string& output)
{
    Encrypt(input, output);  
}

std::string StreamCipher::GenerateRandomKey(int length)
{
    srand(static_cast<unsigned int>(time(0)));
    std::string key;
    for (int i = 0; i < length; ++i) 
    {
        key += static_cast<char>(rand() % ASCII);
    }
    return key;
}
