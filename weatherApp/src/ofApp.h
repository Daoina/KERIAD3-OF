#pragma once

#include "ofMain.h"
#include "ofxJSON.h"
#include "ofxCenteredTrueTypeFont.h"


class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    ofxCenteredTrueTypeFont font;
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    
    void getData();
    
    ofxJSONElement json;
    
    string weather;
    
    ofImage RainImage;
    ofImage CloudsImage;
    ofImage ClearImage;
    ofImage SnowImage;
};