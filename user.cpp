#include "user.hpp"

void User::follow(std::string followingUsername)
{
	followings.push_back(followingUsername);
	std::unique(followings.begin(), followings.end());
}

void User::mentioned(std::string mentioner, ID jeekID)
{
	mentionedJeeks.push_back(MentionEvent(mentioner, jeekID, lastNotificationCheck.presentTime())); 
}

std::vector<Event*> User::jeeksFromTime (TimeAndDate fromThisTime )
{
	std::vector<Event*> events;
	for (int i = 0; i < (int)jeeks.size(); i++)
		if(jeeks[i]->getPublishTime() >= fromThisTime)
			events.push_back(new NewJeekEvent(username, jeeks[i]->getID(), jeeks[i]->getPublishTime()));
	return events;
}

std::vector<Event*> User::notifications( TimeAndDate fromThisTime )
{
	std::vector<Event*> events;
	for (int i = 0; i < (int)jeeks.size(); i++)
	{
		std::vector<Event*> curJeekEvents = jeeks[i]->eventsFromTime(fromThisTime);
		events.insert(events.end(), curJeekEvents.begin(), curJeekEvents.end());
	}
	for (int i = 0; i < (int)mentionedJeeks.size(); i++)
	{
		if(mentionedJeeks[i].getTime() >= fromThisTime)
			events.push_back(&mentionedJeeks[i]);
	}
	return events;
}