#pragma once
#include <vector>
#include <string>
#include "Crypto.h"

class LZ77 : public Crypto
{
private:
    int windowSize;
    int lookaheadBufferSize;

public:
    LZ77(int window = 4096, int lookahead = 18);

    void Encrypt(const std::vector<char>& input, std::vector<char>& output);
    void Decrypt(const std::vector<char>& input, std::vector<char>& output);

    void Encrypt(const std::string& input, std::string& output) override;
    void Decrypt(const std::string& input, std::string& output) override;

    struct Token {
        int offset;
        int length;
        char nextChar;
    };

    std::vector<Token> Compress(const std::vector<char>& input);
    std::vector<char> Decompress(const std::vector<Token>& tokens);
};
