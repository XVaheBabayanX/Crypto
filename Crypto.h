#pragma once

//Abstract base class  

class Crypto
{
public:
	virtual ~Crypto() = default;
	virtual int Encrypt();
	virtual int Decrypt();
};
