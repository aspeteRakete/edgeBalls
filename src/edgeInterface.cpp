#include <edgeInterface.h>

std::vector<Polygon> edgeInterface::parsePolygons(int screenw, int screenh)
{
	std::vector<Polygon> result;
	
	ofxJSONElement doc;
	doc.openRemote(edgeUrl);

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

std::vector<Polygon> edgeInterface::parseFromFile(int screenw, int screenh)
{
	std::vector<Polygon> result;

	currentData.openLocal(testFile);

	Json::Value &objs = currentData["objects"];
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

std::vector<Polygon> edgeInterface::parseFromEdge(int screenw, int screenh)
{
	std::vector<Polygon> result;
	
	currentData.openRemote(edgeUrl);

	Json::Value &objs = currentData["objects"];
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