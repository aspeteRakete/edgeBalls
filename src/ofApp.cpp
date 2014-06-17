#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	
	ofSetVerticalSync(true);
	ofEnableSmoothing();
	ofBackgroundHex(0x0);
	ofSetLogLevel(OF_LOG_NOTICE);

	box2d.init();
	box2d.setGravity(0, 10);
	box2d.createGround();
	box2d.setFPS(30.0);
	box2d.registerGrabbing();


	polys = edgeIntrfc.parseFromFile(ofGetWidth(), ofGetHeight());
	processEdges();
	/*for (int i=0; i < polys.size(); ++i)
	{
		Polygon p = polys[i];
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
	ofLog() << "edges:" << edgesFromEdge.size();*/

	 post.init(ofGetWidth(), ofGetHeight());
	 post.createPass<FxaaPass>()->setEnabled(true);
	 post.createPass<BloomPass>()->setEnabled(false);
	 post.createPass<GodRaysPass>()->setEnabled(true);
	 post.createPass<PixelatePass>()->setEnabled(false);

	 ofDisableArbTex();
	 textureImage.loadImage("edge.png");
	 //textureImage.getTextureReference().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
     //textureImage.getTextureReference().setTextureWrap(GL_REPEAT, GL_REPEAT);


	//midi
	/*lp.listPorts();
	//lp.openPort(1);
	lp.openPort("Launchpad 24:0");
	lp.addListener(this);
	lp.setVerbose(true);*/

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
	//textureImage.draw(0,0,100,100);
	for(int i=0; i<circles.size(); i++) {
		ofFill();
		ofSetHexColor(0x90d4e3);
		circles[i].get()->draw();
	}
	//Boxes
	for(int i=0; i<boxes.size(); i++) {
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

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if(key == 'c') {
		float r = ofRandom(4, 20);		// a random radius 4px - 20px
		circles.push_back(ofPtr<myBox2dCircle>(new myBox2dCircle));
		circles.back().get()->setPhysics(3.0, 0.53, 0.1);
		circles.back().get()->setup(box2d.getWorld(), mouseX, mouseY, r,ofColor(ofRandom(190,210),ofRandom(50,70),ofRandom(0,12)));
		
	}

	if(key == 'b') {
		float w = ofRandom(40, 60);	
		float h = w;
		boxes.push_back(ofPtr<myBox2dRect>(new myBox2dRect(ofColor(ofRandom(10,20),ofRandom(170,190),ofRandom(50,70)),&textureImage)));
		boxes.back().get()->setPhysics(3.0, 0.53, 0.1);
		boxes.back().get()->setup(box2d.getWorld(), mouseX, mouseY, w, h);
		//boxes.back().get()->printVertices();
	}

	if (key == 'f')
	{
		//fullscreen
		ofToggleFullscreen();
	}

	if(key == 'u')
	{
		//update edge from edge
		polys = edgeIntrfc.parseFromEdge(ofGetWidth(), ofGetHeight());
		edgesFromEdge.clear();
		processEdges();

	}

}
void ofApp::processEdges()
{
	for (int i=0; i < polys.size(); ++i)
		{
			Polygon p = polys[i];
			ofPtr<ofxBox2dEdge> edge(new ofxBox2dEdge);
			ofLog() << "numPoints:" << p.size();
			for (int i = 0; i < p.size(); ++i)
			{
				edge->addVertex(p[i].x,p[i].y);
				ofLog() << "Point: " << i << " (" << p[i].x << "," << p[i].y;
			}
			//close Poly
			edge->addVertex(p[0].x,p[0].y);

			//edge.addVertexes(p);
			edge->setPhysics(0.0, 0.5, 0.5);
			edge->create(box2d.getWorld());
			edgesFromEdge.push_back(edge);
		}
		ofLog() << "edges:" << edgesFromEdge.size();
}

void ofApp::newMidiMessage(ofxMidiMessage& eventArgs){
	ofLog() << "Midi Message Received. velocity:" <<eventArgs.velocity << " - pitch: " << eventArgs.pitch; 
	float r = ofRandom(4,20);		// a random radius 4px - 20px
	circles.push_back(ofPtr<myBox2dCircle>(new myBox2dCircle));
	circles.back().get()->setPhysics(3.0, 0.53, 0.1);
	int x = (eventArgs.pitch) * (ofGetWidth() / 120);
	int y = 10;
	circles.back().get()->setup(box2d.getWorld(), x, y, r,ofColor(ofRandom(190,210),ofRandom(50,70),ofRandom(0,12)));
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
