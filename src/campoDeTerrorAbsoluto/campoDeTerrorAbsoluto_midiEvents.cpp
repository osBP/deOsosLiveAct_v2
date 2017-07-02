//
//  campoDeTerrorAbsoluto_midiEvents.cpp
//  deOsosLiveAct_v2
//
//  Created by Oscar David Bravo Peña on 6/21/17.
//
//

#include "ofApp.h"

void ofApp::campoDeTerror_midiEvents(ofxMidiMessage msg){
    ofPoint p;
    ofxDelaunay t;
    switch (msg.status) {
        case MIDI_CONTROL_CHANGE:
            switch (msg.channel) {
                case 1:
                    switch (msg.control) {
                        case 1:
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
            break;
        case MIDI_NOTE_ON:
            switch (msg.channel) {
                case 2:
                    switch (msg.pitch) {
                        case 36:
                            campo[constelationCounter].triangulation[campo[constelationCounter].polygonCounter].addPoint( ofPoint( ofRandom(campo[constelationCounter].minX,campo[constelationCounter].maxX),ofRandom(campo[constelationCounter].minY,campo[constelationCounter].maxY), ofRandom(campo[constelationCounter].minZ,campo[constelationCounter].maxZ) ) );
                            campo[constelationCounter].triangulation[campo[constelationCounter].polygonCounter].triangulate();
                        case 38:
                            campo[constelationCounter].triangulation[campo[constelationCounter].polygonCounter].addPoint( ofPoint( ofRandom(campo[constelationCounter].minX,campo[constelationCounter].maxX),ofRandom(campo[constelationCounter].minY,campo[constelationCounter].maxY), ofRandom(campo[constelationCounter].minZ,campo[constelationCounter].maxZ) ) );
                            campo[constelationCounter].triangulation[campo[constelationCounter].polygonCounter].triangulate();
                            break;
                        case 39:
                            campo[constelationCounter].polygonCounter++;
                            campo[constelationCounter].triangulation.push_back(t);
                            campo[constelationCounter].minX = ofRandom(-5,4)*100;
                            campo[constelationCounter].maxX = campo[constelationCounter].minX + 100;
                            campo[constelationCounter].minY = ofRandom(-5,4)*100;
                            campo[constelationCounter].maxY = campo[constelationCounter].minY + 100;
                            campo[constelationCounter].minZ = ofRandom(-5,4)*100;
                            campo[constelationCounter].maxZ = campo[constelationCounter].minZ + 100;
                            for (int i = 0;  i < 4; i++) {
                                p = ofPoint( ofRandom(campo[constelationCounter].minX,campo[constelationCounter].maxX), ofRandom(campo[constelationCounter].minY,campo[constelationCounter].maxY), ofRandom(campo[constelationCounter].minZ,campo[constelationCounter].maxZ));
                                campo[constelationCounter].triangulation[campo[constelationCounter].polygonCounter].addPoint( p );
                                nextCamPosition.point = p;
                                campo[constelationCounter].triangulation[campo[constelationCounter].polygonCounter].triangulate();
                                if (i == 0) {
                                    campo[constelationCounter].constelation.push_back(p);
                                    nextTarget.point = p;
                                }
                            }
                            break;
                        case 40:
                            constelationCounter++;
                            campoDeTerrorAbsoluto c;
                            campo.push_back(c);
                            campo[constelationCounter].newsetup();
                            nextTarget.point = campo[constelationCounter].constelation[0];
                            nextCamPosition.point = nextTarget.point;
                            break;
//                        default:
//                            break;
                    }
                    break;
                default:
                    break;
            }
            break;
        case MIDI_NOTE_OFF:
            switch (msg.channel) {
                case 1:
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }

}
