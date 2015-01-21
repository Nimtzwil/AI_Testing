#include "libtcod.hpp"
#include "actor.h"

Actor::Actor(int x, int y, int ch, const TCODColor &col, int typ, int health, int spd):
    x(x),y(y),ch(ch),col(col) {
facing = 0;
type = typ;
hp = health;
stinks = false;
speed = spd;
delay = spd;
}

Actor::~Actor(){
    
}

void Actor::render() const{
    TCODConsole::root->setChar(x,y,ch);
    TCODConsole::root->setCharForeground(x,y,col);
}

void Actor::update(){
//Update depending on type
//fire bat
    if (type == 1){
        x = x+1;
    }
//stone golem
    else if (type == 2){
        y = y+1;
    }
}
