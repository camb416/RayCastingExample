//
//  Ray2D.h
//  RayCastingExample
//
//  Created by Cameron Browning on 5/3/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//
#ifndef _RAY2D
#define _RAY2D

#include "cinder/gl/gl.h"
using namespace ci;

class Ray2D : public Vec3f{
    
public:
    // float x;
    // float y;
    // float z; // use as rotation value
   // Ray2D();
   // ~Ray2D();
    void draw();
    void update();
    Vec2f getSecondPoint();
    
};

#endif