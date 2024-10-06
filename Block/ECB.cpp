#include "ECB.h"

void ECBCipher::Encrypt(const std::string& input, std::string& output)
{
    std::vector<int> BinaryInput, BinaryOutput, BinaryKey;

    TextToBinary(Key, BinaryKey);
    TextToBinary(input, BinaryInput);

    BinaryOutput.resize(BinaryInput.size());

    size_t TotalBlocks = (BinaryInput.size() + BlockBytes - 1) / BlockBytes;

    for (size_t i = 0; i < TotalBlocks; ++i)
    {
        size_t blockOffset = i * BlockBytes;
        size_t remainingBytes = std::min(BlockBytes, BinaryInput.size() - blockOffset);

        for (size_t j = 0; j < remainingBytes; ++j)
        {
            BinaryOutput[blockOffset + j] = BinaryInput[blockOffset + j] ^ BinaryKey[j % BinaryKey.size()];
        }

        std::vector<int>::iterator blockStart = BinaryOutput.begin() + blockOffset;
        CyclicLeftShift(blockStart, remainingBytes);
    }


    output = BinaryToText(BinaryOutput);
}

void ECBCipher::Decrypt(const std::string& input, std::string& output)
{
    std::vector<int> BinaryInput, BinaryOutput, BinaryKey;

    TextToBinary(Key, BinaryKey);
    TextToBinary(input, BinaryInput);

    BinaryOutput.resize(BinaryInput.size());

    size_t TotalBlocks = (BinaryInput.size() + BlockBytes - 1) / BlockBytes;

    for (size_t i = 0; i < TotalBlocks; ++i)
    {
        size_t blockOffset = i * BlockBytes;
        size_t remainingBytes = std::min(BlockBytes, BinaryInput.size() - blockOffset);

        std::vector<int>::iterator blockStart = BinaryInput.begin() + blockOffset;
        CyclicRightShift(blockStart, remainingBytes);

        for (size_t j = 0; j < remainingBytes; ++j)
        {
            BinaryOutput[blockOffset + j] = BinaryInput[blockOffset + j] ^ BinaryKey[j % BinaryKey.size()];
        }
    }

    output = BinaryToText(BinaryOutput);
}



// Without Cycle Shifts
//void ECBCipher::Encrypt(const std::string& input, std::string& output)
//{
//    std::vector<int> BinaryInput, BinaryOutput, BinaryKey;
//
//    TextToBinary(Key, BinaryKey);
//    TextToBinary(input, BinaryInput);
//
//    BinaryOutput.resize(BinaryInput.size());
//
//    for (size_t i = 0; i < BinaryInput.size(); ++i) {
//        BinaryOutput[i] = BinaryInput[i] ^ BinaryKey[i % BinaryKey.size()];
//    }
//
//    output = BinaryToText(BinaryOutput);
//}
//
//void ECBCipher::Decrypt(const std::string& input, std::string& output)
//{
//    Encrypt(input, output);
//}
