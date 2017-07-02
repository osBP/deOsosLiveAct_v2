//
//  midiShit.cpp
//  deOsosLiveAct_v2
//
//  Created by Oscar David Bravo Peña on 6/20/17.
//
//

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::midiSetup(){
    ableton.listPorts();
    ableton.openPort("Driver IAC visualsBus");
    ableton.ignoreTypes(false, false, false);
    ableton.addListener(this);
    ableton.setVerbose(false);
    nanoKontrol2.openPort("nanoKONTROL2 SLIDER/KNOB");
    nanoKontrol2.ignoreTypes(false, false, false);
    nanoKontrol2.addListener(this);
    nanoKontrol2.setVerbose(false);
}

//--------------------------------------------------------------
void ofApp::newMidiMessage(ofxMidiMessage &eventArgs){
    midiMessage = eventArgs;
    if (midiMessage.status == MIDI_NOTE_ON && midiMessage.channel == 14) {
        
    }
    else{
        if (campoDeTerror) {
            campoDeTerror_midiEvents(midiMessage);
        }
    }
}
