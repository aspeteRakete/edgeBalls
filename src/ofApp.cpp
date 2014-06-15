#include "ofApp.h"


#include "boxparse.h"
#include <fstream>
#include <string>
#include <streambuf>

//--------------------------------------------------------------
void ofApp::setup(){
	/*std::ifstream stream("data/examplelvl.json");
	std::string json((std::istreambuf_iterator<char>(stream)),
					 std::istreambuf_iterator<char>());
	//vector<parse::Polygon> polys = parse::parsePolygons(json, ofGetWidth(), ofGetHeight());*/
	
	ofSetVerticalSync(true);
	ofEnableSmoothing();
	ofBackgroundHex(0x0);
	ofSetLogLevel(OF_LOG_NOTICE);

	box2d.init();
	box2d.setGravity(0, 10);
	box2d.createGround();
	box2d.setFPS(30.0);
	box2d.registerGrabbing();


	vector<Polygon> polys = edgeIntrfc.parseFromFile(ofGetWidth(), ofGetHeight());
	for (int i=0; i < polys.size(); ++i)
	{
		/* code */
		parse::Polygon p = polys[i];
		ofPtr<ofxBox2dEdge> edge(new ofxBox2dEdge);
		ofLog() << "numPoints:" << p.size();
		for (int i = 0; i < p.size(); ++i)
		{
			edge->addVertex(p[i].x,p[i].y);
			ofLog() << "Point: " << i << " (" << p[i].x << "," << p[i].y;
		}
		//edge.addVertexes(p);
		edge->setPhysics(0.0, 0.5, 0.5);
		edge->create(box2d.getWorld());
		edgesFromEdge.push_back(edge);
	}
	ofLog() << "edges:" << edgesFromEdge.size();

	 post.init(ofGetWidth(), ofGetHeight());
	 post.createPass<FxaaPass>()->setEnabled(true);
	 post.createPass<BloomPass>()->setEnabled(false);
	 post.createPass<GodRaysPass>()->setEnabled(true);
	 post.createPass<PixelatePass>()->setEnabled(false);

}

//--------------------------------------------------------------
void ofApp::update(){
	box2d.update();


 	// remove shapes offscreen
    ofRemove(boxes, ofxBox2dBaseShape::shouldRemoveOffScreen);
    ofRemove(circles, ofxBox2dBaseShape::shouldRemoveOffScreen);
}

//--------------------------------------------------------------
void ofApp::draw(){
	//post.begin();
	//Circles
	for(int i=0; i<circles.size(); i++) {
		ofFill();
		ofSetHexColor(0x90d4e3);
		circles[i].get()->draw();
	}
	//Boxes
	for(int i=0; i<boxes.size(); i++) {
		ofFill();
		ofSetHexColor(0xe63b8b);
		boxes[i].get()->draw();
	}
	//post.end();
	//Edges
	ofNoFill();
	ofSetHexColor(0x444342);
	//ofLog() << "edges:" << edgesFromEdge.size();

	for (int i = 0; i < edgesFromEdge.size(); ++i)
	{
		edgesFromEdge[i]->updateShape();
		edgesFromEdge[i]->draw();
	}

	

	//edges
	//edgeLine.updateShape();
	//edgeLine.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if(key == 'c') {
		float r = ofRandom(4, 20);		// a random radius 4px - 20px
		circles.push_back(ofPtr<myBox2dCircle>(new myBox2dCircle));
		circles.back().get()->setPhysics(3.0, 0.53, 0.1);
		circles.back().get()->setup(box2d.getWorld(), mouseX, mouseY, r,ofColor(ofRandom(0,10),ofRandom(120,190),ofRandom(60,90)));
		
	}

	if(key == 'b') {
		float w = ofRandom(4, 20);	
		float h = ofRandom(4, 20);	
		boxes.push_back(ofPtr<ofxBox2dRect>(new ofxBox2dRect));
		boxes.back().get()->setPhysics(3.0, 0.53, 0.1);
		boxes.back().get()->setup(box2d.getWorld(), mouseX, mouseY, w, h);
	}

	if (key == 'f')
	{
		//fullscreen
		ofToggleFullscreen();
	}

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
