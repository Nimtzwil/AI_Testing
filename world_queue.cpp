#include "world_queue.h"
#include "actor.h"

//default constructor
WorldQueue::WorldQueue(){
    size = 0;
    head = nullptr;
    tail = nullptr;
}

//destructor
WorldQueue::~WorldQueue(){
    Clear();
}

//empties the queue
void WorldQueue::Clear(){
    while (size > 0){
        PopFront();
    }
}

//returns and removes a pointer to the next Actor to be updated
Actor* WorldQueue::PopFront(){
    Actor* toUpdate = nullptr;

    if (size == 0){
        toUpdate = nullptr;
    }
    else if (size == 1){
        toUpdate = head->payload;
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else {
        toUpdate = head->payload;
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
    }

    
    size = size-1;
    if (toUpdate != nullptr){
        StepTime(toUpdate->delay);
    }
    return toUpdate;
}

//inserts a pointer to an Actor to enter into the queue
void WorldQueue::Insert(Actor &act){
    Node *toInsert = new Node(act);

    if (size == 0){
        head = toInsert;
        tail = toInsert;
    }
    else if (toInsert->payload->delay < head->payload->delay){
        head->prev = toInsert;
        toInsert->next = head;
        head = toInsert;
    }
    else if (toInsert->payload->delay >= tail->payload->delay){
        tail->next = toInsert;
        toInsert->prev = tail;
        tail = toInsert;
    }
    else {
        Node *Position = head->next;
        while (toInsert->payload->delay < Position->payload->delay){
            Position = Position->next;
        }
        Position->prev->next = toInsert;
        toInsert->prev = Position->prev;
        Position->prev = toInsert;
        toInsert->next = Position;
    }

    size = size+1;
    return;
}

//removes the step time from each Actor in the queue
//called automatically in PopFront
void WorldQueue::StepTime(int &step){
    Node *Position = head;

    if ((step != 0)&&(size != 0)){
        while (Position != nullptr){
            Position->payload->delay = Position->payload->delay - step;
        }
    }

    return;
}
