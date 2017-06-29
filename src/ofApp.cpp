#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    myFont.load("PTSans.ttc", 18);
    
    std::string url = "https://whispering-mesa-52741.herokuapp.com/twitter/search/hasse%20filter:media/de/51.2876179,6.7646025,20km";
    // Now parse the JSON
    bool parsingSuccessful = result.open(url);
    
    if (parsingSuccessful)
    {
        ofLogNotice("ofApp::setup") << result.getRawString();
    }
    else
    {
        ofLogNotice("ofApp::setup")  << "Failed to parse JSON" << endl;
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    ofSetColor(100,100,100);
    
    if (result.isMember("errors"))
    {
        ofDrawBitmapString(result.getRawString(), 10, 14);
    }
    else if (result.isObject())
    {
        const Json::Value& trends = result["statuses"];
        //cout << trends.size() << endl;
//        for (int i = 0; <#condition#>; <#increment#>) {
//            <#statements#>
//        }
        for (Json::ArrayIndex i = 0; i < trends.size(); ++i){
            std::string date = trends[i]["created_at"].asString();
            std::string message = trends[i]["text"].asString();
            myFont.drawString(message, 10, 40*i+40);
            //ofDrawBitmapString(message, 10, 40*i+40);
            ofDrawBitmapString(date, 10, 40*i+60);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
