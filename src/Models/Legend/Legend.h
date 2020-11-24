//
//  Legend.h
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 23/11/2020.
//

#ifndef Legend_h
#define Legend_h

#include "ofMain.h"
class Legend {
    public:
        Legend();
        void draw();
        void toggleShow();
    protected:
        void drawBackground();
        void drawIcons();
        bool show;
        int margin = 20;
        int spacing = 40;
};
#endif /* Legend_h */
