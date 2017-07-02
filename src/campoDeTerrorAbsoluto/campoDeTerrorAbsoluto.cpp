//
//  campoDeTerrorAbsoluto.cpp
//  deOsosLiveAct_v2
//
//  Created by Oscar David Bravo Peña on 6/20/17.
//
//

#include "campoDeTerrorAbsoluto.h"

void campoDeTerrorAbsoluto::setup(){
    ofxDelaunay t;
    triangulation.push_back(t);
    minX = ofRandom(-5,4)*100;
    maxX = minX + 100;
    minY = ofRandom(-5,4)*100;
    maxY = minY + 100;
    minZ = ofRandom(-5,4)*100;
    maxZ = minZ + 100;
    for (int i = 0;  i < 3; i++) {
        ofPoint p( ofRandom(minX,maxX),ofRandom(minY,maxY), ofRandom(minZ,maxZ));
        triangulation[polygonCounter].addPoint( p );
        triangulation[polygonCounter].triangulate();
        if (i == 0) {
            constelation.push_back(p);
        }
    }
}

void campoDeTerrorAbsoluto::newsetup(){
    ofxDelaunay t;
    triangulation.push_back(t);
    minX = ofRandom(-5,4)*100;
    maxX = minX + 100;
    minY = ofRandom(-5,4)*100;
    maxY = minY + 100;
    minZ = ofRandom(-5,4)*100;
    maxZ = minZ + 100;
    for (int i = 0;  i < 3; i++) {
        ofPoint p( ofRandom(minX,maxX),ofRandom(minY,maxY), ofRandom(minZ,maxZ));
        triangulation[polygonCounter].addPoint( p );
        triangulation[polygonCounter].triangulate();
        if (i == 0) {
            constelation.push_back(p);
        }
    }
}

void campoDeTerrorAbsoluto::update(){
    
}

void campoDeTerrorAbsoluto::draw(){
    ofNoFill();
    for (int i = 0; i < triangulation.size(); i++) {
        ofSetLineWidth(0);
        ofSetColor(200);
        triangulation[i].draw();
        if (constelation.size() > 1) {
            for (int i = 0; i < constelation.size()-1; i++) {
                ofSetLineWidth(0);
                ofSetColor(255);
                ofDrawLine(constelation[i], constelation[i+1]);
            }
        }
    }
}

void campoDeTerrorAbsoluto::exit(){
    
}
