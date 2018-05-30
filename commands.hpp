#ifndef COMMANDS__HPP
#define COMMANDS__HPP

#include <string>
#include <vector>
#include "user.hpp"

#define UNKOWNDISPLAYNAME ""

enum CommandsArgc { SIGNUPARGC = 4, LOGINARGC = 3 };

class COMMAND_EXEPTIONS {};

class NO_COMMAND_FOUND : public COMMAND_EXEPTIONS {};

class FEW_ARGUMENT : public COMMAND_EXEPTIONS {};

class MUCH_ARGUMENT : public COMMAND_EXEPTIONS {};

class Command
{
private:
	void parse();

protected:
	std::string cmd;
	std::vector<std::string> parsedCmd;
	void checkArgc();
	virtual bool fewArgc() { return false; }
	virtual bool muchArgc() { return false; }


public:
	Command(std::string _cmd) : cmd(_cmd) { parse(); checkArgc(); }
	std::string getArg(int idx) const
	{
		if(idx >= (int)parsedCmd.size())
			return "";
		return parsedCmd[idx];
	}
};

class SingUpCommand : private Command
{
private:
	bool fewArgc() { return ((int)parsedCmd.size() < SIGNUPARGC); }
	bool muchArgc() {return ((int)parsedCmd.size() > SIGNUPARGC); }
public:
	SingUpCommand(std::string _cmd) : Command(_cmd) {};
	User* registeringUser() { return new User(parsedCmd[1], parsedCmd[2], parsedCmd[3]); }
};

class LoginCommand : private Command
{
private:
	bool fewArgc() { return ((int)parsedCmd.size() < LOGINARGC); }
	bool muchArgc(){ return ((int)parsedCmd.size() > LOGINARGC); }
public:
	LoginCommand(std::string _cmd) : Command(_cmd) {};
	User* LogedInUser() { return new User(parsedCmd[1], UNKOWNDISPLAYNAME, parsedCmd[2]); }
};

#endif