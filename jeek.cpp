#include "jeek.hpp"

std::vector<Event*> Jeek::likesFromTime(TimeAndDate tnd)
{
	std::vector<Event*> ret;
	for (int i = 0; i < (int)likes.size(); i++)
		if(likes[i].second >= tnd)
			ret.push_back(new LikeEvent(likes[i].first, jeekId, likes[i].second));
	return ret;
}

std::vector<Event*> Jeek::dislikesFromTime(TimeAndDate tnd)
{
	std::vector<Event*> ret;
	for (int i = 0; i < (int)dislikes.size(); i++)
		if(dislikes[i].second >= tnd)
			ret.push_back(new DislikeEvent(dislikes[i].first, jeekId, dislikes[i].second));
	return ret;
}

std::vector<Event*> Jeek::reJeeksFromTime(TimeAndDate tnd)
{
	std::vector<Event*> ret;
	for (int i = 0; i < (int)reJeekers.size(); i++)
		if(reJeekers[i].second >= tnd)
			ret.push_back(new ReJeekEvent(reJeekers[i].first, jeekId, reJeekers[i].second));
	return ret;
}

std::vector<Event*> Jeek::commentsFromTime(TimeAndDate tnd)
{
	std::vector<Event*> ret;
	for (int i = 0; i < (int)comments.size(); i++)
	{
		std::vector<Event*> thisCommentEvents = comments[i].eventsFromTime(tnd);
		ret.insert(ret.end(), thisCommentEvents.begin(), thisCommentEvents.end());
	}
	return ret;
}

std::vector<Event*> Jeek::eventsFromTime(TimeAndDate tnd)
{
	std::vector<Event*> events;

	std::vector<Event*> likesEvents = likesFromTime(tnd);
	std::vector<Event*> dislikesEvents = dislikesFromTime(tnd);
	std::vector<Event*> reJeeksEvents = reJeeksFromTime(tnd);
	std::vector<Event*> commentsEvents = commentsFromTime(tnd);

	events.insert(events.end(), likesEvents.begin(), likesEvents.end());
	events.insert(events.end(), dislikesEvents.begin(), dislikesEvents.end());
	events.insert(events.end(), reJeeksEvents.begin(), reJeeksEvents.end());
	events.insert(events.end(), commentsEvents.begin(), commentsEvents.end());

	return events;
}

void Jeek::showHashTagsDetails()
{
	for (int i = 0; i < (int)hashTags.size(); i++)
		printf("#%s\n", hashTags[i].c_str());
}

void Jeek::showMentions()
{
	for (int i = 0; i < (int)mentions.size(); i++)
		printf("@%s\n", mentions[i].c_str());
}

void Jeek::showCommentIds()
{
	printf("comments:\n");
	for (int i = 0; i < (int)comments.size(); i++)
		comments[i].printID();
}

void Jeek::showDetails()
{
	printf("%s\n", username.c_str());
	printf("%s\n", text.c_str());

	showHashTagsDetails();
	showMentions();

	printf("Likes %d\n", (int)likes.size());
	printf("Rejeeks %d\n", (int)reJeekers.size());

	showCommentIds();
}