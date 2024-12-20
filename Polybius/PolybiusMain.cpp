#include "Polybius.h"
#include <iostream>

using namespace std;

int main()
{
    string text, key;

    cout << "Input text: ";
    getline(cin, text);

    cout << "Input key: ";
    getline(cin, key);

    Polybius cipher(key);

    string encryptedText;
    cipher.Encrypt(text, encryptedText);
    cout << "\nEncrypted: " << encryptedText << endl;

    string decryptedText;
    cipher.Decrypt(encryptedText, decryptedText);
    cout << "Decrypted: " << decryptedText << endl;

    cipher.printPolybiusSquare();

    return 0;
}
