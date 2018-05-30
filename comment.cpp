#include "comment.hpp"

void Comment::showDetails()
{
	printf("%s\n", commenterDispname.c_str());
	printf("%s\n", text.c_str());
	for (int i = 0; i < (int)replies.size(); i++)
	{
		replies[i]->	getID().print();
		printf("\n");
	}
}

std::vector<Event*> Comment::eventsFromTime(TimeAndDate tnd)
{
	std::vector<Event*> events;
	if(commentTime >= tnd)
		events.push_back(new CommentEvent(commenter, commentID, commentTime));
	for (int i = 0; i < (int)replies.size(); i++)
	{
		std::vector<Event*> thisReplyEvents = replies[i]->eventsFromTime(tnd);
		events.insert(events.end(), thisReplyEvents.begin(), thisReplyEvents.end());
	}

	return events;
}