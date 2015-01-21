#ifndef world_queue_H
#define world_queue_H

#include "actor.h"

//generic node for doubly linked lists
//class used in conjunction with WorldQueue
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

//handles ordering of Actors via a priority queue
class WorldQueue
{
public:
	WorldQueue();
	~WorldQueue();

//empties the queue
	void Clear();
//returns and removes a pointer to the next Actor to be updated
	Actor* PopFront();
//inserts a pointer to an Actor to enter into the queue
	void Insert(Actor &act);
//removes the step time from each Actor in the queue
	void StepTime(int &step);
	
private:
	Node* head;
	Node* tail;
    int size;
};
#endif
