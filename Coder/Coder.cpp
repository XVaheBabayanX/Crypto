#include "Coder.h"

void Coder::Encode(const std::string& input, std::string& output)
{
	std::string transpose;
	transposition.Encrypt(input, transpose);
	rle.Encrypt(transpose, output);
}

void Coder::Decode(const std::string& input, std::string& output)
{
	std::string rlestring;
	rle.Decrypt(input, rlestring);
	transposition.Decrypt(rlestring, output);
	
}
