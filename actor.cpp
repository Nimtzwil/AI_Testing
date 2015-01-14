#include "libtcod.hpp"
#include "actor.h"

Actor::Actor(int x, int y, int ch, const TCODColor &col, int typ, int health, int spd):
    x(x),y(y),ch(ch),col(col) {
facing = 0;
type = typ;
hp = health;
stinks = false;
delay = 0;
speed = spd;
}

Actor::~Actor(){
    
}

void Actor::render() const{
    TCODConsole::root->setChar(x,y,ch);
    TCODConsole::root->setCharForeground(x,y,col);
}

void Actor::update(){
    x = x+1;
}
