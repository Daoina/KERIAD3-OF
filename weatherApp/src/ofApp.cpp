#include "ofApp.h"

void ofApp::setup() {
    RainImage.load("rain.png");
    ClearImage.load("clear.png");
    CloudsImage.load("clouds.png");
    SnowImage.load("snow.png");

    font.loadFont("Gotham-Book.otf", 20);

    getData();
}


void ofApp::update() {
    
    weather = json["list"][0]["weather"][0]["main"].asString();
    
}

void ofApp::draw() {
    //drawt een image van het juiste weer
    ofSetBackgroundColor(255, 255, 255);
    
    if (weather == "Clear"){
    ofSetColor(255,255,255);
    ClearImage.draw(0,0);
    }
    
    if (weather == "Clouds"){
        ofSetColor(255,255,255);
        CloudsImage.draw(0,0);
    }
    
    if (weather == "Rain"){
        ofSetColor(255,255,255);
        RainImage.draw(0,0);
    }
    
    if (weather == "Snow"){
        ofSetColor(255,255,255);
        RainImage.draw(0,0);
    }
    
    ofSetColor(155, 155, 155);
    font.drawStringCentered(weather, ofGetWidth()/2, 100);
    
    //Hij toont altijd de image van het huidige weer
}

void ofApp::keyPressed(int key) {
    
}

void ofApp::keyReleased(int key) {
    
}

void ofApp::mouseMoved(int x, int y) {
    
}

void ofApp::mousePressed(int x, int y, int button) {
    
}

void ofApp::mouseReleased(int x, int y, int button) {
    
}

void ofApp::getData() {
    string url = "http://api.openweathermap.org/data/2.5/forecast?q=Amsterdam,nl&appid=37f584c9d170b496e7abe382b2237a5a&units=metric";
    
    bool success = json.open(url);
    if (success) {
        int elementCount = json["cnt"].asInt();
        ofLog() << json["cnt"].asInt() << " elementen gekregen" << endl;
        
        for (int i = 0; i < elementCount; i++) {
            ofLog() << "Datum van element #" << i << " : " << json["list"][i]["dt_txt"] << endl;
        }
        
    } else {
        ofLog() << "Oops. No data!" << endl;
    }
}