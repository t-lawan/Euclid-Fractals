//
//  Grid.h
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 17/11/2020.
//

#ifndef Grid_h
#define Grid_h

#include <stdio.h>
#include "ofMain.h"
#include "Cell.h"
#include "Vec2Key.h"
#include "Sugarcane.h"
#include "Soybean.h"
#include "Capital.h"
#include "AlienFungi.h"
#include "Pollinator.h"
#include "PlantDestroyer.h"

class Grid {
    public:
        int numX = 50;
        int numY = 50;
        int plantThreshold = 10;
        int stepX;
        int stepY;
        int maxNumberOfPlantsOnCell = 0;
        int population = 0;
        int numOfDead = 0;
        Capital capital;
        AlienFungi alienFungi;
    
        map<Vec2Key, Cell> cells;
        Grid(int _numX, int _numY);
    
        vector<Cell> convertCellsMapToVector();
        void draw();
        void update(
                    vector<Sugarcane> _sugarcanes,
                    vector<Soybean> _soybeans,
                    vector<Pollinator> _pollinators,
                    vector<PlantDestroyer> _plantDestroyers
                    );
        void updateCells(vector<Sugarcane> _sugarcanes,  vector<Soybean> _soybeans);
    void updatePopulation(int _population, int _numOfDead);
        void setupCells();
        Cell getCell(int x, int y);
        void updateCell(int x, int y, Cell newCell);
};
#endif /* Grid_h */
