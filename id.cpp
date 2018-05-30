#include "id.hpp"

char ID::getNextChar(char ch)
{
	if(ch == 'Z')
		ch = 'a';
	else if(ch == 'z')
		ch = '0';
	else if(ch == '9')
		ch = 'A';
	else ch++;

	return ch;
}

std::string ID::lastID()
{
	std::ifstream fin;
	fin.open(LastIDFileName);
	if(fin == NULL)
		return "Ap0X";
	else 
	{
		std::string ret;
		fin >> ret;
		fin.close();
		return ((int)ret.size() != 0 ? ret : "Ap0X");
	}
}

void ID::changeLastID()
{
	std::ofstream fout;
	fout.open(LastIDFileName);
	fout << id << "\n";
	fout.close();
}

std::string ID::nextID(std::string id)
{
	int idx = 0;
	while(idx < (int)id.size())
	{
		id[idx] = getNextChar(id[idx]);
		if(id[idx] == 'A')
			idx++;
		else break;
	}
	if(idx == (int)id.size())
		id += 'A';
	return id;
}

ID::ID()
{
	srand(time(0));
	int numberOfForwardCycling = rand() % (rand() % randCONST);
	id = lastID();
	for (int i = 0; i < numberOfForwardCycling; i++)
		id = nextID(id);
	changeLastID();
}

void ID::print()
{
	printf("%s", id.c_str());
}