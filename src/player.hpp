//
//  player.hpp
//  Air_Hockey
//
//  Created by Abhay Singhal on 4/12/17.
//
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include "ofMain.h"

class Player
{
    private:
        ofVec2f pos;
        ofVec2f vel;
        int r;
        int m;
        int n;
    
        void checkBoundaries();
        void move();
    
    public:
        Player();
        Player(int number);
        ~Player();
    
        void display();
        void update();
    
        void setPos(ofVec2f p) {pos = p;}
        ofVec2f getPos() {return pos;}
    
        void setVel(ofVec2f v) {vel = v;}
        ofVec2f getVel() {return vel;}
    
        int getRad() {return r;}
        int getMass() {return m;}
};

#endif /* player_hpp */
