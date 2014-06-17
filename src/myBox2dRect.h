#pragma once
#include "ofMain.h"
#include "ofxBox2dRect.h"

class myBox2dRect : public ofxBox2dRect
{
public:
	myBox2dRect(ofColor color,ofImage* textureImage);
	//void setup();
	//overwrite draw method
	void draw();
	void printVertices();

private:
	ofColor color;
	ofImage* textureImage;
};