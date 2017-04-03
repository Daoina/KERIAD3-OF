#include "ofApp.h"

void ofApp::setup() {
    mapImage.load("plattegrond rdam.png");
    maproute1Image.load("route.png");
    maproute2Image.load("route2.png");
    stamp1Image.load("stamp1.png");
    stamp2Image.load("stamp2.png");
    youImage.load("you.png");
    menuImage.load("menu.png");
    goImage.load("go.png");
    stopImage.load("stop.png");
    infopage1Image.load("infopage1.png");
    infopage2Image.load("infopage2.png");

}

void ofApp::draw() {
    ofSetColor(ofColor::white);
    mapImage.draw(0, 0);
    
    if(drawmapRoute1)
    {
        maproute1Image.draw(0, 0);
    }
    
    if(drawmapRoute2)
    {
        maproute2Image.draw(0, 0);
    }
    
    if(drawstamp2Image)
    {
        stamp2Image.draw(47, 15);
    }
    
    if(drawgoImage)
    {
        goImage.draw(165,405);
    }
    
    if(drawstamp1Image)
    {
        stamp1Image.draw(328,36);
    }
    
    if(drawstopImage)
    {
        stopImage.draw(20, 438);
    }

    youImage.draw(260,289);
    menuImage.draw(0,510);
    
    if(drawinfopage1Image)
    {
        infopage1Image.draw(0, 0);
    }
    
    if(drawinfopage2Image)
    {
        infopage2Image.draw(0, 0);
    }
}

void ofApp::mousePressed(int x, int y, int button)
{
    if(ofGetMouseX() >= 165 && ofGetMouseY() >= 405 && ofGetMouseX() <= 165 + goImage.getWidth() && ofGetMouseY() <= 405 + goImage.getHeight()) //dit is voor de go knop. Als erop geklikt wordt spawnt de route van stamp 1.
    {
        drawmapRoute1 = true;
        drawstopImage = true;
        drawgoImage = false;
    }
    
    if(ofGetMouseX() >= 165 && ofGetMouseY() >= 315 && ofGetMouseX() <= 165 + goImage.getWidth() && ofGetMouseY() <= 315 + goImage.getHeight()) //dit is voor de neppe go knop (bevindt zich boven de echte go knop). Als erop geklikt word spawnt de route van stamp 2.
    {
        drawmapRoute2 = true;
        drawstopImage = true;
        drawgoImage = false;
    }
    
    if(ofGetMouseX() >= 20 && ofGetMouseY() >= 438 && ofGetMouseX() <= 20 + stopImage.getWidth() && ofGetMouseY() <= 438 + stopImage.getHeight()) //dit is voor de stop knop. Als erop geklikt wordt spawnt het de go knop weer en despawned het de stop knop.
    {
        drawmapRoute1 = false;
        drawmapRoute2 = false;
        drawstopImage = false;
        drawgoImage = true;
    }
    
    if(ofGetMouseX() >= 30 && ofGetMouseY() >= 593 && ofGetMouseX() <= 30 + 69 && ofGetMouseY() <= 593 + 69) //dit is voor de stamp 1 ("blauwe muur"), in het menu. Als erop geklikt word despawnt het stamp 2  en spawnt het stamp 1
    {
        drawstamp2Image = false;
        drawstamp1Image = true;
        drawstopImage = false;
        drawgoImage = true;
        drawmapRoute2 = false;
    }
    
    if(ofGetMouseX() >= 30 && ofGetMouseY() >= 672 && ofGetMouseX() <= 30 + 69 && ofGetMouseY() <= 672 + 69) //dit is voor de stamp 2 ("zwart-witte muur), in het menu. Als erop geklikt word despawnt het stamp 1 en spawnt het stamp 2
    {
        ofLog() << "er word op mij geklikt!" << endl;
        
        drawstamp2Image = true;
        drawstamp1Image = false;
        drawstopImage = false;
        drawgoImage = true;
        drawmapRoute1 = false;
    }
    
    if(ofGetMouseX() >= 260 && ofGetMouseY() >= 612 && ofGetMouseX() <= 260 + 150 && ofGetMouseY() <= 612 + 25) //Als er op "more info" bij "blauwe muur" word geklikt spawnt dit info scherm 1
    {
        drawinfopage1Image = true;
    }
    
    if(ofGetMouseX() >= 0 && ofGetMouseY() >= 223 && ofGetMouseX() <= 0 + 50 && ofGetMouseY() <= 223 + 20)
//        als er op de back knop word geklikt bij het info scherm, despawnt deze.
    {
        drawinfopage1Image = false;
        drawinfopage2Image = false;
    }
    
    if(ofGetMouseX() >= 260 && ofGetMouseY() >= 688 && ofGetMouseX() <= 260 + 150 && ofGetMouseY() <= 688 + 25) //Als er op "more info" bij "zwart-witte muur" word geklikt spawnt dit info scherm 2
    {
        drawinfopage2Image = true;
    }
}
