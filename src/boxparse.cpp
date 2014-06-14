#include "boxparse.h"
#include <iostream>

namespace parse {


std::vector<Polygon> parsePolygons(const std::string &json)
{
	ofxJSONElement doc(json);

	Json::Value &objs = doc["objects"];
	Json::Value::Members objids = objs.getMemberNames();
	Json::Value::Members::const_iterator mI, mIend;

	for (mI = objids.begin(), mIend = objids.end(); mI != mIend; ++mI) {
		const Json::Value &id = objs[*mI]["id"];
		std::cout << "ID: " << id.asInt() << std::endl;
	}

	return std::vector<Polygon>();
}


}
