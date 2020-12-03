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
        ofImage plantDestroyerImg;
        ofImage soybeanImg;
        ofImage sugarcaneImg;
        ofImage pollinatorImg;
        ofImage foodImg;
        ofImage capitalImg;
        ofImage fungiImg;
        int population = 0;
        int numberOfDead = 0;
    
        Legend();
        void draw();
        void update(int _population, int _numberOfDead);
        void toggleShow();
    protected:
        void drawBackground();
        void drawIcons();
        bool show;
        int margin = 20;
        int spacing = 40;
};
#endif /* Legend_h */
