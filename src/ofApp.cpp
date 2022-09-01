#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofEnableAlphaBlending();
    ofBackground(30);
    ofSetLineWidth(1.5);

    for (int i = 0; i < 3; i++)
    {
        arcs.push_back(new Arc());
    }
}

//--------------------------------------------------------------
void ofApp::update()
{
    for (Arc *a : arcs)
    {
        a->update();
    }

    // video_recorder.record("/home/ezequiel/Videos/arcs");
}

//--------------------------------------------------------------
void ofApp::draw()
{
    for (Arc *a : arcs)
    {
        a->draw();
    }
}

void ofApp::exit()
{
    // video_recorder.stopRecording();
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if (key == OF_KEY_F1)
    {
        video_recorder.stopRecording();
    }
}
//
// //--------------------------------------------------------------
// void ofApp::keyReleased(int key){
//
// }
//
// //--------------------------------------------------------------
// void ofApp::mouseMoved(int x, int y ){
//
// }
//
// //--------------------------------------------------------------
// void ofApp::mouseDragged(int x, int y, int button){
//
// }
//
// //--------------------------------------------------------------
// void ofApp::mouseReleased(int x, int y, int button){
//
// }
//
// //--------------------------------------------------------------
// void ofApp::mouseEntered(int x, int y){
//
// }
//
// //--------------------------------------------------------------
// void ofApp::mouseExited(int x, int y){
//
// }
//
// //--------------------------------------------------------------
// void ofApp::windowResized(int w, int h){
//
// }
//
// //--------------------------------------------------------------
// void ofApp::gotMessage(ofMessage msg){
//
// }
//
// //--------------------------------------------------------------
// void ofApp::dragEvent(ofDragInfo dragInfo){
//
// }
