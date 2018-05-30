#ifndef COMMENT_HPP
#define COMMENT_HPP

#include <string>
#include <vector>
#include "id.hpp"
#include "timeAndDate.hpp"
#include "event.hpp"

class Comment
{
private:
	std::string commenter;
	std::string commenterDispname;
	std::vector<Comment*> replies;
	ID commentID;
	std::string text;
	TimeAndDate commentTime;
public:
	Comment(std::string _commenter, std::string _commenterDispname, std::string _text) : commenter(_commenter),
	commenterDispname(_commenterDispname), text(_text) {}
	void showDetails();
	std::vector<Event*> eventsFromTime(TimeAndDate tnd);
	void addReply(Comment* replyCommnet) { replies.push_back(replyCommnet); }
	ID getID() { return commentID; }
	void printID() { commentID.print(); }
};

#endif