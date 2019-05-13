#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(30);

    ofBackground(0);
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    if (ofGetMousePressed()){
        for (int i=0; i < 1; i++) {
            Particle newP = Particle(mouseX, mouseY, i+pts.size(), i+pts.size());
            pts.push_back(newP);
        }
    }
    
    for (int i=0; i<pts.size(); i++) {
        Particle p = pts[i];
//        printf("lifespan %d\n", p.lifeSpan);
        printf("point ( %f, %f )\n", p.loc.x, p.loc.y);
        p.update();
        p.display();
    }
    
    for (int i=pts.size()-1; i > -1; i--) {
        Particle p = pts[i];
        if (p.dead) {
//            printf("dead %d", i);
            pts[i] = pts.back();
            pts.pop_back();
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'c') pts.clear();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
