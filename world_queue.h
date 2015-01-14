#ifndef world_queue_H
#define world_queue_H

#include "actor.h"

class Node 
{
	friend class WorldQueue;
public:
	Node() {payload = nullptr; next = nullptr;  prev = nullptr;}
	Node(Actor &t) {payload = &t;  next = nullptr;  prev = nullptr;}

private:
	Node *next;
	Node *prev;
	Actor *payload;
};

class WorldQueue
{
public:
	WorldQueue();
	~WorldQueue();
	
	void Clear();

	Actor* PopFront();
	void Insert(Actor &act);
	
	void StepTime(int &step);
	
private:
	Node* head;
	Node* tail;
    int size;
	
	// You can put helper methods here
};
#endif
