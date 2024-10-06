#include "Vigenere.h"
#include <iostream>

using namespace std;

int main()
{
    string text, key;

    cout << "Input text: ";
    getline(cin, text);

    cout << "Input key: ";
    getline(cin, key);

    VigenereASCII cipher;  

    cipher.setKey(key); 

    string encryptedText;
    cipher.Encrypt(text, encryptedText); 
    cout << "\nEncrypted: " << encryptedText << endl;

    string decryptedText;
    cipher.Decrypt(encryptedText, decryptedText);  
    cout << "Decrypted: " << decryptedText << endl;

    return 0;
}
