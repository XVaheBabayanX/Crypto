#pragma once

#include <string>
#include <algorithm>
//Abstract base class  

class Crypto
{
public:
    virtual void Encrypt(const std::string& input, std::string& output) = 0;
    virtual void Decrypt(const std::string& input, std::string& output) = 0;
    virtual ~Crypto() = default;
};
