#pragma once

#include "Transposition.h"
#include "RLE.h"

class Coder
{
public:
	Coder();
	Coder(size_t key) : transposition(key) {}
	void Encode(const std::string& input, std::string& output);
	void Decode(const std::string& input, std::string& output);
private:
	RLE rle;
	Transposition transposition;
};
