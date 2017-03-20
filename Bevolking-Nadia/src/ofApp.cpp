#include <SQLiteCpp/include/SQLiteCpp/Database.h>
#include "ofApp.h"

void ofApp::setup() {
    string databasePath = ofToDataPath("bevolking.sqlite", true);
    db = new SQLite::Database(databasePath);
    font.loadFont("Gotham-Book.otf", 20);
    myfont.load("Gotham-Book.otf", 10);
}

void ofApp::update() {
    int year = ofMap(ofGetMouseX(), 0, ofGetWidth() - 100, 1900, 2016, true);
    
    if (year != selectedYear) {
        selectedYear = year;
        string sql = "SELECT year, north, east, south, west, north+east+south+west AS total FROM bevolking WHERE year=?";
        
        SQLite::Statement query(*db, sql);
        
        query.bind(1, selectedYear); // vervang 1e vraagteken door de waarde van de variabele
        if (query.executeStep()) {
            total = query.getColumn("total").getInt();
            year = query.getColumn("year").getInt();
            north = query.getColumn("north").getInt();
            east = query.getColumn("east").getInt();
            south = query.getColumn("south").getInt();
            west = query.getColumn("west").getInt();
            ofLog() << selectedYear << " " << total << " "
            << north << " " << east << " " << south << " " << west
            << endl;
        }
        
        query.reset();
    }
    
}

void ofApp::draw() {
    ofSetCircleResolution(100);
    ofSetBackgroundColor(255, 255, 255);
    ofSetColor(155, 155, 155);
    font.drawStringCentered("Bevolking van de windstreken in", ofGetWidth()/2, 60);
    font.drawStringCentered(ofToString(selectedYear), ofGetWidth()/2, 80);
   
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2); //zet de cirkel in het midden
    
    ofPath tArcPathWest;
    tArcPathWest.setColor(ofColor(240,200,160));
    tArcPathWest.setArcResolution(360);
    tArcPathWest.arc(30, 30, west/15, west/15, 130, 220);
    tArcPathWest.draw();
    ofSetColor(255,255,255);
    myfont.drawString("West", -30, 30);
    myfont.drawString(ofToString(west) , -30, 30 + 10);
    
    ofPath tArcPathNorth;
    tArcPathNorth.setColor(ofColor(160,220,240));
    tArcPathNorth.setArcResolution(360);
    tArcPathNorth.arc(30, 30, north/15, north/15, 220, 310);
    tArcPathNorth.draw();
    myfont.drawString("North", 10, -10);
    myfont.drawString(ofToString(north) , 10, 0);
    
    ofPath tArcPathEast;
    tArcPathEast.setColor(ofColor(190,160,200));
    tArcPathEast.setArcResolution(360);
    tArcPathEast.arc(30, 30, east/15, east/15, 310, 40);
    tArcPathEast.draw();
    myfont.drawString("East", 50, 30);
    myfont.drawString(ofToString(east) , 50, 40);
    
    ofPath tArcPathSouth;
    tArcPathSouth.setColor(ofColor(180,220,180));
    tArcPathSouth.setArcResolution(360);
    tArcPathSouth.arc(30, 30, south/15, south/15, 40, 130);
    tArcPathSouth.draw();
    myfont.drawString("South", 10, 70);
    myfont.drawString(ofToString(south) , 10, 80);
}

void ofApp::keyPressed(int key) {
    
}

void ofApp::keyReleased(int key) {
    
}

void ofApp::mouseMoved(int x, int y) {
    
}