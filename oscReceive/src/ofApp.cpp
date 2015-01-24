#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground( 255, 255, 255 );
    
    receiver.setup(PORT);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    string msg = "";
    msg += "FPS: " + ofToString( ofGetFrameRate() ) + "\n";
    msg += "receiver: " + ofToString( receiver.hasWaitingMessages() ) + "\n";
    
    // OSCの個数分繰り返す
    int index = 0;
    while(receiver.hasWaitingMessages()) {
        
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        string value = m.getArgAsString(index);
        // msg += "getAddress: " + m.getAddress() + "\n";
        // msg += "getArgAsString " + ofToString(index) + ": " + value + "\n";
        
        if( index == 0 ){
            getFFT = ofMap( ofToFloat( m.getArgAsString(index) ), -90, 0, 0, 1 );
        }
        
        index++;
    }
    
    // ビジュアライズ
    drawVisual();
    
    msg += "FFT: " + ofToString( getFFT ) + "\n";
    ofSetColor( 0, 0, 0, 255 );
    ofDrawBitmapString( msg, 30, 30 );
}

//--------------------------------------------------------------
void ofApp::drawVisual(){
    
    float ww = ofGetWidth();
    float wh = ofGetHeight();
    
    ofCircle( ww * 0.5, wh * 0.5, 100 * getFFT );
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}