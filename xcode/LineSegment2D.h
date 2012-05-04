//
//  LineSegment.h
//  RayCastingExample
//
//  Created by Cameron Browning on 5/3/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//
#ifndef _LineSegment2D
#define _LineSegment2D

#include "cinder/gl/gl.h"

using namespace ci;

class LineSegment2D{
public:
    LineSegment2D();
    ~LineSegment2D();
    void set(Vec2f start_in,Vec2f end_in);
    void draw();
    Vec2f start;
    Vec2f end;
};

#endif