#pragma once
#include <vector>
#include <string>
#include "ofxJSONElement.h"

namespace parse {

typedef std::pair<int, int> Vertex;
typedef std::vector<Vertex> Polygon;


std::vector<Polygon> parsePolygons(const std::string &json, int screenw, int screenh);


}
