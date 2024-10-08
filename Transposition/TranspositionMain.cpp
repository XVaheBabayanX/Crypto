#include <iostream>
#include "Transposition.h"

int main() {
    Transposition cipher;
    std::string PlainText;
    std::string EncryptedText, DecryptedText;
    size_t Key;

    std::cout << "\nEnter Plain text : ";
    std::getline(std::cin, PlainText);

    do {
        std::cout << "Input key (0 for random key) Values( 1 - " << PlainText.size() << " ) : ";
        std::cin >> Key;
    } while (Key > PlainText.size());

    if (Key == 0) {
        Key = cipher.GenerateRandomKey(PlainText.size());
        std::cout << "Generated random key: " << Key << std::endl;
    }

    if (Key == 0) {
        std::cerr << "Key cannot be 0." << std::endl;
        return 1;
    }

    cipher.setKey(Key);
    std::cout << "Plain : " << PlainText << std::endl;

    try {
        cipher.Encrypt(PlainText, EncryptedText);
        std::cout << "Transposition Encrypted: " << EncryptedText << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error occurred in Transposition Encrypt." << std::endl;
    }

    try {
        cipher.Decrypt(EncryptedText, DecryptedText);
        std::cout << "Transposition Decrypted: " << DecryptedText;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error occurred in Transposition Decrypt." << std::endl;
    }

    return 0;
}
