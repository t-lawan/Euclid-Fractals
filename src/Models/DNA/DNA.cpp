//
//  DNA.cpp
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 17/11/2020.
//

#include "DNA.h"

DNA::DNA(){
    float seed = ofRandom(0,1);
    genes.push_back(seed);
}

void DNA::set(vector<float> newGenes) {
    genes = newGenes;
}

DNA DNA::copy(){
    vector<float> newGenes;
    for(int i = 0; i < genes.size(); i++) {
        newGenes.push_back(genes[i]);
    }
    
    DNA dna;
    dna.set(newGenes);
    return dna;
}

void DNA::mutate(float m) {
    for(int i = 0; i < genes.size(); i++) {
        if(ofRandom(1) < m) {
            genes[i] = ofRandom(0,1);
        }
    }
}

