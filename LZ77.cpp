#include "LZ77.h"
#include <sstream>
#include <iostream>

LZ77::LZ77(int window, int lookahead) : windowSize(window), lookaheadBufferSize(lookahead) {}

void LZ77::Encrypt(const std::vector<char>& input, std::vector<char>& output)
{
    std::vector<Token> tokens = Compress(input);

    for (const auto& token : tokens) {
        output.push_back((char)token.offset);
        output.push_back((char)token.length);
        output.push_back(token.nextChar);
    }
}

void LZ77::Decrypt(const std::vector<char>& input, std::vector<char>& output)
{
    std::vector<Token> tokens;
    for (size_t i = 0; i < input.size(); i += 3) {
        int offset = (unsigned char)input[i];  
        int length = (unsigned char)input[i + 1];
        char nextChar = input[i + 2];
        tokens.push_back({ offset, length, nextChar });
    }

    output = Decompress(tokens);
}

void LZ77::Encrypt(const std::string& input, std::string& output) {
    std::vector<char> inputVec(input.begin(), input.end());
    std::vector<char> outputVec;
    Encrypt(inputVec, outputVec);
    output.assign(outputVec.begin(), outputVec.end());
}

void LZ77::Decrypt(const std::string& input, std::string& output) {
    std::vector<char> inputVec(input.begin(), input.end());
    std::vector<char> outputVec;
    Decrypt(inputVec, outputVec);
    output.assign(outputVec.begin(), outputVec.end());
}

std::vector<LZ77::Token> LZ77::Compress(const std::vector<char>& input)
{
    std::vector<Token> tokens;
    int pos = 0;

    while (pos < input.size()) {
        int bestLength = 0;
        int bestOffset = 0;
        char nextChar = input[pos];

        int searchStart = std::max(0, pos - windowSize);
        for (int i = searchStart; i < pos; ++i) {
            int length = 0;
            while (length < lookaheadBufferSize && pos + length < input.size() &&
                input[i + length] == input[pos + length]) {
                ++length;
            }
            if (length > bestLength) {
                bestLength = length;
                bestOffset = pos - i;
                if (pos + length < input.size()) {
                    nextChar = input[pos + length];
                }
                else {
                    nextChar = '\0';
                }
            }
        }

        tokens.push_back({ bestOffset, bestLength, nextChar });
        pos += bestLength + 1;
    }

    return tokens;
}

std::vector<char> LZ77::Decompress(const std::vector<Token>& tokens)
{
    std::vector<char> output;
    for (const auto& token : tokens) {
        if (token.offset == 0 && token.length == 0) {
            output.push_back(token.nextChar);
        }
        else {
            int start = output.size() - token.offset;
            for (int i = 0; i < token.length; ++i) {
                output.push_back(output[start + i]);
            }
            output.push_back(token.nextChar);
        }
    }
    return output;
}
