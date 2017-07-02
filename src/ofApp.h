#pragma once

#include "ofMain.h"
#include "ofxMidi.h"
#include "campoDeTerrorAbsoluto/campoDeTerrorAbsoluto.h"
#include "ofxCartesianCylindricalSpherical.h"
#include "ofxSyphon.h"

class ofApp : public ofBaseApp, public ofxMidiListener{

public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void exit();
    //////-------MIDI-------//////
    void newMidiMessage(ofxMidiMessage& eventArgs);
    ofxMidiMessage midiMessage;
    ofxMidiIn ableton;
    ofxMidiIn nanoKontrol2;
    void midiSetup();
    //////-------CAMERA-------//////
    ofEasyCam cam;
    ofxCartesianCylindricalSpherical actualCamPosition;
    ofxCartesianCylindricalSpherical nextCamPosition;
    ofxCartesianCylindricalSpherical velocity;
    ofxCartesianCylindricalSpherical actualTarget;
    ofxCartesianCylindricalSpherical nextTarget;
    ofxSyphonServer mainOutputSyphonServer;
    //////-------CAMPO DE TERROR-------//////
    bool campoDeTerror;
    int constelationCounter;
    vector<campoDeTerrorAbsoluto> campo;
    void campoDeTerror_midiEvents(ofxMidiMessage msg);
};
