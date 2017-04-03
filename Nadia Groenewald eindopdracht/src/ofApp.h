#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

    public:
        void setup();

        void draw();
    
        void mousePressed(int x, int y, int button);
    
    private:
        ofImage mapImage;
        ofImage maproute1Image;
        ofImage maproute2Image;
        ofImage stamp1Image;
        ofImage stamp2Image;
        ofImage goImage;
        ofImage menuImage;
        ofImage youImage;
        ofImage stopImage;
        ofImage infopage1Image;
        ofImage infopage2Image;
    
        bool drawmapRoute1 = false;
        bool drawmapRoute2 = false;
        bool drawstopImage = false;
        bool drawstamp2Image = false;
        bool drawinfopage1Image = false;
        bool drawinfopage2Image = false;
    
        bool drawstamp1Image = true;
        bool drawgoImage = true;
    
    
        
};
