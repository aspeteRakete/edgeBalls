#include "boxparse.h"
#include <iostream>

namespace parse {


std::vector<Polygon> parsePolygons(const std::string &json)
{
	ofxJSONElement doc(json);

	Json::Value &objs = doc["objects"];
	Json::Value::const_iterator i, iend;

	std::cout << "NUM OBJECTS" << objs.size() << std::endl;

	for (i = objs.begin(), iend = objs.end(); i != iend; ++i) {
		const Json::Value &id = (*i)["id"];
		std::cout << "ID: " << id.asInt() << std::endl;
	}

	return std::vector<Polygon>();
}


}
