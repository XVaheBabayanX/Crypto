#include "SimpleSubstitution.h"
#include <iostream>
#include <string>

int main()
{
    SimpleSubstitutionCipher cipher;
    std::string OriginalText, EncryptedText, DecryptedText;

    std::cout << "Enter original text: ";
    std::getline(std::cin, OriginalText);

    cipher.Encrypt(OriginalText, EncryptedText);
    cipher.Decrypt(EncryptedText, DecryptedText);

    std::cout << std::endl;
    std::cout << "Original Text  : " << OriginalText << std::endl;
    std::cout << "Encrypted Text : " << EncryptedText << std::endl;
    std::cout << "Decrypted Text : " << DecryptedText << std::endl;

    return 0;
}
