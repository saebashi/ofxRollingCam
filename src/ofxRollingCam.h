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
    void setup(float _camSpeed=DEFAULT_CAM_SP,float _distance=ofGetHeight());
    void update();
    void begin();
    void end();
    void setCamSpeed(float _camSpeed);
    void setRandomPos(float _randomAngle=180);
    void setPos(float _x,float _y,float _z);
    void setRandomDist(float _min,float _max);
    void setDistance(float _dist);


    ofEasyCam cam;
    
    ofVec3f posN,posT,posS;
    ofLight lig;
    float camSpeed;
    float distN,distT,distS;
};
#endif
