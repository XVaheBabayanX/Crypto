#pragma once

#include "Crypto.h"
#include <vector>
#include <string>

class RLE : public Crypto {
private:
    const int MARKER = 255;
    std::vector<int> Encoded;

public:
    void Encrypt(const std::string& input, std::string& output) override;
    void Decrypt(const std::string& input, std::string& output) override;

    void printHex(const std::string& data);
};
