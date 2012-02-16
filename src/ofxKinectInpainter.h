
#pragma once
#include "ofxCvGrayscaleImage.h"

class ofxKinectInpainter {
public:
	ofxKinectInpainter();
	/**
	 * The amount of downsampling will determine the quality.
	 * 4 is quarter-sized, but real-time.
	 */
	void setup(int width = 640, int height = 480, int downsampling = 4);
	
	/**
	 * This is a parameter of the inpainting algorithm, the higher the better
	 * but the higher the most computationally expensive.
	 */
	void setInpaintingRadius(int radius);
	void setDownsampling(int downsampling);
	
	int getInpaintingRadius();
	int getDownsampling();
	
	void inpaint(ofxCvGrayscaleImage &img);
private:
	ofxCvGrayscaleImage scaled;
	ofxCvGrayscaleImage mask;
	ofxCvGrayscaleImage scaledMask;
	
	ofxCvGrayscaleImage inpainted;
	float scale;
	int width;
	int height;
	static const int DEFAULT_INPAINT_RADIUS = 3;
	int inpaintRadius;
};