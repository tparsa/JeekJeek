CPPFLAGS=-std=c++11	
CPPOFLAG=-c
CPPBINDFLAGS=-o JeekJeek

all: commands.o jeek.o event.o id.o timeAndDate.o main.o user.o comment.o newJeek.o
	g++ commands.o jeek.o event.o id.o timeAndDate.o main.o user.o comment.o newJeek.o $(CPPFLAGS) $(CPPBINDFLAGS)

commands.o: commands.hpp commands.cpp
	g++ -c commands.cpp $(CPPFLAGS) $(CPPOFLAGS)

jeek.o: jeek.hpp jeek.cpp
	g++ -c jeek.cpp $(CPPFLAGS) $(CPPOFLAGS)

event.o: event.hpp event.cpp
	g++ -c event.cpp $(CPPFLAGS) $(CPPOFLAGS)

id.o: id.hpp id.cpp
	g++ -c id.cpp $(CPPFLAGS) $(CPPOFLAGS)

timeAndDate.o: timeAndDate.hpp timeAndDate.cpp
	g++ -c timeAndDate.cpp $(CPPFLAGS) $(CPPOFLAGS)

main.o: main.cpp
	g++ -c main.cpp $(CPPFLAGS) $(CPPOFLAGS)

user.o: user.hpp user.cpp
	g++ -c user.cpp $(CPPFLAGS) $(CPPOFLAGS)

comment.o: comment.hpp comment.cpp
	g++ -c comment.cpp $(CPPFLAGS) $(CPPOFLAGS)

newJeek.o: newJeek.hpp newJeek.cpp
	g++ -c newJeek.cpp $(CPPFLAGS) $(CPPOFLAGS)

clean:
	touch ~lstID
	touch non.o
	touch JeekJeek
	rm ~lstID && rm *.o && rm JeekJeek

clear: clean