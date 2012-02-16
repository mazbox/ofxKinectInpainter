#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	kinect.init();
	kinect.open();
	
	inpainter.setup(kinect.getWidth(), kinect.getHeight());
	depthImg.allocate(kinect.getWidth(), kinect.getHeight());
	inpaintedImg.allocate(kinect.getWidth(), kinect.getHeight());
}

//--------------------------------------------------------------
void testApp::update(){
	float t = ofGetElapsedTimef();
	kinect.update();
	
	depthImg.setFromPixels(kinect.getDepthPixels(), kinect.getWidth(), kinect.getHeight());
	
	inpaintedImg = depthImg;
	inpainter.inpaint(inpaintedImg);
	ofSetWindowTitle(ofToString(ofGetFrameRate(), 2)+"fps - Inpainting radius: " 
					 + ofToString(inpainter.getInpaintingRadius()) + "px    downsampling: " 
					 + ofToString((inpainter.getDownsampling())) + ":1");
}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetHexColor(0xFFFFFF);
	depthImg.draw(0, 0);
	inpaintedImg.draw(depthImg.getWidth(), 0);
	ofSetHexColor(0xFF0000);
	ofDrawBitmapString("Raw Kinect View", 20, 20);
	
	ofDrawBitmapString("Inpainted Kinect View", depthImg.getWidth() + 20, 20);
	
	ofEnableAlphaBlending();
	glColor4f(0, 0, 0, 0.7);
	ofRect(10, ofGetHeight()-30, 540, 15);
	ofSetHexColor(0x44CC44);
	ofDrawBitmapString("Move your mouse to change the inpaint radius and downsample factor", 20, ofGetHeight()-20);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	inpainter.setInpaintingRadius(ofMap(x, 0, ofGetWidth(), 1, 10, true));
	inpainter.setDownsampling(ofMap(y, 0, ofGetHeight(), 1, 20, true));
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