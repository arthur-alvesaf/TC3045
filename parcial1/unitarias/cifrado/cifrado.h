#pragma once
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

class Cifrado
{
public:
	Cifrado() {}
	~Cifrado() {}
	virtual int decrypt(string word) = 0;
};