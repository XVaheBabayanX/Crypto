#include "Caesar.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int shift;
    string OriginalText, EncryptedText, DecryptedText;

    cout << "Input ASCII Shift : ";
    cin >> shift;

    CaesarCipher cipher(shift);

    cout << "\nEnter original text : ";
    cin.ignore();
    getline(cin, OriginalText);

    cipher.Encrypt(OriginalText, EncryptedText);
    cipher.Decrypt(EncryptedText, DecryptedText);

    cout << endl;
    cout << "Original Text  : " << OriginalText << endl;
    cout << "Encrypted Text : " << EncryptedText << endl;
    cout << "Decrypted Text : " << DecryptedText << endl;

    return 0;
}
