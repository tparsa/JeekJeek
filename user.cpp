#include "user.hpp"

void User::follow(std::string followingUsername)
{
	followings.push_back(followingUsername);
	std::unique(followings.begin(), followings.end());
}