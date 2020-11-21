//
//  Vec2Key.c
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 21/11/2020.
//

#include "Vec2Key.h"
Vec2Key::Vec2Key( float xValue, float yValue ){
    x = xValue;
    y = yValue;
}

ofVec2f Vec2Key::getOfVec2f() {
    return ofVec2f(x, y);
}


