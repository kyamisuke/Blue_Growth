//
//  Particle.h
//  Blue_Growth
//
//  Created by 村上航輔 on 2019/05/13.
//

#pragma once

#include "ofMain.h"

class Particle : public ofBaseApp{
    
public:
    ofVec2f loc, vel, acc;
    int lifeSpan, passedLife;
    bool dead;
    float alpha, weight, weightRange, decay, xOffset, yOffset;
    ofColor c;
    int frameCount=0;

    
    Particle(float x, float y, float xo, float yo);
    void update();
    void display();
};
