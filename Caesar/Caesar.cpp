#include "Caesar.h"


CaesarCipher::CaesarCipher(int s) : shift(s)
{
    Key.resize(ASCII); 
    Shift(shift);
}

void CaesarCipher::Encrypt(const std::string& OriginalText, std::string& EncryptedText)
{
    int text_length = OriginalText.length();
    EncryptedText.resize(text_length);

    for (int i = 0; i < text_length; i++)
    {
        EncryptedText[i] = Key[static_cast<unsigned char>(OriginalText[i])];
    }
}

void CaesarCipher::Decrypt(const std::string& EncryptedText, std::string& DecryptedText)
{
    int text_length = EncryptedText.length();
    DecryptedText.resize(text_length);

    for (int i = 0; i < text_length; i++)
    {
        for (int j = 0; j < ASCII; j++)
        {
            if (EncryptedText[i] == Key[j])
            {
                DecryptedText[i] = static_cast<char>(j);
                break;
            }
        }
    }
}

void CaesarCipher::Shift(int shift)
{
    for (int i = 0; i < ASCII; i++)
    {
        Key[i] = static_cast<char>(i);
    }
    shift %= ASCII;
    std::rotate(Key.begin(), Key.begin() + (ASCII - shift), Key.end());
}
