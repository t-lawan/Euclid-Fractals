//
//  BarChart.hpp
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 02/12/2020.
//

#ifndef BarChart_h
#define BarChart_h

#include "ofMain.h"
#include <algorithm>
#include <stdio.h>

class BarChart {
    public:
        ofImage plantDestroyerImg;
        ofImage soybeanImg;
        ofImage sugarcaneImg;
        ofImage pollinatorImg;

        int pollinatorPop = 2;
        int plantdestroyerPop = 5;
        int sugarcanePop = 10;
        int soybeanPop = 6;
        int minPopulation = 2;
        int maxPopulation = 10;
    
        BarChart();
        void draw();
        void update(int _sugarcanePop, int _soybeanPop, int _plantdestroyerPop, int _pollinatorPop);
        void toggleShow();
    protected:
        void drawBackground();
        void drawBars();
        bool show;
        int margin = 5;
        int spacing = 20;
        int textSpacing = 150;
};
#endif /* BarChart_h */
