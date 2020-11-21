//
//  DNA.h
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 17/11/2020.
//

#ifndef DNA_h
#define DNA_h

#include "ofMain.h"
#include <stdio.h>

class DNA {
    public:
        vector<float> genes;

        DNA();
        void set(vector<float> newGenes);
        DNA copy();
        void mutate(float m);
};
#endif /* DNA_h **/
