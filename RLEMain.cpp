#include "RLE.h"
#include <iostream>

using namespace std;

int main() {
    RLE rle;
    string OriginalText, EncryptedText, DecryptedText;

    cout << "Input string: ";
    getline(cin, OriginalText);  

    cout << "Original string:\n";
    rle.printHex(OriginalText);  

    rle.Encrypt(OriginalText, EncryptedText);
    cout << "\nEncoded string:\n" << EncryptedText << endl;

    rle.Decrypt(EncryptedText, DecryptedText);
    cout << "\nDecoded string:\n" << DecryptedText << endl;

    return 0;
}
