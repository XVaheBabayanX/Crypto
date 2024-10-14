#pragma once
#include "Crypto.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

class StreamCipher : public Crypto
{
private:
    std::string Key;
    static const int ASCII = 256;

    void XOR(const std::vector<int>& input, const std::vector<int>& key, std::vector<int>& output);
    void TextToBinary(const std::string& text, std::vector<int>& binary);
    std::string BinaryToText(const std::vector<int>& binary);
    std::string AdjustKeyLength(int targetLength);

public:
    StreamCipher();
    StreamCipher(const std::string& key);
    void setKey(const std::string& key);
    void Encrypt(const std::string& input, std::string& output) override;
    void Decrypt(const std::string& input, std::string& output) override;
    static std::string GenerateRandomKey(int length);
};
