#pragma once

#include "ofMain.h"
#include "puck.hpp"
#include "player.hpp"
#include "ofxNetwork.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
        void background();
        void serverSetup();
        void server();
        void clientSetup();
        void client();

    private:
        Puck puck;
//        Player player;
        Player pl[2];
    
        ofxUDPManager s;
//        ofxUDPManager c;
//        int ID;
    
//        ofVec2f p;
};
