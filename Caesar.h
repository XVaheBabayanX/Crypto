#pragma 

#include <D:\\Visual Studio\\С++\\ProgSystemDefending\\CryptoClasses\\Crypto.h>

class CaesarCipher : public Crypto
{
private:
    std::string Key;
    int shift;
    static const int ASCII = 256; 

public:
    CaesarCipher(int s);

    void Encrypt(const std::string& OriginalText, std::string& EncryptedText) override;
    void Decrypt(const std::string& EncryptedText, std::string& DecryptedText) override;

private:
    void Shift(int shift);
};