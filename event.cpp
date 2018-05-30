#include "event.hpp"

void LikeEvent::print()
{
	printf("%s liked ", username.c_str());
	id.print();
	printf("\n");
}

void DislikeEvent::print()
{
	printf("%s disliked ", username.c_str());
	id.print();
	printf("\n");
}

void NewJeekEvent::print()
{
	printf("%s jeeked ", username.c_str());
	id.print();
	printf("\n");
}

void ReJeekEvent::print()
{
	printf("%s rejeeked ", username.c_str());
	id.print();
	printf("\n");
}

void CommentEvent::print()
{
	printf("%s commented on ", username.c_str());
	id.print();
	printf("\n");
}

void ReplyEvent::print()
{
	printf("%s replied ", username.c_str());
	id.print();
	printf("\n");
}

void MentionEvent::print()
{
	printf("%s mentioned you in", username.c_str());
	id.print();
	printf("\n");
}	