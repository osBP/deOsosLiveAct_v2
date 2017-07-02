#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    campoDeTerror = true;
    actualCamPosition.point = ofPoint(1000,1000,1000);
    cam.setPosition(actualCamPosition.point);
    actualTarget.point = ofPoint(0,0,0);
    midiSetup();
    campoDeTerrorAbsoluto c;
    cout<<" c created "<<endl;
    campo.push_back(c);
    constelationCounter = 0;
    campo[constelationCounter].setup();
    nextTarget.point = campo[constelationCounter].constelation[0];
    nextCamPosition.point = nextTarget.point;
    ofEnableSmoothing();
    ofSetLineWidth(0);
    ofHideCursor();
    mainOutputSyphonServer.setName("Screen Output");
}

//--------------------------------------------------------------
void ofApp::update(){
    actualTarget.point += (nextTarget.point - actualTarget.point) * (0.01);
    cam.setTarget(actualTarget.point);
    actualCamPosition.point += (nextCamPosition.point - actualCamPosition.point) * (0.001);
    cam.setPosition(actualCamPosition.point);
    //cout<<"lens offset: x"<<cam.getLensOffset().x<<"lens offset: y"<<cam.getLensOffset().y<<endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ofBackground(0);
    cam.begin();
    for (int i = 0; i < campo.size(); i++) {
        campo[i].draw();
    }
    cam.end();
    mainOutputSyphonServer.publishScreen();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::exit(){
    
}
