//
//  Controls.h
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 28/11/2020.
//

#ifndef Controls_h
#define Controls_h

#include "ofMain.h"
class Controls {
    public:
        ofImage plantDestroyerImg;
        ofImage soybeanImg;
        ofImage sugarcaneImg;
        ofImage pollinatorImg;
        Controls();
        void draw();
        void update();
        void toggleShow();
    protected:
        void drawBackground();
        void drawInstructions();
        bool show;
        int margin = 20;
        int spacing = 50;
        int textSpacing = 150;
};

#endif /* Controls_h */
