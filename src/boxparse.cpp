#include "boxparse.h"
#include "ofApp.h"
#include <iostream>

namespace parse {


std::vector<Polygon> parsePolygons(const std::string &json, int screenw, int screenh)
{
	std::vector<Polygon> result;
	
	ofxJSONElement doc(json);

	Json::Value &objs = doc["objects"];
	Json::Value::Members objids = objs.getMemberNames();
	Json::Value::Members::const_iterator mI, mIend;

	for (mI = objids.begin(), mIend = objids.end(); mI != mIend; ++mI) {
		const Json::Value &obj = objs[*mI];
		const Json::Value &points = obj["points"];
		Polygon poly;

		for (int i = 0; i < points.size(); ++i) {
			double x = points[i]["x"].asDouble();
			double y = points[i]["y"].asDouble();
			poly.push_back(ofVec2f(x * screenw, y * screenh));
		}
		result.push_back(poly);
	}

	return result;
}


}
