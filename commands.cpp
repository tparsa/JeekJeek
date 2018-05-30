#include "commands.hpp"

void Command::parse()
{
	std::string nextPiece = "";

	for (int i = 0; i < (int)cmd.size(); i++)
	{
		if(cmd[i] == ' ')
		{
			if(nextPiece.size() != 0)
				parsedCmd.push_back(nextPiece);
			nextPiece = "";
		}
		else nextPiece += cmd[i];
	}
	if((int)parsedCmd.size() == 0)
		throw NO_COMMAND_FOUND();
}

void Command::checkArgc()
{
	if(this->fewArgc())
		throw FEW_ARGUMENT();
	if(this->muchArgc())
		throw MUCH_ARGUMENT();
}