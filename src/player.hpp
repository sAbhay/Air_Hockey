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
#include "puck.hpp"

class Player
{
    private:
        ofVec2f pos;
        ofVec2f vel;
        int r;
        int m;
        int n;
    
    public:
        Player();
        Player(int number);
        ~Player();
    
        void display();
        void move();
        void update();
        void checkCollision(Puck& p);
        void checkBoundaries();
    
        void setPos(ofVec2f p) {pos = p;}
        ofVec2f getPos() {return pos;}
    
        void setVel(ofVec2f v) {vel = v;}
        ofVec2f getVel() {return vel;}
};

#endif /* player_hpp */
