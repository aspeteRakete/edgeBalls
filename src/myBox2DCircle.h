#pragma once

#include "ofMain.h"
#include "ofxBox2dCircle.h"
#include "ofxBox2d.h"


class myBox2dCircle : public ofxBox2dCircle
{
    public:
        myBox2dCircle();
        virtual ~myBox2dCircle();
        void draw();
        void setup(b2World * b2dworld, float x, float y, float radius, ofColor col);
        bool isDead();
        ofColor myColor;
        void fadeOut();
    protected:
    private:
        bool fadingOut;

};
