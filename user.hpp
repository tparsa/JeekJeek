#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <vector>
#include <algorithm>
#include "jeek.hpp"
#include "event.hpp"
#include "id.hpp"

class User
{
private:
	std::string username;
	std::string password;
	std::string displayName;
	std::vector<ID> mentionedJeeks;
	std::vector<ID> jeeks;
	std::vector<std::string> followings;
	TimeAndDate lastNotificationCheck;
public:
	User(std::string _username, std::string _displayName, std::string _password) : username(_username), displayName(_displayName),
	password(_password) {}

	void mentioned(ID jeekID) {mentionedJeeks.push_back(jeekID);}
	void follow(std::string followingUsername);
	TimeAndDate getLastNotifiCheck() { return lastNotificationCheck; }

	bool operator==(const User& secondUser) const
	{
		return(secondUser.username == username && secondUser.password == password);
	}
};

#endif