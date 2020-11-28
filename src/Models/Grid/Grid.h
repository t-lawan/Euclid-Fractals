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

class Grid {
    public:
        int numX = 50;
        int numY = 50;
        int plantThreshold = 10;
        int stepX;
        int stepY;
        int maxNumberOfPlantsOnCell = 0;
        Grid(int _numX, int _numY);
        void draw();
        void update(vector<Sugarcane> _sugarcanes,  vector<Soybean> _soybeans);
        void setupCells();
        Cell getCell(int x, int y);
        void setMaxNumberOfPlants();
    
        Cell checkIfPlantsAreOnCell(Cell cell,
                                    vector<Sugarcane> _sugarcanes,
                                    vector<Soybean> _soybeans);
        vector<Cell> findCellsWithHighNumberOfPlants();
        void acceleratePlantsOnCells(
                                     vector<Cell> cellsWithHighNumberOfPlants,
                                     vector<Sugarcane> _sugarcanes,
        
                                     vector<Soybean> _soybeans);
        void updateCell(int x, int y, Cell newCell);
        map<Vec2Key, Cell> cells;
};
#endif /* Grid_h */
