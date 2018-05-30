#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <vector>
#include <algorithm>
#include "jeek.hpp"
#include "event.hpp"
#include "id.hpp"

class Jeek;

class User
{
private:
	std::string username;
	std::string password;
	std::string displayName;
	std::vector<MentionEvent> mentionedJeeks;
	std::vector<Jeek*> jeeks;
	std::vector<std::string> followings;
	TimeAndDate lastNotificationCheck;
public:
	User(std::string _username, std::string _displayName, std::string _password) : username(_username), displayName(_displayName),
	password(_password) {}

	void mentioned(std::string mentioner, ID jeekID);
	void follow(std::string followingUsername);
	TimeAndDate getLastNotifiCheck() { return lastNotificationCheck; }
	std::vector<Event*> notifications( TimeAndDate fromThisTime );

	bool operator==(const User& secondUser) const
	{
		return(secondUser.username == username && secondUser.password == password);
	}
	std::vector<Event*> jeeksFromTime( TimeAndDate fromThisTime );
};

#endif