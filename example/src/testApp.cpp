#include "testApp.h"
//--------------------------------------------------------------
void testApp::setup(){
    rollCam.setup();
    ofBackground(0);
    lig.setup();
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
    lig.setPosition(0, ofGetHeight()/2, 0);
    lig.draw();
    lig.enable();
    
    rollCam.begin(); //rollCam begin
    ofEnableDepthTest();
    ofFill();
    ofSetColor(255,0,0);
    ofDrawBox(0, 0, 0, ofGetHeight()/3);
    ofNoFill();
    ofDrawBox(0, 0, 0, ofGetHeight()/3*1);
    rollCam.end();  //rollCam end
    
    lig.disable();
    ofDisableDepthTest();
    ofSetColor(255,0,0);

    ofPopMatrix();
    ofDisableLighting();
    string info = "";
    info += "PressKey 'a' : set random camera rotate.\n";
    info += "PressKey 's' : set camera position (0,0,0)\n";
    info += "PressKey 't' : toggle fullscreen\n";
    info += "Now rotate   : "+ofToString(rollCam.posN)+"\n";
    info += "Target rotate: "+ofToString(rollCam.posT)+"\n";
    ofDrawBitmapString(info, 100,100);
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key=='a') {
        rollCam.setRandom();    //Random rotate.
    }
    if (key=='s') {
        rollCam.setPos(0, 0, 0);    //Inputting optional rotate.
    }
    if (key=='f') {
        ofToggleFullscreen();
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