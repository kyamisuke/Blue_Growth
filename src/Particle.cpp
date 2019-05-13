//
//  Particle.cpp
//  Blue_Growth
//
//  Created by 村上航輔 on 2019/05/13.
//

#include "Particle.h"
Particle::Particle(float x, float y, float xo, float yo){
    loc.set(x, y);
    
    float randDegrees = ofRandom(360);
    vel.set(cos(randDegrees), sin(randDegrees));
    vel *= ofRandom(10);
    
    acc.set(0, 0);
    lifeSpan = int(ofRandom(30, 90));
    this->passedLife = 0;
    decay = ofRandom(0.75, 0.9);
    c.set(ofRandom(255), ofRandom(255), 255);
    weightRange = ofRandom(3, 50);
    
    xOffset = xo;
    yOffset = yo;
}

void Particle::update() {
    if (passedLife >= lifeSpan) {
        printf("this is dead\n");
        dead = true;
    } else {
        //printf("this passes life\n");
        this->passedLife++;
        //printf("passedLife: %d", passedLife);
    }
    
    alpha = float(lifeSpan-passedLife)/lifeSpan * 70+50;
    weight = float(lifeSpan-passedLife)/lifeSpan * weightRange;
    
    acc.set(0, 0);
    
    float rn = (ofNoise((loc.x+ofGetElapsedTimeMillis()+xOffset)*0.01, (loc.y+ofGetElapsedTimeMillis()+yOffset)*0.01)-0.5)*4*PI;
    float mag = ofNoise((loc.y+ofGetElapsedTimeMillis())*0.01, (loc.x+ofGetElapsedTimeMillis())*0.01);
    
    ofVec2f dir = ofVec2f(cos(rn*DEG_TO_RAD), sin(rn*DEG_TO_RAD));
    acc += dir;
    acc *= mag;
    
    float randDegrees = ofRandom(360);
    ofVec2f randV = ofVec2f(cos(randDegrees*DEG_TO_RAD), sin(randDegrees*DEG_TO_RAD));
    randV *= 0.5;
    acc += randV;
    
    vel += acc;
    vel *= decay;
    vel.limit(3);
    this->loc += vel;
}

void Particle::display() {
    ofSetColor(0, alpha);
    ofDrawCircle(loc.x, loc.y, (weight+1.5)/2);
    
    ofSetColor(c);
    ofDrawCircle(loc.x, loc.y, weight/2);
}

