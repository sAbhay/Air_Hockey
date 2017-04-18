#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetCircleResolution(50);
    
    p = Puck();
    player = Player(0);
}

//--------------------------------------------------------------
void ofApp::update()
{
    ofVec2f v;
    
    v.x = ofGetMouseX() - ofGetPreviousMouseX();
    v.y = ofGetMouseY() - ofGetPreviousMouseY();
    
    player.setVel(v);
    
    p.checkCollision(player);
}

//--------------------------------------------------------------
void ofApp::draw()
{
    background();
    
    player.update();
    p.update();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::background()
{
    float s = p.getRad();

    ofBackground(255);
    
    ofFill();
    ofSetColor(255, 0, 0);
    ofDrawRectangle(ofGetWidth()/2 - 5, 0, 10, ofGetHeight()/2 - s);
    ofDrawRectangle(ofGetWidth()/2 - 5, ofGetHeight()/2 + s, 10, ofGetHeight()/2);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, 1.266666 * s);
    
    ofSetColor(255);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, s);
}
