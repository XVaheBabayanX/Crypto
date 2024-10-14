#pragma once
#include <string>
#include <iostream>
#include <cctype>
#include "Crypto.h"

class VigenereASCII : public Crypto
{
public:
    VigenereASCII();

    void Encrypt(const std::string& input, std::string& output) override;
    void Decrypt(const std::string& input, std::string& output) override;

    void CorrectText(const std::string& text);
    void setKey(const std::string& key);

    static void GenerateVigenereSquare();
    void printVigenereSquare();

private:
    static const int ASCII = 256;
    static bool Generated;
    static char VigenereSquare[ASCII][ASCII];

    std::string Key;
    
    void removeDuplicates(std::string& text);
    bool isASCII(const std::string& text);
};
