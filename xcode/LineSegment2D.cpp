//
//  LineSegment.cpp
//  RayCastingExample
//
//  Created by Cameron Browning on 5/3/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include "LineSegment2D.h"



LineSegment2D::LineSegment2D(){ };
LineSegment2D::~LineSegment2D(){ };

void LineSegment2D::set(Vec2f start_in,Vec2f end_in){
    
    start.set(start_in);
    end.set(end_in);
}

void LineSegment2D::draw(){
       gl::drawLine(start,end);
}