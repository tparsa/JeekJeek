#ifndef JEEK_HPP
#define JEEK_HPP

#include <string>
#include <iostream>
#include "user.hpp"
#include "comment.hpp"
#include "timeAndDate.hpp"
#include "event.hpp"
#include "id.hpp"

class JEEK_EXCEPTION {};

class JEEK_TEXT_SIZE_EXCEEDED : public JEEK_EXCEPTION {};

class EMPTY_JEEK : public JEEK_EXCEPTION {};

class EXPECTING_PUBLISHING_ABORTED_JEEK : public JEEK_EXCEPTION {};

class Jeek
{
private:
	ID jeekId;
	std::string username;
	std::vector<Comment> comments;
	std::string text;
	std::vector<std::string> mentions;
	std::vector< std::pair<std::string, TimeAndDate> > likes;
	std::vector< std::pair<std::string, TimeAndDate> > dislikes;
	std::vector< std::pair<std::string, TimeAndDate> > reJeekers;
	std::vector<std::string> hashTags;
	TimeAndDate publishTime;

	std::vector<Event*> likesFromTime(TimeAndDate tnd);
	std::vector<Event*> dislikesFromTime(TimeAndDate tnd);
	std::vector<Event*> reJeeksFromTime(TimeAndDate tnd);
	std::vector<Event*> commentsFromTime(TimeAndDate tnd);
	void showHashTagsDetails();
	void showMentions();
	void showCommentIds();

public:
	Jeek (std::string _username, std::string _text, std::vector<std::string> _mentions, std::vector<std::string> _hashTags, TimeAndDate _publishTime): username(_username),
	text(_text), mentions(_mentions), hashTags(_hashTags), publishTime(_publishTime) {}
	std::vector<Event*> eventsFromTime(TimeAndDate tnd);
	void showDetails();
	void addReJeeker(std::string rejeekerUsername)
	{
		reJeekers.push_back( make_pair( rejeekerUsername, publishTime.presentTime() ) );
	}
	std::string getText() const { return text; }
	std::vector<std::string> getHashTags() const { return hashTags; }
	std::vector<std::string> getMentions() const { return mentions; }
	TimeAndDate getPublishTime() { return publishTime; }
	ID getID() { return jeekId;}
};

#endif