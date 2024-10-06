#include <iostream>
#include "Stream.h"

int main() {
    StreamCipher streamCipher; 

    std::string Key;
    std::string Plaintext = "Hello, Stream Cipher!";
    std::string Encrypted;
    std::string Decrypted;

    std::cout << "\nEnter Plain text : ";
    std::getline(std::cin, Plaintext);

    std::cout << "Input key (leave empty for random key): ";
    std::getline(std::cin, Key);

    if (Key.empty()) {
        Key = StreamCipher::GenerateRandomKey(Plaintext.size());
        std::cout << "Generated random key: " << Key << std::endl;
    }

    streamCipher.setKey(Key);

    streamCipher.Encrypt(Plaintext, Encrypted);
    std::cout << "Encrypted (Stream): " << Encrypted << std::endl;

    streamCipher.Decrypt(Encrypted, Decrypted);
    std::cout << "Decrypted (Stream): " << Decrypted << std::endl;

    return 0;
}
