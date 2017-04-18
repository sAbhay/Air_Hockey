//
//  player.cpp
//  Air_Hockey
//
//  Created by Abhay Singhal on 4/12/17.
//
//

#include "player.hpp"

Player::Player()
{
    pos = ofVec2f(0, 0);
    vel = ofVec2f(0, 0);
    r = 40;
    m = 2;
    n = 0;
}

Player::Player(int number)
{
    pos = ofVec2f(number * ofGetWidth()/2 + ofGetWidth()/4, ofGetHeight()/2);
    vel = ofVec2f(0, 0);
    r = 45;
    m = 2;
    n = number;
}

Player::~Player()
{
    
}

void Player::display()
{
    ofFill();
    ofSetColor(0);
    ofDrawCircle(pos.x, pos.y, r);
}

void Player::move()
{
    pos += vel;
}

void Player::update()
{
    move();
    checkBoundaries();
}

void Player::checkBoundaries()
{
    if(pos.x <= n * ofGetWidth()/2 + r)
    {
        pos.x = n * ofGetWidth()/2 + r;
        vel.x = 0;
    }
    
    if(pos.x >= (n+1) * ofGetWidth()/2 - r)
    {
        pos.x = (n+1) * ofGetWidth()/2 - r;
        vel.x = 0;
    }
    
    if(pos.y <= r)
    {
        pos.y = r;
        vel.y = 0;
    }
    
    if(pos.y >= ofGetHeight() - r)
    {
        pos.y = ofGetHeight() - r;
        vel.y = 0;
    }

}
