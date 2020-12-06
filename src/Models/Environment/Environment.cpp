//
//  Environment.cpp
//  Euclid Fractals
//
//  Created by Thomas Lawanson on 17/11/2020.
//

#include "Environment.h"

Environment::Environment(int num) : food(num + 1), grid(4, 4) {
    isTest = false;
    groundImg.load("ground.png");
    for (int i = 0; i < num; i++) {
        ofVec2f position;
        if(isTest) {
            spawn(AGENT, ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
        } else {
            spawn(SUGARCANE, ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
            spawn(SUGARCANE, ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
            
            spawn(SOYBEAN, ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
            spawn(SOYBEAN, ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
            
            spawn(POLLINATOR, ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));

            spawn(PLANT_DESTROYER, ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
        }
    }
    
    population = sugarcanes.size() + pollinators.size() + soybeans.size() + plantDestroyers.size();
}

void Environment::spawn(AgentTypeEnum type, float x, float y){
    ofVec2f position;
    position.set(x, y);
    DNA dna = DNA();
    switch (type) {
        case SUGARCANE: {
            Sugarcane sugarcane = Sugarcane(position, dna);
            sugarcanes.push_back(sugarcane);
            break;
        };
        case SOYBEAN: {
            Soybean soybean = Soybean(position,dna);
            soybeans.push_back(soybean);
            break;
        };
        case POLLINATOR: {
            Pollinator pollinator = Pollinator(position, dna);
            pollinators.push_back(pollinator);
            break;
        };
        case PLANT_DESTROYER: {
            PlantDestroyer plantDestroyer = PlantDestroyer(position,dna);
            plantDestroyers.push_back(plantDestroyer);
            break;
        };
        case JAMMER: {
            Jammer jammer = Jammer(position,dna);
            jammers.push_back(jammer);
            break;
        };
        case AGENT: {
            Agent agent = Agent(position, dna);
            agents.push_back(agent);
        }
        default:
            break;
    }

}
void Environment::setup(){
    tick.load("tick.mp3");
    tick.setLoop(false);
    tick.setVolume(0.6);
    
    pollinatorDelay = pollinatorInterval;
    fungal = true;
    fractaliser.push_back(soybeans.size());
    fractaliser.push_back(sugarcanes.size());
}

void Environment::playTick(){
    tick.play();
}

void Environment::update() {
    food.update();
    if(isTest){
        for (int i = 0; i < agents.size(); i++) {
            agents[i].update();
            int index = agents[i].isOnFood(food);
            // If agent is on food. Eat then remove the food item
            if(index > -1) {
                food.remove(index);
            }
        }
    } else {
        /*pollinatorDelay -= 1;
        if(pollinatorDelay <= 0){
            updatePollinators();
            pollinatorDelay = pollinatorInterval;
        }*/
        updatePollinators();
        updateSugarcane();
        updateSoybeans();
        updatePlantDestroyers();
        updateJammers();
    }
    grid.updatePopulation(population, numberOfDead);
    grid.update(sugarcanes, soybeans, pollinators, plantDestroyers);
}

// Run the world
void Environment::draw() {
    ofSetColor(255, 100);
    groundImg.draw(0, 0, ofGetWidth(), ofGetHeight());
    // Draw grid
    grid.draw();
    // Draw  food
    food.draw();
    if(isTest) {
        drawAgents();
    } else {
        // Draw Pollinators
        drawPollinators();
        // Draw sugarcane
        drawSugarcane();
        // Draw all plant destroyers
        drawPlantDestroyers();
        // Draw all soybeans
        drawSoybeans();
        // Draw all jammers
        drawJammers();
    }
}


void Environment::agentBorn(){
    population++;
}

void Environment::agentDead(){
    population--;
    numberOfDead++;
}


void Environment::updatePollinators(){
    for (int i = 0; i < pollinators.size(); i++) {
        pollinators[i].update();
        // Check if plant is on food
        int index = pollinators[i].isOnFood(food);
                    // If plant is on food, absorb then remove food
        if(index > -1){
            food.remove(index);
        }
        // reproduction check2
          if(pollinators[i].shouldReproduce()) {
              agentBorn();
              
              float reproductionRandomValue = ofRandom(1);
              if (reproductionRandomValue < 0.3){
                  spawn(SUGARCANE ,pollinators[i].position.x, pollinators[i].position.y);
                  pollinatorInterval -= 1;
                  if (pollinatorInterval <= 0) {
                      pollinatorInterval = 0;
                  }
              } else if(reproductionRandomValue < 0.6) {
                  spawn(SOYBEAN ,pollinators[i].position.x, pollinators[i].position.y);
                  pollinatorInterval -= 1;
                  if (pollinatorInterval <= 0) {
                      pollinatorInterval = 0;
                  }
              } else { pollinators.push_back(pollinators[i].reproduce());
                  pollinatorInterval -= 1;
                  if (pollinatorInterval <= 0) {
                      pollinatorInterval = 0;
                  }
              }
          }
       // If it's dead, kill it and make food
          if (pollinators[i].dead()) {
              agentDead();
            food.add(pollinators[i].position);
            pollinators.erase(pollinators.begin() + i);
          }

        }
}

void Environment::drawPollinators(){
    for (int i = 0; i < pollinators.size(); i++) {
      Pollinator pollinator = pollinators[i];
      pollinator.draw();
    }
}

int Environment::pollinatorPopulation(){
    return pollinators.size();
}



void Environment::updateSugarcane(){
    for (int i = 0; i < sugarcanes.size(); i++) {
        sugarcanes[i].update();
        // Check if plant is on food
        int index = sugarcanes[i].isOnFood(food);
                    // If plant is on food, absorb then remove food
        if(index > -1){
            food.remove(index);
        }

                // check for reproduction
        if(sugarcanes[i].shouldReproduce()){
                agentBorn();
            sugarcanes.push_back(sugarcanes[i].reproduce());
        }
        
        // If sugarcane dies, remove and make food
        if (sugarcanes[i].dead()) {
            agentDead();
            food.add(sugarcanes[i].position);
            sugarcanes.erase(sugarcanes.begin() + i);
        //            sugarcanes.push_back(sugarcane.reproduce());
        }
    }

}

void Environment::drawSugarcane(){
    for (int i = 0; i < sugarcanes.size(); i++) {
        Sugarcane sugarcane = sugarcanes[i];
        sugarcane.draw();

    }
}

int Environment::sugarcanePopulation(){
    return sugarcanes.size();
}

void Environment::updateSoybeans() {
    for (int i = 0; i < soybeans.size(); i++) {
        soybeans[i].update();
                
        // Check if plant is on food
        int index = soybeans[i].isOnFood(food);
                    // If plant is on food, absorb then remove food
        if(index > -1){
            food.remove(index);
        }

                // check for reproduction
        if(soybeans[i].shouldReproduce()){
            agentBorn();
            soybeans.push_back(soybeans[i].reproduce());
        }
        
                // If sugarcane dies, remove and make food
        if (soybeans[i].dead()) {
            agentDead();
            food.add(soybeans[i].position);
            soybeans.erase(soybeans.begin() + i);
        }
    }
    
    // Set fungal to false initally
    fungal = false;
    
    // Go through grid and check if alien fungi is present on cell
    for(int gridY = 0; gridY < ofGetHeight(); gridY = gridY + grid.stepY) {
        for(int gridX = 0; gridX < ofGetWidth(); gridX = gridX + grid.stepX) {
            Cell cell = grid.getCell(gridX, gridY);
            // If Cell has fungi then spawn a jammer
            if(grid.capital.isManipulating(cell)){
                // If any cell has fungi set to true
                fungal = true;
                if(ofRandom(1) < cell.jammerProductionRate) {
                    spawn(JAMMER,
                            ofRandom(cell.x, cell.x + cell.width),
                            ofRandom(cell.y, cell.y + cell.height));
//                            agentBorn();
                    cell.updateJammerProuctionRate();
                    grid.updateCell(gridX, gridY, cell);
                }
      
            }
        }
    }

    updateFractaliser();
}

void Environment::drawSoybeans(){
    for (int i = 0; i < soybeans.size(); i++) {
        Soybean soybean = soybeans[i];
        soybean.draw();

    }
}

int Environment::soybeanPopulation(){
    return soybeans.size();
}

void Environment::updatePlantDestroyers(){
    for (int i = 0; i < plantDestroyers.size(); i++) {
        plantDestroyers[i].update();
        int index = plantDestroyers[i].isOnFood(food);
        // If agent is on food. Eat then remove the food item
        if(index > -1) {
            food.remove(index);
        }

        // Check if agent is on food and remove if index > -1
          index = plantDestroyers[i].isOnSoybeans(soybeans);
          if(index > -1) {
//              agentDead();
              soybeans[index].hasBeenTouched();
//              soybeans.erase(soybeans.begin() + index);
          }
            
          index = plantDestroyers[i].isOnSugarCanes(sugarcanes);
            if(index > -1) {
//                agentDead();
                sugarcanes[index].hasBeenTouched();
//                sugarcanes.erase(sugarcanes.begin() + index);
            }
            
          // Perhaps this bloop would like to make a baby?
            if(plantDestroyers[i].shouldReproduce()) {
                agentBorn();
        plantDestroyers.push_back(plantDestroyers[i].reproduce());
            }
        
        // If it's dead, kill it and make food
        if (plantDestroyers[i].dead()) {
            agentDead();
          food.add(plantDestroyers[i].position);
          plantDestroyers.erase(plantDestroyers.begin() + i);
        }
    }
}

void Environment::drawPlantDestroyers() {
    for (int i = 0; i < plantDestroyers.size(); i++) {
      PlantDestroyer plantDestroyer = plantDestroyers[i];
      plantDestroyer.draw();

    }
}

int Environment::plantDestroyerPopulation(){
    return plantDestroyers.size();
}

void Environment::updateJammers(){
    for (int i = 0; i < jammers.size(); i++) {
        jammers[i].update();
        
    }
}

void Environment::drawJammers(){
    for (int i = 0; i < jammers.size(); i++) {
      Jammer jammer = jammers[i];
      jammer.draw();

    }
}

void Environment::drawAgents(){
    for (int i = 0; i < agents.size(); i++) {
      Agent agent = agents[i];
      agent.draw();
      // If it's dead, kill it and make food
      if (agent.dead()) {
          agentDead();
        food.add(agent.position);
        agents.erase(agents.begin() + i);
      }
        
        if(agent.shouldReproduce()) {
            agentBorn();
            agents.push_back(agent.reproduce());
        }
    }
}

void Environment::updateFractaliser(){
    if (fungal)
    {
        fractaliser.push_back(fractaliser[fractaliser.size()] + fractaliser[0]);
    }
    // check if size of soybean population has changed
    if (soybeans.size()!=fractaliser[0]){
//        cout << "fractalise" << endl;
        // if it has modify all values in fractaliser accordingly
        float popDiff = soybeans.size() - fractaliser[0];
        for (int i=0; i<fractaliser.size(); i++){
            fractaliser[i] += popDiff;
        }
    }

}
