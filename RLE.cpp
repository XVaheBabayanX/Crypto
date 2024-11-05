#include "RLE.h"
#include <iostream>
#include <iomanip>
#include <sstream>

void RLE::Encrypt(const std::string& input, std::string& output) {
    Encoded.clear();
    int count;

    for (size_t i = 0; i < input.size(); i++) {
        int number = static_cast<int>(input[i]);
        count = 1;

        while (i < (input.size() - 1) && input[i] == input[i + 1]) {
            count++;
            i++;
        }

        if (count > 1) {
            Encoded.push_back(MARKER);
            Encoded.push_back(count);
        }

        if (number == MARKER) {
            Encoded.push_back(MARKER);
            Encoded.push_back(MARKER);
        }
        else {
            Encoded.push_back(number);
        }
    }

    std::stringstream ss;
    for (size_t i = 0; i < Encoded.size(); i++) {
        ss << std::uppercase << std::hex << std::setw(2) << std::setfill('0') << Encoded[i] << " ";
    }
    output = ss.str();
}

void RLE::Decrypt(const std::string& input, std::string& output) {
    std::stringstream ss(input);
    int value;
    Encoded.clear();

    while (ss >> std::hex >> value) {
        Encoded.push_back(value);
    }

    output.clear();
    for (size_t i = 0; i < Encoded.size(); i++) {
        if (Encoded[i] == MARKER) {
            int count = Encoded[++i];
            int number = Encoded[++i];
            for (int j = 0; j < count; j++) {
                output += static_cast<char>(number);
            }
        }
        else if (Encoded[i] == MARKER && Encoded[i + 1] == MARKER) {
            output += static_cast<char>(MARKER);
            i++;
        }
        else {
            output += static_cast<char>(Encoded[i]);
        }
    }
}

void RLE::printHex(const std::string& data) {
    for (size_t i = 0; i < data.size(); i++) {
        std::cout << std::uppercase << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(data[i]) << " ";
    }
    std::cout << std::endl;
}
