#include "world_queue.h"
#include "actor.h"

WorldQueue::WorldQueue(){
    head = nullptr;
    tail = nullptr;
}

WorldQueue::~WorldQueue(){
    Clear();
}

void WorldQueue::Clear(){
    while (size > 0){
        PopFront();
    }
}

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

void WorldQueue::StepTime(int &step){
    Node *Position = head;

    if ((step != 0)&&(size != 0)){
        while (Position != nullptr){
            Position->payload->delay = Position->payload->delay - step;
        }
    }

    return;
}
