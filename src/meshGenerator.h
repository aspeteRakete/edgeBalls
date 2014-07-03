// Mesh Generator - generates meshes from Images.

#pragma once
#include "ofMain.h"
#include "ofxGui.h"

class meshGenerator
{
public:
	meshGenerator();
	//~meshGenerator();
	void loadImage(string path);
	void resizeImage(int width, int height);
	void generateMesh();

	void draw();
	ofxPanel& getGuiPanel();
	//parameters
	ofParameterGroup& getParameters();
private:

	ofImage image;
	ofVboMesh mesh;

	//parameters
	ofParameterGroup parameters;
	ofParameter<int> maxNumVertices;
	ofParameter<float> intensityThreshold;
	ofParameter<float> connectionDistance;
	//gui
	ofxPanel guiPanel;
	ofxButton guiButtonRender;
};