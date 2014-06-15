#pragma once

#include "ofMain.h"
#include "ofxJSONElement.h"

typedef std::vector<ofVec2f> Polygon;

class edgeInterface {
public:
	
	const std::string edgeUrl = "http://192.168.1.100:8080/scene";
	const std::string testFile = "examplelvl.json";

	std::vector<Polygon> parsePolygons(int screenw, int screenh);
	std::vector<Polygon> parseFromFile(int screenw, int screenh);
	std::vector<Polygon> parseFromEdge(int screenw, int screenh);

private:
	ofxJSONElement currentData;

};