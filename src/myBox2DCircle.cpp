#include "myBox2DCircle.h"

myBox2dCircle::myBox2dCircle():fadingOut(false)
{
    //ctor
}

myBox2dCircle::~myBox2dCircle()
{
    //dtor
}

void myBox2dCircle::draw()
{


    //ofxBox2dCircle::draw();
    if(!isBody()) return;

    if(fadingOut){
    	if(myColor.a > 10){
    		myColor.a = myColor.a - 10;
    	} else {
    		myColor.a = 0;
    	}
    }
    ofSetColor(myColor.r,myColor.g,myColor.b,myColor.a);

	ofPushMatrix();
	ofTranslate(getPosition().x, getPosition().y, 0);
	ofRotate(getRotation(), 0, 0, 1);
	ofCircle(0, 0, getRadius());

    ofPushStyle();
    ofEnableAlphaBlending();
    ofPopStyle();

	ofPopMatrix();
}

void myBox2dCircle::setup(b2World * b2dworld, float x, float y, float radius, ofColor col)
{
    myColor = col;
    ofxBox2dCircle::setup(b2dworld,x,y,radius);
}

bool myBox2dCircle::isDead()
{
    ofVec2f pos = getPosition();
    if(myColor.a == 0 || pos.x < (0-getRadius()) || pos.y < 0 || pos.x > (float(ofGetWidth()) + getRadius()) || pos.y > float(ofGetHeight())){
        return true;
    }else{
    return false;
    }
}

void myBox2dCircle::fadeOut()
{
	fadingOut = true;
}
