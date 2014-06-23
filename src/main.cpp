#include "ofMain.h"
#include "ofApp.h"
#include "ofGLProgrammableRenderer.h"


#define SCREENWIDTH 1680
#define SCREENHEIGHT 1050
//========================================================================
int main( ){
	ofSetCurrentRenderer(ofGLProgrammableRenderer::TYPE);
	ofSetupOpenGL(SCREENWIDTH,SCREENHEIGHT,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
