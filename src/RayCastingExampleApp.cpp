#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Ray2d.h"
#include "LineSegment2D.h"
#include "cinder/Rand.h"

//using namespace ci::Rand;
using namespace ci;
using namespace ci::app;
using namespace std;

class RayCastingExampleApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    Ray2D ray;
    int numWalls;
    float wallLength;
    LineSegment2D * walls;
    Vec2f RayToLineSegmentIntersection(float x1_, float y1_, float x2_, float y2_, 
                                       float x3_, float y3_, float x4_, float y4_);


};

void RayCastingExampleApp::setup()
{
    numWalls = 50;
    walls = new LineSegment2D[numWalls];
    
    for(int i=0;i<numWalls;i++){
        float x1 = Rand::randFloat()*640.0f;
        float y1 = Rand::randFloat()*640.0f;
        walls[i].set(Vec2f(x1,y1),Vec2f(Rand::randFloat()*200.0f-100.0f+x1,Rand::randFloat()*200.0f-100.0f+y1));   
    
    }
    ray.set(320,240,0);

    
    
}

void RayCastingExampleApp::mouseDown( MouseEvent event )
{
}

void RayCastingExampleApp::update()
{
    ray.update();
    
    
}

void RayCastingExampleApp::draw()
{

    // clear out the window with black
	
    gl::clear( Color( 1.0,1.0,1.0 ) ); 
    
    
    for(int i=0;i<numWalls;i++){
       
        
        //cout << walls[i].end.x << endl;
       
        Vec2f apt = ray.getSecondPoint();
        Vec2f intersect = RayToLineSegmentIntersection(ray.x,ray.y,apt.x,apt.y,walls[i].start.x,walls[i].start.y,walls[i].end.x,walls[i].end.y);
    
        
        if(intersect.x>-998){
            gl::color(Color(0.2f,0.4f,1.0f));
            gl::drawStrokedCircle(intersect,3,32);
        } else {
             gl::color(Color(0.2,0.3,0.25));
        }
        walls[i].draw();
        
    }
    

    
    gl::color(Color(1.0,0.5,0.2));
    ray.draw();

}


Vec2f RayCastingExampleApp::RayToLineSegmentIntersection(float x1_, float y1_, float x2_, float y2_, 
                                                float x3_, float y3_, float x4_, float y4_)
{
	Vec2f result;
    result.set(-999,-999);
	float r, s, d;
	// Make sure the lines aren't parallel
	if ((y2_ - y1_) / (x2_ - x1_) != (y4_ - y3_) / (x4_ - x3_))
	{
		d = (((x2_ - x1_) * (y4_ - y3_)) - (y2_ - y1_) * (x4_ - x3_));
		if (d != 0)
		{
			r = (((y1_ - y3_) * (x4_ - x3_)) - (x1_ - x3_) * (y4_ - y3_)) / d;
			s = (((y1_ - y3_) * (x2_ - x1_)) - (x1_ - x3_) * (y2_ - y1_)) / d;
			if (r >= 0)
			{
				if (s >= 0 && s <= 1)
				{
					result.set(x1_ + r * (x2_ - x1_), y1_ + r * (y2_ - y1_));
				}
			}
		}
	}
	return result;
}


CINDER_APP_BASIC( RayCastingExampleApp, RendererGl )
