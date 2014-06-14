#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofxBox2d                                box2d;			  //	the box2d world
		ofPolyline                              drawing;		  //	we draw with this first
		ofxBox2dEdge                            edgeLine;		  //	the box2d edge/line shape (min 2 points)
		vector <ofPtr<ofxBox2dEdge> >			edgesFromEdge;		// edges from the edge
		vector      <ofPtr<ofxBox2dCircle> >    circles;          //    default box2d circles
		vector      <ofPtr<ofxBox2dRect> >      boxes;            //    defalut box2d rects
		
};
