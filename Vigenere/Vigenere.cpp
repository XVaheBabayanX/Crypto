#include "Vigenere.h"
#include <stdexcept>
#include <algorithm>

char VigenereASCII::VigenereSquare[ASCII][ASCII] = {};
bool VigenereASCII::Generated = false;

VigenereASCII::VigenereASCII()
{
    GenerateVigenereSquare();
}

void VigenereASCII::CorrectText(const std::string& text)
{
    try
    {
        if (!isASCII(text)) throw std::runtime_error("None ASCII symbol(s) in Text"); 
    }
    catch (const std::exception& e)
    {
        std::cerr << "CorrectText() failed : " << e.what() << std::endl;
    }
}

void VigenereASCII::setKey(const std::string& key)
{
    std::string modifiedKey = key;
    try
    {
        if (isASCII(modifiedKey))
        {
            removeDuplicates(modifiedKey);
            Key = modifiedKey;
        }
        else throw std::runtime_error("None ASCII symbol(s) in Key");
    }
    catch (const std::exception& e)
    {
        std::cerr << "setKey() failed : " << e.what() << std::endl;
    }
}

void VigenereASCII::removeDuplicates(std::string& text)
{
    std::string temp;
    for (char c : text)
    {
        if (temp.find(c) == std::string::npos)
            temp += c;
    }
    text = temp;
}

void VigenereASCII::Encrypt(const std::string& input, std::string& output)
{
    CorrectText(input);
    output.clear();
    size_t keyIndex = 0;
    char StartASCII = 0;
    for (char c : input)
    {
        char textChar = c - StartASCII;
        char keyChar = Key[keyIndex % Key.size()] - StartASCII;  
        output += VigenereSquare[textChar][keyChar];
        keyIndex++;
    }
}

void VigenereASCII::Decrypt(const std::string& input, std::string& output)
{
    output.clear();
    size_t keyIndex = 0;
    char StartASCII = 0;

    for (char c : input)
    {
        char codedChar = c - StartASCII;
        char keyChar = Key[keyIndex % Key.size()] - StartASCII;
        int originalChar = (codedChar - keyChar + ASCII) % ASCII;
        output += StartASCII + originalChar;
        keyIndex++;
    }
}

void VigenereASCII::GenerateVigenereSquare()
{
    if (Generated) return;

    int Shift = 0;
    std::string TempRow;
    for (int i = 0; i < ASCII; i++)
    {
        TempRow.clear();  
        for (int j = 0; j < ASCII; j++)
        {
            TempRow += static_cast<char>(j);  
        }
        std::rotate(TempRow.begin(), TempRow.begin() + Shift, TempRow.end());
        for (int j = 0; j < ASCII; j++)
        {
            VigenereSquare[i][j] = TempRow[j]; 
        }
        Shift++;  
    }

    Generated = true;
}

void VigenereASCII::printVigenereSquare()
{
    for (int i = 0; i < ASCII; ++i)
    {
        for (int j = 0; j < ASCII; ++j)
        {
            std::cout << VigenereSquare[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool VigenereASCII::isASCII(const std::string& text)
{
    return std::all_of(text.begin(), text.end(), [](unsigned char c) 
    {
        return c >= 0 && c < ASCII; 
    });
}
