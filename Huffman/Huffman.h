#pragma once

#include <string>
#include <unordered_map>
#include <D:\\Visual Studio\\С++\\ProgSystemDefending\\CryptoClasses\\Crypto.h>

class Huffman : public Crypto {
private:
    struct Node {
        char ch;
        int freq;
        Node* left;
        Node* right;

        Node(char c, int f);
    };

    struct Compare {
        bool operator()(Node* left, Node* right);
    };

    std::unordered_map<char, std::string> huffmanCode;
    std::unordered_map<std::string, char> reverseHuffmanCode;

    void buildHuffmanTree(const std::string& input);
    void generateCodes(Node* root, const std::string& str);
    void generateReverseCodes();

public:
    void Encrypt(const std::string& input, std::string& output) override;
    void Decrypt(const std::string& input, std::string& output) override;
};
