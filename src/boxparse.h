#pragma once
#include <vector>
#include <string>
#include "ofxJSONElement.h"

namespace parse {
const std::string edgeUrl = "192.168.1.00:8080/scene"
//typedef std::pair<int, int> Vertex;
typedef std::vector<ofPoint> Polygon;


std::vector<Polygon> parsePolygons(const std::string &json);


}
