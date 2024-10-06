#pragma once
#include "Block.h"

class ECBCipher : public BlockCipher {
public:
    ECBCipher() : BlockCipher() {};
    ECBCipher(const std::string& key) : BlockCipher(key) {}

    void Encrypt(const std::string& input, std::string& output) override;
    void Decrypt(const std::string& input, std::string& output) override;
};
