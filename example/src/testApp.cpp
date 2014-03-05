#include "testApp.h"
//--------------------------------------------------------------
void testApp::setup(){
    rollCam.setup();//rollCam's setup.
    rollCam.setCamSpeed(0.1);//rollCam's speed set;
    ofBackground(0);
    lig.setup();
    
    float r=ofGetHeight()*0.8;
    for (int i=0; i<300; i++) {
        ofVec3f newPos;
        newPos.set(ofRandomf()*r,ofRandomf()*r,ofRandomf()*r);
        pos.push_back(newPos);
    }
}

//--------------------------------------------------------------
void testApp::update(){
    rollCam.update();   //rollCam's rotate update.
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255);
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetWidth()/2);
    ofEnableLighting();
    lig.setPosition(0, -ofGetHeight()/2, ofGetHeight()/3);
    lig.draw();
    lig.enable();
    ofPopMatrix();
    
    rollCam.begin(); //rollCam begin
    ofEnableDepthTest();
    ofFill();
    ofSetColor(255,0,0);
    ofDrawBox(0, 0, 0, ofGetHeight()/3);
    
    for (int i=0; i<pos.size(); i++) {
        ofFill();
        if (i%3==0)ofNoFill();
        ofSetColor(ofColor::fromHsb(255*((float)i/pos.size()), 150, 255));
        ofDrawBox(pos[i].x, pos[i].y, pos[i].z, ofGetHeight()/20);
    }
    
    ofNoFill();
    ofDrawBox(0, 0, 0, ofGetHeight()/3*1);
    rollCam.end();  //rollCam end
    
    lig.disable();
    ofDisableDepthTest();
    ofSetColor(255,0,0);

    ofPopMatrix();
    ofDisableLighting();
    if(!hide){
    string info = "";
    info += "PressKey '1' : set camera all random.\n";
    info += "PressKey '2' : set random camera rotate.\n";
    info += "PressKey '3' : set camera position (0,0,0)\n";
    info += "PressKey '4' : set random camera distance.\n";
    info += "PressKey '5' : set camera distance by window height.\n";
    info += "PressKey 'f' : toggle fullscreen.\n";
    info += "PressKey 'd' : hide explanation.\n";
    info += "Now Angle    : "+ofToString(rollCam.posN)+"\n";
    ofDrawBitmapString(info, 10,10);
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key=='1') {//All Random.
        rollCam.setRandomScale(0.5, 1.5);
        rollCam.setRandomPos(270);
    }
    if (key=='2') {//Random rotate.
        rollCam.setRandomPos(270);
    }
    if (key=='3') {//Inputting optional rotate.
        rollCam.setPos(0, 0, 0);
    }
    if (key=='4') {//Random distance.
        rollCam.setRandomScale(0.5, 1.5);
    }
    if (key=='5') {//Inputting optional distance.
        rollCam.setScale(1);
    }

    if (key=='f') {
        ofToggleFullscreen();
    }
    if (key=='h') {
        hide= !hide;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}