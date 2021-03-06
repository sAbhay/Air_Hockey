#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetCircleResolution(50);
    
//    ID = 0;
    
//    player = Player(ID);

//    clientSetup();
    
    puck = Puck();
    
    pl[0] = Player(0);
    pl[1] = Player(1);
    
    serverSetup();
}

//--------------------------------------------------------------
void ofApp::update()
{
    /*ofVec2f v;
    
    v.x = ofGetMouseX() - ofGetPreviousMouseX();
    v.y = ofGetMouseY() - ofGetPreviousMouseY();
    
    player.setVel(v);
    
    player.update();
    
    client();*/
    
    server();
    
    for(int i = 0; i < 2; i++)
    {
        pl[i].update();
    }
    
    puck.update();
    
    for(int i = 0; i < 2; i++)
    {
        puck.checkCollision(pl[i]);
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    background();
    
    for(int i = 0; i < 2; i++)
    {
        pl[i].display();
    }
    
    puck.display();
    
    /*player.display();
    
    
    ofFill();
    ofSetColor(0, 255, 0);
    ofDrawCircle(p.x, p.y, 30);*/
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
    float s = puck.getRad();
//    float s = 30;

    ofBackground(255);
    
    ofFill();
    ofSetColor(255, 0, 0);
    ofDrawRectangle(ofGetWidth()/2 - 5, 0, 10, ofGetHeight()/2 - s);
    ofDrawRectangle(ofGetWidth()/2 - 5, ofGetHeight()/2 + s, 10, ofGetHeight()/2);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, 1.266666 * s);
    
    ofSetColor(255);
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, s);
}

void ofApp::serverSetup()
{
    s.Create();
//    s.SetEnableBroadcast(true);
    s.Connect("172.16.51.62", 12344);
    s.SetNonBlocking(true);
}

void ofApp::server()
{
    ofVec2f pPos = puck.getPos();
    
    std::ostringstream puckPosX;
    puckPosX << pPos.x;
    std::string x(puckPosX.str());
    
    std::ostringstream puckPosY;
    puckPosY << pPos.y;
    std::string y(puckPosY.str());
    
    std::string puckPos = x + " " + y + " ";

    s.Send(puckPos.c_str(), puckPos.length());
    
    char received[100];
    int e = s.Receive(received, 100);
    
    std::cout << e;
    
    if(e != 0)
    {
        string data(received);
    
        /*string data1;
        data1 = data.substr(data.find("1:"), data.find("2:"));
        data.erase(data.find("1:") - 2, data.find("2:"));*/
    
        string delimiter;
        delimiter = " ";
    
        int pos[2];
        std::string token[2];
        int tokenNumber[2];
        float movementInfo[2][4];
        
        for(int i = 0; i < 2; i++)
        {
            pos[i] = 0;
            token[i] = "";
            tokenNumber[i] = 0;
            
            for(int j = 0; j < 4; j++)
            {
                movementInfo[i][j] = 0;
            }
        }
    
        while ((pos[0] = data.find(delimiter)) != std::string::npos)
        {
            token[0] = data.substr(0, pos[0]);
        
            if(token[0] != "1:" || token[0] != "2:")
            {
                movementInfo[0][tokenNumber[0]] = std::stoi(token[0]);
                tokenNumber[0]++;
            }
        
            data.erase(0, pos[0] + delimiter.length());
        }
    
       /*while ((pos[1] = data1.find(delimiter)) != std::string::npos)
        {
            token[1] = data.substr(0, pos[1]);
        
            if(token[1] != "1:" || token[1] != "2:")
            {
                movementInfo[1][tokenNumber[1]] = std::stoi(token[1]);
                tokenNumber[1]++;
            }
        
            data.erase(0, pos[1] + delimiter.length());
        }*/

    
        ofVec2f attributes[4];
        
        attributes[0] = ofVec2f(movementInfo[0][0], movementInfo[0][2]);
        attributes[1] = ofVec2f(movementInfo[0][2], movementInfo[0][3]);
        
        pl[0].setPos(attributes[0]);
        pl[0].setVel(attributes[1]);
    
        attributes[2] = ofVec2f(movementInfo[1][0], movementInfo[1][1]);
        attributes[3] = ofVec2f(movementInfo[1][2], movementInfo[1][3]);
    
        pl[1].setPos(attributes[2]);
        pl[1].setVel(attributes[3]);
    }
}

/*void ofApp::clientSetup()
{
    c.Create();
    c.Bind(12344);
    c.SetNonBlocking(true);
}

void ofApp::client()
{
    char received[100];
    int x = c.Receive(received, 100);
    
    if(x != 0)
    {
        string data(received);
    
        string delimiter = ", ";
    
        int pos = 0;
        std::string token;
        int tokenNumber = 0;
        float movementInfo[2];
    
        while ((pos = data.find(delimiter)) != std::string::npos)
        {
            token = data.substr(0, pos);
            movementInfo[tokenNumber] = std::stoi(token);
            tokenNumber++;
            data.erase(0, pos + delimiter.length());
        }
    
        p = ofVec2f(movementInfo[0], movementInfo[1]);
    }
    
    ofVec2f pPos = player.getPos();
    ofVec2f pVel = player.getVel();
    
    std::ostringstream k;
    k << pPos.x;
    std::string x(k.str());
    
    std::ostringstream l;
    l << pPos.y;
    std::string y(l.str());
    
    std::ostringstream m;
    m << pVel.x;
    std::string velX(m.str());
    
    std::ostringstream n;
    n << pVel.y;
    std::string velY(n.str());
    
    std::ostringstream o;
    o << ID + 1;
    std::string id(o.str());

    
    string send;
    send = id + ": " + x + " " + y + " " + velX + " " + velY + " ";
    
    c.Send(send.c_str(), send.length());
}*/
