//
// Created by lica-pc on 11/25/19.
//

#ifndef PROYECTOBATTLESHIP_GAME_H
#define PROYECTOBATTLESHIP_GAME_H


#include "Ship.h"
#include "casilla.h"

class Game {

private:

    vector<vector<casilla>> tableroJugador; 

    string **playerboard;

    int size;

    Ship playeraircraft = Ship(4, 0, "Aircraft");

    Ship playercruiser1 = Ship(3, 0, "Cruiser");

    Ship playercruiser2 = Ship(3, 0, "Cruiser");

    Ship playertorpedo1 = Ship(1, 0, "Torpedo");

    Ship playertorpedo2 = Ship(1, 0, "Torpedo");

    Ship playertorpedo3 = Ship(1, 0, "Torpedo");

    Ship playertorpedo4 = Ship(1, 0, "Torpedo");

    Ship playersubmarine1 = Ship(2, 0, "Submarine");

    Ship playersubmarine2 = Ship(2, 0, "Submarine");

    Ship playersubmarine3 = Ship(2, 0, "Submarine");

public:

    void start();

    void setsize();

    int getsize();

    void createtable();

    void printplayer();

    void settable();

    int computerturn(int counter);

    int computerdoubleturn(int counter, int x, int y);

};



#endif //PROYECTOBATTLESHIP_GAME_H
