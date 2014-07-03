#include "meshGenerator.h"
//#include "string.h"

meshGenerator::meshGenerator(){
	//Setup parameters and GUI

	guiPanel.setup("meshControl");
	parameters.add(maxNumVertices.set("MaximumVertices", 2000,0,20000));
	parameters.add(intensityThreshold.set("intensityThreshold", 150, 1, 255));
	parameters.add(connectionDistance.set("connectionDistance" , 30 , 1, 70));

	guiPanel.add(parameters);
	guiButtonRender.addListener(this,&meshGenerator::generateMesh);
	guiPanel.add(guiButtonRender.setup("Render"));
}

void meshGenerator::loadImage(string path){
	image.loadImage(path);
}

void meshGenerator::resizeImage(int width, int height){
	image.resize(width,height);
}

void meshGenerator::generateMesh(){
	mesh.clear();

	mesh.setMode(OF_PRIMITIVE_LINES);
	 
    vector<ofVec3f> potentialPoints;
    int w = image.getWidth();
    int h = image.getHeight();
    for (int x=0; x<w; ++x) {
        for (int y=0; y<h; ++y) {
            ofColor c = image.getColor(x, y);
            float intensity = c.getLightness();
            if (intensity >= intensityThreshold) {
            	potentialPoints.push_back(ofVec3f(x,y,ofRandom(-50,100)));
                /*ofVec3f pos(x, y, 0.0);
                mesh.addVertex(pos);
                mesh.addColor(c);*/
            }
        }
    }

    //pick random points to add
    for (int i = 0; i < maxNumVertices; ++i)
    {
    	int index = (int) ofRandom(0,potentialPoints.size()-1);
    	//ofLog() << index ;
    	ofVec3f pos = potentialPoints[index];
    	mesh.addVertex(pos);
    	mesh.addColor(image.getColor(pos.x,pos.y));
    }

    // Let's add some lines!
	int numVerts = mesh.getNumVertices();
	for (int a=0; a<numVerts; ++a) {
	    ofVec3f verta = mesh.getVertex(a);
	    for (int b=a+1; b<numVerts; ++b) {
	        ofVec3f vertb = mesh.getVertex(b);
	        float distance = verta.distance(vertb);
	        if (distance <= connectionDistance) {
	            mesh.addIndex(a);
	            mesh.addIndex(b);
	        }
	    }
	}
}

void meshGenerator::draw(){
	mesh.draw();
}

ofParameterGroup& meshGenerator::getParameters(){
	return parameters;
}

ofxPanel& meshGenerator::getGuiPanel(){
	return guiPanel;
}
