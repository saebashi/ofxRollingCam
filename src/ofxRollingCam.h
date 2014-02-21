/*
 *  ofxRollingCam.h
 *
 *  Copyright (c) 2014, saebashi, https://twitter.com/saebashi
 *  All rights reserved.
*/
#pragma once


#ifndef __ofxRollingCam__
#define __ofxRollingCam__

#include <iostream>
#include "ofMain.h"
#define DEFAULT_CAM_SP 0.1
class ofxRollingCam : public ofBaseApp{
public:
    ofxRollingCam();
    void setup(float _distance=ofGetHeight(),float _camSpeed=DEFAULT_CAM_SP);
    void update();
    void begin();
    void end();
    void setCamSpeed(float _camSpeed);
    void setRandom(float _randomAngle=180);
    void setPos(float _x,float _y,float _z);


    ofEasyCam cam;
    
    ofVec3f posN,posT,posS;
    ofLight lig;
    float camSpeed;
};
#endif
