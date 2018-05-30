#ifndef ID_HPP
#define ID_HPP

#include <string>
#include <fstream>
#include <cstdio>
#include <ctime>
#include <cstdlib>

#define LastIDFileName "~lstID"
const int randCONST = 19790;

class ID
{
private:
	std::string lastID();
	void changeLastID();
	char getNextChar(char ch);
	std::string nextID(std::string id);
	std::string id;

public:
	ID();
	void print();
};

#endif