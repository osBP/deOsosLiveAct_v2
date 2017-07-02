//
//  campoDeTerrorAbsoluto.h
//  deOsosLiveAct_v2
//
//  Created by Oscar David Bravo Peña on 6/20/17.
//
//

#ifndef campoDeTerrorAbsoluto_h
#define campoDeTerrorAbsoluto_h

#include "ofMain.h"
#include "ofxDelaunay.h"

class campoDeTerrorAbsoluto {
public:
    campoDeTerrorAbsoluto(){
        cout<<"new child"<<endl;
    };
    void setup();
    void newsetup();
    void update();
    void draw();
    void exit();
    
    vector<ofxDelaunay> triangulation;
    vector<ofPoint> constelation;
    unsigned int polygonCounter = 0;
    int minX,maxX,minY,maxY,minZ,maxZ;
};

#endif /* campoDeTerrorAbsoluto_h */
