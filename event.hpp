#ifndef EVENT_HPP
#define EVENT_HPP

#include <string>
#include <cstdio>
#include "id.hpp"
#include "timeAndDate.hpp"

class Event
{

protected:
	std::string username;
	ID id;
	TimeAndDate eventTime;
public:
	Event(std::string _username, ID _id, TimeAndDate _time) : username(_username), id(_id), eventTime(_time) {}
	virtual void print() = 0;

};

class LikeEvent : public Event
{
public:
	LikeEvent(std::string _username, ID _id, TimeAndDate _time) : Event(_username, _id, _time) {}
	void print();
};

class DislikeEvent : public Event
{
public:
	DislikeEvent(std::string _username, ID _id, TimeAndDate _time) : Event(_username, _id, _time) {}
	void print();
};

class NewJeekEvent : public Event
{
public:
	NewJeekEvent(std::string _username, ID _id, TimeAndDate _time) : Event(_username, _id, _time) {}
	void print();
};

class ReJeekEvent : public Event
{
public:
	ReJeekEvent(std::string _username, ID _id, TimeAndDate _time) : Event(_username, _id, _time) {}
	void print();
};

class CommentEvent : public Event
{
public:
	CommentEvent(std::string _username, ID _id, TimeAndDate _time) : Event(_username, _id, _time) {}
	void print();
};

class ReplyEvent : public Event
{
public:
	ReplyEvent(std::string _username, ID _id, TimeAndDate _time) : Event(_username, _id, _time) {}
	void print();
};

class MentionEvent : public Event
{
public:
	MentionEvent(std::string _username, ID _id, TimeAndDate _time) : Event(_username, _id, _time) {}
	void print();
	TimeAndDate getTime() { return eventTime; }
};

#endif