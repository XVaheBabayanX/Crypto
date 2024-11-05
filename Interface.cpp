#include "Coder.h"
#include <iostream>

using namespace std;

int main() {
    size_t Key;
    string OriginalText, EncryptedText, DecryptedText;

    cout << "Input string: ";
    getline(cin, OriginalText);

    do {
        std::cout << "Input key Values( 1 - " << OriginalText.size() << " ) : ";
        std::cin >> Key;
    } while (Key > OriginalText.size() || Key <= 0);

    Coder coder(Key);

    cout << "\nOriginal string : ";
    cout << OriginalText;

    coder.Encode(OriginalText, EncryptedText);
    cout << "\nEncoded string : " << EncryptedText << endl;

    coder.Decode(EncryptedText, DecryptedText);
    cout << "\nDecoded string : " << DecryptedText << endl;

    return 0;
}
