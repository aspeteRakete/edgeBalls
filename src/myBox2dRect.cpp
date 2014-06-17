#include "myBox2dRect.h"

myBox2dRect::myBox2dRect(ofColor color, ofImage* img):color(color){
	textureImage = img;
}

void myBox2dRect::draw(){
	
	if(body == NULL) {
		return;	
	}

	ofPushStyle();
	ofSetColor(color);
	ofNoFill();
	mesh.clearTexCoords();
	mesh.addTexCoord(ofVec2f(0,1));
	mesh.addTexCoord(ofVec2f(1,0));
	mesh.addTexCoord(ofVec2f(1,1));
	mesh.addTexCoord(ofVec2f(0,0));
    
    ofPushMatrix();
    ofTranslate(ofxBox2dBaseShape::getPosition());
    ofRotate(getRotation());
    textureImage->bind();
    mesh.draw();
    textureImage->unbind();
    //mesh.drawWireframe();
    ofPopMatrix();
    ofPopStyle();
}

void myBox2dRect::printVertices(){
	ofLog() << "Vertices: ";
	for (int i = 0; i < mesh.getNumVertices(); ++i)
	{
		ofLog() << mesh.getVertex(i);
	}
}