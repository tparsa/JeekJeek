#include "newJeek.hpp"

void NewJeek::changeText(const Command& cmdLine)
{
	for (int i = 1;;i++)
	{
		std::string nextPiece = cmdLine.getArg(i);
		if(nextPiece == "")
			break;
		if(i != 1)
			text += " ";
		text += nextPiece;
	}

	if(text.size() > 140)
		throw JEEK_TEXT_SIZE_EXCEEDED();
}

void NewJeek::addTag(const Command& cmdLine)
{
	hashTags.push_back(cmdLine.getArg(1));
}

void NewJeek::addMention(const Command& cmdLine)
{
	mentions.push_back(cmdLine.getArg(1));
}

void NewJeek::readJeek()
{
	std::string line;
	while(std::getline(std::cin, line))
	{
		Command cmdLine(line);
		std::string commandIdentity = cmdLine.getArg(0);
		if(commandIdentity == "text")
			changeText(cmdLine);
		else if(commandIdentity == "tag")
			addTag(cmdLine);
		else if(commandIdentity == "mention")
			addMention(cmdLine);
		else if(commandIdentity == "publish")
		{
			if((int)text.size() == 0)
				throw EMPTY_JEEK();
			else
			{
				publishTime = publishTime.presentTime();
				return;
			}
		}
		else if(commandIdentity == "abort")
		{
			jeekAborted = true;
			return;
		}
	}

}

void NewJeek::reJeek(const Jeek& jeek)
{
	text = "Rejeeked: " + jeek.getText();
	hashTags = jeek.getHashTags();
	mentions = jeek.getMentions();
}

Jeek NewJeek::getJeek(std::string username)
{
	if(jeekAborted == true)
		throw EXPECTING_PUBLISHING_ABORTED_JEEK();
	return Jeek(username, text, mentions, hashTags, publishTime);
}