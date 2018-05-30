#ifndef NEWJEEK_HPP
#define NEWJEEK_HPP

#include <string>
#include <vector>
#include "jeek.hpp"
#include "commands.hpp"

class NewJeek
{
private:
	bool jeekAborted;
	std::string text;
	std::vector<std::string> mentions;
	std::vector<std::string> hashTags;
	TimeAndDate publishTime;
	void changeText(const Command& cmdLine);
	void addTag(const Command& cmdLine);
	void addMention(const Command& cmdLine);

public:
	NewJeek() : jeekAborted(false) {}
	void readJeek();
	void reJeek(const Jeek& jeek);
	Jeek getJeek(std::string username);
};

#endif