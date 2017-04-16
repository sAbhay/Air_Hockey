//
//  puck.cpp
//  Air_Hockey
//
//  Created by Abhay Singhal on 4/12/17.
//
//

#include "puck.hpp"

Puck::Puck()
{
    pos = ofVec2f(ofGetWidth()/2, ofGetHeight()/2);
    vel = ofVec2f(0, 0);
    r = 30;
    m = 1;
}

Puck::~Puck()
{
    
}

void Puck::display()
{
    ofFill();
    ofSetColor(0, 255, 0);
    ofDrawCircle(pos.x, pos.y, r);
}

void Puck::move()
{
    vel *= friction;
    
    pos += vel;
}

void Puck::update()
{
    move();
    display();
}

void Puck::checkBoundaries()
{
    if(pos.x <= r)
    {
        pos.x = r;
        vel.x *= -restitution;
    }
    
    if(pos.x >= ofGetWidth() - r)
    {
        pos.x = ofGetWidth() - r;
        vel.x *= -restitution;
    }
    
    if(pos.y <= r)
    {
        pos.y = r;
        vel.y *= -restitution;
    }
    
    if(pos.y >= ofGetWidth() - r)
    {
        pos.y = ofGetWidth() - r;
        vel.y *= -restitution;
    }
}
