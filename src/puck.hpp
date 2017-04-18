//
//  puck.hpp
//  Air_Hockey
//
//  Created by Abhay Singhal on 4/12/17.
//
//

#ifndef puck_hpp
#define puck_hpp

#include <stdio.h>
#include "ofMain.h"
#include "player.hpp"

class Puck
{
    private:
        ofVec2f pos;
        ofVec2f vel;
        int r;
        int m;
        float restitution;
        float friction;
    
    public:
        Puck();
        ~Puck();
    
        void display();
        void move();
        void update();
        void checkBoundaries();
    
        void checkCollision(Player& p);
    
        void setPos(ofVec2f p) {pos = p;}
        ofVec2f getPos() {return pos;}
    
        void setVel(ofVec2f v) {vel = v;}
        ofVec2f getVel() {return vel;}
    
        int getRad() {return r;}
        int getMass() {return m;}
};

#endif /* puck_hpp */
