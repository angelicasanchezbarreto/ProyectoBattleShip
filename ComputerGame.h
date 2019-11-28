//
// Created by lica-pc on 11/25/19.
//

#ifndef PROYECTOBATTLESHIP_COMPUTERGAME_H
#define PROYECTOBATTLESHIP_COMPUTERGAME_H


#include "Ship.h"
#include "Game.h"

class ComputerGame{

private:

    vector<vector<casilla>> tableroPC; 

    vector<vector<casilla>> tableroRef; 

    string **computerboard;

    string **referenceboard;

    int size;

    Ship computeraircraft = Ship(4, 0, "Aircraft");

    Ship computercruiser1 = Ship(3, 0, "Cruiser");

    Ship computercruiser2 = Ship(3, 0, "Cruiser");

    Ship computertorpedo1 = Ship(1, 0, "Torpedo");

    Ship computertorpedo2 = Ship(1, 0, "Torpedo");

    Ship computertorpedo3 = Ship(1, 0, "Torpedo");
    
    Ship computertorpedo4 = Ship(1, 0, "Torpedo");
    
    Ship computersubmarine1 = Ship(2, 0, "Submarine");

    Ship computersubmarine2 = Ship(2, 0, "Submarine");
    
    Ship computersubmarine3 = Ship(2, 0, "Submarine");

public:

    void setsize(int tamano);

    void createtable();

    void printcomputer();

    void printreference();

    void settable();

    int playerturn(int counter);

};



#endif //PROYECTOBATTLESHIP_COMPUTERGAME_H
