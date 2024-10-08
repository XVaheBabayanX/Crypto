#include <iostream>
#include "ECB.h"
#include "CBC.h"

int main() {
    ECBCipher ecb;
    CBCCipher cbc;
    std::string PlainText;
    std::string EncryptedText, DecryptedText;
    std::string Key;
    int KeyLength = 0;

    std::cout << "\nEnter Plain text : ";
    std::getline(std::cin, PlainText);


    do{
        std::cout << "Input key (leave empty for random key) length( 1 - " << PlainText.size() << " ) : ";
        std::getline(std::cin, Key);
    } while (Key.size() > PlainText.size());

    if (Key.empty()) {
        while (KeyLength <= 0 || KeyLength > PlainText.size())
        {
            std::cout << "Input Key length( 1 - " << PlainText.size() <<" ) : ";
            std::cin >> KeyLength;
        }
        Key = BlockCipher::GenerateRandomKey(KeyLength);
        std::cout << "Generated random key: " << Key << std::endl;
    }

    if (Key.empty()) {
        std::cerr << "Key cannot be empty." << std::endl;
        return 1;
    }

    ecb.setKey(Key);
    cbc.setKey(Key);
    std::vector<int> PlainBinary = BlockCipher::TextToBinary(PlainText);
    std::cout << "\nThe Binary of Plain : \n";
    for (int i = 0; i < PlainBinary.size(); i++)
    {
        std::cout << PlainBinary[i];
    }
    std::cout << std::endl;

    std::cout << "Plain : " << PlainText << std::endl;

    try {
        ecb.Encrypt(PlainText, EncryptedText);
        std::cout << "ECB Encrypted: " << EncryptedText << std::endl;
        std::vector<int> EncryptedBinary = BlockCipher::TextToBinary(EncryptedText);
        std::cout << "\nThe Binary of ECB Encrypted : \n";
        for (int i = 0; i < EncryptedBinary.size(); i++)
        {
            std::cout << EncryptedBinary[i];
        }
        std::cout << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error occurred in ECB Encrypt." << std::endl;
    }

    try {
        ecb.Decrypt(EncryptedText, DecryptedText);
        std::cout << "ECB Decrypted: " << DecryptedText;
        std::vector<int> DecryptedBinary = BlockCipher::TextToBinary(DecryptedText);
        std::cout << "\nThe Binary of ECB Decrypted : \n";
        for (int i = 0; i < DecryptedBinary.size(); i++)
        {
            std::cout << DecryptedBinary[i];
        }
        std::cout << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error occurred in ECB Decrypt." << std::endl;
    }

    try {
        std::vector<int> EncryptedBinary = BlockCipher::TextToBinary(EncryptedText);
        cbc.Encrypt(PlainText, EncryptedText);
        EncryptedBinary = BlockCipher::TextToBinary(EncryptedText);
        std::cout << "\nThe Binary of CBC Encrypted : \n";
        for (int i = 0; i < EncryptedBinary.size(); i++)
        {
            std::cout << EncryptedBinary[i];
        }
        std::cout << std::endl;
        std::cout << "CBC Encrypted: " << EncryptedText << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error occurred in CBC Encrypted." << std::endl;
    }

    try {
        std::vector<int> DecryptedBinary = BlockCipher::TextToBinary(DecryptedText);
        cbc.Decrypt(EncryptedText, DecryptedText);
        DecryptedBinary = BlockCipher::TextToBinary(DecryptedText);
        std::cout << "\nThe Binary of CBC Decrypted : \n";
        for (int i = 0; i < DecryptedBinary.size(); i++)
        {
            std::cout << DecryptedBinary[i];
        }
        std::cout << std::endl;
        std::cout << "CBC Decrypted: " << DecryptedText << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error occurred in CBC Decrypt." << std::endl;
    }

    return 0;
}
