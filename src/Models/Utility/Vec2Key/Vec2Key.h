//
//  Vec2Key.h
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 21/11/2020.
//

#ifndef Vec2Key_h
#define Vec2Key_h

#include <stdio.h>
#include "ofMain.h"

class Vec2Key
{
    
public:
    float x;
    float y;
    
    Vec2Key( float xValue, float yValue );
    
    bool operator < ( const Vec2Key& other) const
    {
        if ( x == other.x ) {
            return y < other.y;
        }
        
        return x < other.x;
    }
    
    ofVec2f getOfVec2f();

    
};
#endif /* Vec2Key_h */
