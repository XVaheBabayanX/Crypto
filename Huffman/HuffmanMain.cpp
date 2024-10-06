#include "Huffman.h"
#include <iostream>

using namespace std;

int main() {
    Huffman huffman;
    string OriginalText, EncryptedText, DecryptedText;

    cout << "\nEnter original text : ";
    getline(cin, OriginalText);

    huffman.Encrypt(OriginalText, EncryptedText);
    cout << "Encrypted: " << EncryptedText << endl;

    huffman.Decrypt(EncryptedText, DecryptedText);
    cout << "Decrypted: " << DecryptedText << endl;

    return 0;
}
