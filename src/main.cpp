#include "ofMain.h"
#include "ofApp.h"

#include "boxparse.h"
#include <fstream>
#include <string>
#include <streambuf>

//========================================================================
int main( ){
	std::ifstream stream("data/examplelvl.json");
	std::string json((std::istreambuf_iterator<char>(stream)),
					 std::istreambuf_iterator<char>());
	parse::parsePolygons(json);
	
	ofSetupOpenGL(800,600,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
