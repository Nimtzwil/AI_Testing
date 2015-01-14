#include <vector>
#include <string>
#include <list>

#include "libtcod.hpp"
#include "actor.h"
#include "world_queue.h"

//render the game
void render(int & curX, int & curY, bool & hide, int & clock){
    TCODConsole::root->clear();
    std::string str = "";
    int count = 0;

//cursor
    if (!hide){
        TCODConsole::root->setChar(curX,curY,7);
        TCODConsole::root->setCharForeground(curX,curY,TCODColor::blue);
    }

//menu background
    for (unsigned int I = 62-2; I <= 62+9; I++){
        for (unsigned int J = 0; J <= 62-3; J++){
            TCODConsole::root->setCharBackground(I, J, TCODColor::darkestGrey);
        }
    }

//vertical lines
    for (unsigned int J = 1; J < 62-3; J++){
        TCODConsole::root->setChar(62-2,J,186);
        TCODConsole::root->setCharForeground(62-2, J, TCODColor::red);

        TCODConsole::root->setChar(62+9,J,186);
        TCODConsole::root->setCharForeground(62+9, J, TCODColor::red);
    }

//horizontal lines
    for (unsigned int I = 62-1; I <62+9; I++){
        TCODConsole::root->setChar(I,0,205);
        TCODConsole::root->setCharForeground(I, 0, TCODColor::red);

        TCODConsole::root->setChar(I,5,205);
        TCODConsole::root->setCharForeground(I, 5, TCODColor::red);

        TCODConsole::root->setChar(I,62-5,205);
        TCODConsole::root->setCharForeground(I, 62-5, TCODColor::red);

        TCODConsole::root->setChar(I,62-3,205);
        TCODConsole::root->setCharForeground(I, 62-3, TCODColor::red);
    }

//left connections
    TCODConsole::root->setChar(62-2,0,201);
    TCODConsole::root->setCharForeground(62-2,0, TCODColor::red);

    TCODConsole::root->setChar(62-2,5,204);
    TCODConsole::root->setCharForeground(62-2,5, TCODColor::red);

    TCODConsole::root->setChar(62-2,62-5,204);
    TCODConsole::root->setCharForeground(62-2,62-5, TCODColor::red);

    TCODConsole::root->setChar(62-2,62-3,200);
    TCODConsole::root->setCharForeground(62-2,62-3, TCODColor::red);

//right connections
    TCODConsole::root->setChar(62+9,0,187);
    TCODConsole::root->setCharForeground(62+9,0, TCODColor::red);

    TCODConsole::root->setChar(62+9,5,185);
    TCODConsole::root->setCharForeground(62+9,5, TCODColor::red);

    TCODConsole::root->setChar(62+9,62-5,185);
    TCODConsole::root->setCharForeground(62+9,62-5, TCODColor::red);

    TCODConsole::root->setChar(62+9,62-3,188);
    TCODConsole::root->setCharForeground(62+9,62-3, TCODColor::red);

//Title
    count = 0;
    str = "AI";
    for (char c: str){
        TCODConsole::root->setChar(62-1+count,1,c);
        TCODConsole::root->setCharForeground(62-1+count,1, TCODColor::blue);
        count++;
    }

    count = 0;
    str = "Testing";
    for (char c: str){
        TCODConsole::root->setChar(62-1+count,2,c);
        TCODConsole::root->setCharForeground(62-1+count,2, TCODColor::chartreuse);
        count++;
    }

    count = 0;
    str = "_____";
    for (char c: str){
        TCODConsole::root->setChar(62-1+count,3,c);
        TCODConsole::root->setCharForeground(62-1+count,3, TCODColor::chartreuse);
        count++;
    }

    count = 0;
    str = "_____";
    for (char c: str){
        TCODConsole::root->setChar(62-1+count,4,c);
        TCODConsole::root->setCharForeground(62-1+count,4, TCODColor::chartreuse);
        count++;
    }

//Time
    count = 0;
    str = "Time-";
    for (char c: str){
        TCODConsole::root->setChar(62-1+count,62-4,c);
        TCODConsole::root->setCharForeground(62-1+count,62-4, TCODColor::blue);
        count++;
    }

    str = std::to_string(clock);
    for (char c: str){
        TCODConsole::root->setChar(62-1+count,62-4,c);
        TCODConsole::root->setCharForeground(62-1+count,62-4, TCODColor::chartreuse);
        count++;
    }

//Controls
    count = 0;
    str = " Controls";
    for (char c: str){
        TCODConsole::root->setChar(62-1+count,6,c);
        TCODConsole::root->setCharForeground(62-1+count,6, TCODColor::blue);
        count++;
    }

    count = 0;
    str = "Move-arrow";
    for (char c: str){
        TCODConsole::root->setChar(62-1+count,8,c);
        TCODConsole::root->setCharForeground(62-1+count,8, TCODColor::chartreuse);
        count++;
    }
    count = 0;
    str = "      keys";
    for (char c: str){
        TCODConsole::root->setChar(62-1+count,9,c);
        TCODConsole::root->setCharForeground(62-1+count,9, TCODColor::chartreuse);
        count++;
    }

    count = 0;
    str = " Hide  - h";
    for (char c: str){
        TCODConsole::root->setChar(62-1+count,12,c);
        TCODConsole::root->setCharForeground(62-1+count,12, TCODColor::chartreuse);
        count++;
    }
    count = 0;
    str = "Cursor";
    for (char c: str){
        TCODConsole::root->setChar(62-1+count,13,c);
        TCODConsole::root->setCharForeground(62-1+count,13, TCODColor::chartreuse);
        count++;
    }

    count = 0;
    str = "Flip   - f";
    for (char c: str){
        TCODConsole::root->setChar(62-1+count,16,c);
        TCODConsole::root->setCharForeground(62-1+count,16, TCODColor::chartreuse);
        count++;
    }
    count = 0;
    str = "  Cell";
    for (char c: str){
        TCODConsole::root->setChar(62-1+count,17,c);
        TCODConsole::root->setCharForeground(62-1+count,17, TCODColor::chartreuse);
        count++;
    }

    count = 0;
    str = "Random - r";
    for (char c: str){
        TCODConsole::root->setChar(62-1+count,20,c);
        TCODConsole::root->setCharForeground(62-1+count,20, TCODColor::chartreuse);
        count++;
    }
    count = 0;
    str = " Fill";
    for (char c: str){
        TCODConsole::root->setChar(62-1+count,21,c);
        TCODConsole::root->setCharForeground(62-1+count,21, TCODColor::chartreuse);
        count++;
    }

    count = 0;
    str = "Clear  - c";
    for (char c: str){
        TCODConsole::root->setChar(62-1+count,24,c);
        TCODConsole::root->setCharForeground(62-1+count,24, TCODColor::chartreuse);
        count++;
    }
    count = 0;
    str = " Board";
    for (char c: str){
        TCODConsole::root->setChar(62-1+count,25,c);
        TCODConsole::root->setCharForeground(62-1+count,25, TCODColor::chartreuse);
        count++;
    }

    count = 0;
    str = "Step   - s";
    for (char c: str){
        TCODConsole::root->setChar(62-1+count,28,c);
        TCODConsole::root->setCharForeground(62-1+count,28, TCODColor::chartreuse);
        count++;
    }
    count = 0;
    str = "  Time";
    for (char c: str){
        TCODConsole::root->setChar(62-1+count,29,c);
        TCODConsole::root->setCharForeground(62-1+count,29, TCODColor::chartreuse);
        count++;
    }
}

//main body of game
int main() {
    int width = 60;
    int height = width;
    int cursorX = 0;
    int cursorY = 0;
    TCODConsole::initRoot(width+12, height, "AI Testing", false);
    TCODRandom rnd = TCODRandom();
    int rndVal = 0;
    bool hidden = false;
    int time = 0;

    std::list<Actor *> actors;
    WorldQueue queue;

//render initial state
    render(cursorX,cursorY,hidden,time);

//keeps game going
    while ( !TCODConsole::isWindowClosed() ) {
        TCOD_key_t key;
//check if key has been pressed
        TCODSystem::checkForEvent(TCOD_EVENT_KEY_PRESS, &key,NULL);
        switch(key.vk) {
//up
            case TCODK_UP :
                cursorY = (cursorY - 1);
            break;
//down
            case TCODK_DOWN :
                cursorY = (cursorY + 1);
            break;
//left
            case TCODK_LEFT :
                cursorX = (cursorX - 1);
            break;
//right
            case TCODK_RIGHT :
                cursorX = (cursorX + 1);
            break;

//not a special character
            case TCODK_CHAR :
//TODO
                if(key.c == 'f'){
                    actors.push_front(new Actor(cursorX, cursorY, 25, TCODColor::red, 1, 1, 3));
                    queue.Insert(*actors.front());
                }
//TODO
                else if(key.c == 's'){
                    actors.push_front(new Actor(cursorX, cursorY, 25, TCODColor::blue, 1, 1, 6));
                    queue.Insert(*actors.front());
                }
//step time
                else if(key.c == 'u'){
                    Actor* lamb = queue.PopFront();
                    time = time + lamb->speed;
                    lamb->delay = lamb->speed;
                    queue.Insert(*lamb);
                }
//hide cursor
                else if(key.c == 'h'){
                    if(hidden)
                        hidden = false;
                    else
                        hidden = true;
                }
            break;

//default
            default:break;
        }

//handle cursor wrapping (% was giving issues when going to -1)
        if (cursorY >= height)
            cursorY = cursorY - height;
        else if (cursorY < 0)
            cursorY = cursorY + height;

        if (cursorX >= width)
            cursorX = cursorX - width;
        else if (cursorX < 0)
            cursorX = cursorX + width;

//render current state
        render(cursorX,cursorY,hidden,time);
        for (auto iterator=actors.begin(); iterator != actors.end(); iterator++) {
            (*iterator)->render();
        }

//flush the screen buffer
        TCODConsole::flush();
    }

    for(auto each : actors){
        delete each;
    }

    return 0;
}
