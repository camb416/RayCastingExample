//
//  Ray2D.cpp
//  RayCastingExample
//
//  Created by Cameron Browning on 5/3/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include "Ray2D.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace gl;

void Ray2D::update(){
    z += 1.0f;
}

Vec2f Ray2D::getSecondPoint(){
    return Vec2f(x+cos(z*M_PI/180.0f)*30.0f,y+sin(z*M_PI/180.0f)*30.0f);
}

void Ray2D::draw(){
    /*
        float lineVerts[3*2];
        glEnableClientState( GL_VERTEX_ARRAY );
        glVertexPointer( 3, GL_FLOAT, 0, lineVerts );
        lineVerts[0] = 0; lineVerts[1] = 0; lineVerts[2] = 0;
        lineVerts[3] = 100; lineVerts[4] = 100; lineVerts[5] = 0; 
        glDrawArrays( GL_LINES, 0, 2 );
        glDisableClientState( GL_VERTEX_ARRAY );
    */
    
   // gl::drawStrokedCircle(,5,32);
    
    gl::pushMatrices();
    gl::translate(Vec2f(x,y));
    gl::drawSolidCircle(Vec2f(0,0),2,32);
    gl::rotate(z);
    gl::drawLine(Vec2f(0,0),Vec2f(100,0));
    gl::popMatrices();
}