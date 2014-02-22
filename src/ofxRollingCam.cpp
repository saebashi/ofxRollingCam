/*
 *  ofxRollingCam.cpp
 *
 *  Copyright (c) 2014, saebashi, https://twitter.com/saebashi
 *  All rights reserved.
 */

#include "ofxRollingCam.h"
//--------------------------------------------------------------

ofxRollingCam::ofxRollingCam(){
    cam.disableMouseInput();
    distN=ofGetHeight();
    distT=distN;
    cam.setDistance(ofGetHeight());
    camSpeed=DEFAULT_CAM_SP;
    
}
//--------------------------------------------------------------
void ofxRollingCam::setup(float _camSpeed,float _distance){
    cam.disableMouseInput();
    distN=_distance;
    distT=distN;
    camSpeed=ofClamp(_camSpeed,0,1);
}

//--------------------------------------------------------------
void ofxRollingCam::update(){
    posS.set(posT.x-posN.x,posT.y-posN.y,posT.z-posN.z);
    posS.set(posS.x*camSpeed,posS.y*camSpeed,posS.z*camSpeed);
    posN.set(posN.x+posS.x, posN.y+posS.y,posN.z+posS.z);
    
    distS=distT-distN;
    distS=distS*camSpeed;
    distN=distN+distS;
    cam.setDistance(distN);
}
//--------------------------------------------------------------

void ofxRollingCam::begin(){
    ofPushMatrix();
    cam.begin();
    ofRotateX(posN.x);
    ofRotateY(posN.y);
    ofRotateZ(posN.z);
}
//--------------------------------------------------------------

void ofxRollingCam::end(){
    cam.end();
    ofPopMatrix();
    
}
//--------------------------------------------------------------

void ofxRollingCam::setCamSpeed(float _camSpeed){
    camSpeed=ofClamp(_camSpeed,0,1);
}
//--------------------------------------------------------------

void ofxRollingCam::setRandomPos(float _randomAngle){
    ofVec3f ram3f;
    int ramSize=_randomAngle;
    ram3f.set(ofRandom(-ramSize, ramSize),ofRandom(-ramSize, ramSize),ofRandom(-ramSize, ramSize));
    posT.set(ofRandom(posN.x,(int)(posN.x+ram3f.x)%360), ofRandom(posN.y,(int)(posN.y+ram3f.y)%360),ofRandom(posN.z,(int)(posN.z+ram3f.z)%360));
}
//--------------------------------------------------------------

void ofxRollingCam::setPos(float _x,float _y,float _z){
    posT.set(_x,_y,_z);
}
//--------------------------------------------------------------

void ofxRollingCam::setRandomDist(float _min,float _max){
    distT=ofRandom(_min,_max);
}
//--------------------------------------------------------------

void ofxRollingCam::setDistance(float _dist){
    distT=_dist;
}

//--------------------------------------------------------------
//void testApp::mousePressed(int x, int y, int button){
//    camSetRandom();
//}

