#include "CBC.h"

void CBCCipher::Encrypt(const std::string& input, std::string& output)
{
    std::vector<int> BinaryInput, BinaryOutput, BinaryKey, PreviousBlock;
    TextToBinary(Key, BinaryKey);
    TextToBinary(input, BinaryInput);

    BinaryOutput.resize(BinaryInput.size());

    PreviousBlock = std::vector<int>(BinaryKey.size(), 0);

    for (size_t i = 0; i < BinaryInput.size(); i += BlockBytes)
    {
        size_t remainingBytes = std::min(BlockBytes, BinaryInput.size() - i);
        std::vector<int> CurrentBlock(BinaryInput.begin() + i, BinaryInput.begin() + i + remainingBytes);

        for (size_t j = 0; j < remainingBytes; ++j) {
            CurrentBlock[j] ^= PreviousBlock[j];
        }

        for (size_t j = 0; j < remainingBytes; ++j) {
            CurrentBlock[j] ^= BinaryKey[j % BinaryKey.size()];
        }

        CyclicLeftShift(CurrentBlock, remainingBytes);

        std::copy(CurrentBlock.begin(), CurrentBlock.end(), BinaryOutput.begin() + i);
        PreviousBlock = CurrentBlock;
    }

    output = BinaryToText(BinaryOutput);
}


void CBCCipher::Decrypt(const std::string& input, std::string& output)
{
    std::vector<int> BinaryInput, BinaryOutput, BinaryKey, PreviousBlock;
    TextToBinary(Key, BinaryKey);
    TextToBinary(input, BinaryInput);

    BinaryOutput.resize(BinaryInput.size());

    PreviousBlock = std::vector<int>(BinaryKey.size(), 0);

    for (size_t i = 0; i < BinaryInput.size(); i += BlockBytes) {
        size_t remainingBytes = std::min(BlockBytes, BinaryInput.size() - i);

        std::vector<int> CurrentBlock(BinaryInput.begin() + i, BinaryInput.begin() + i + remainingBytes);
        std::vector<int> CurrentBlockCopy = CurrentBlock;

        CyclicRightShift(CurrentBlock, remainingBytes);

        for (size_t j = 0; j < remainingBytes; ++j) {
            CurrentBlock[j] ^= BinaryKey[j % BinaryKey.size()];
        }

        for (size_t j = 0; j < remainingBytes; ++j) {
            CurrentBlock[j] ^= PreviousBlock[j];
        }

        std::copy(CurrentBlock.begin(), CurrentBlock.end(), BinaryOutput.begin() + i);
        PreviousBlock = CurrentBlockCopy;
    }

    output = BinaryToText(BinaryOutput);
}

