#pragma once

#include "ofMain.h"
#include "SQLiteCpp.h"
#include "ofxCenteredTrueTypeFont.h"

class ofApp : public ofBaseApp {
    
public:
    
    void setup();
    
    void update();
    
    void draw();
    
    ofxCenteredTrueTypeFont font;
    
    
    void keyPressed(int key);
    
    void keyReleased(int key);
    
    void mouseMoved(int x, int y);
    
    ofTrueTypeFont myfont;
    
private:
    SQLite::Database* db;
    int selectedYear = 0;
    
    int total;
    int north;
    int east;
    int south;
    int west;
};
