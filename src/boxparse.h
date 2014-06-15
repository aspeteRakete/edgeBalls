#pragma once
#include <vector>
#include <string>
#include "ofxJSONElement.h"

namespace parse {
const std::string edgeUrl = "http://192.168.1.100:8080/scene";

//typedef std::pair<int, int> Vertex;
typedef std::vector<ofVec2f> Polygon;


std::vector<Polygon> parsePolygons(const std::string &json, int screenw, int screenh);


}
