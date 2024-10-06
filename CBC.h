#pragma once
#include "Block.h"

class CBCCipher : public BlockCipher {
public:
    CBCCipher() : BlockCipher(), IV(BlockCipher::GenerateRandomBinaryKey(BLOCKSIZE)) {}
    CBCCipher(const std::string& key) : BlockCipher(key), IV(BlockCipher::GenerateRandomBinaryKey(BLOCKSIZE)) {}

    void Encrypt(const std::string& input, std::string& output) override;
    void Decrypt(const std::string& input, std::string& output) override;

private:
    std::vector<int> IV; 
};
