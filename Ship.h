//
// Created by lica-pc on 11/25/19.
//

#ifndef PROYECTOBATTLESHIP_SHIP_H
#define PROYECTOBATTLESHIP_SHIP_H

#include "casilla.h"

using namespace std;

class Ship {

private:

    int size;

    int damage;

    char orientation;

    int cx;

    int cy;

    string name;

public:

    Ship(int tamano, int dano, string nombre);

    void dmg();

    int getsize();

    string getname();

    bool check(vector<vector<casilla>> board, int area);

    void setship(vector<vector<casilla>> &board, int area);

    void setcomputership(vector<vector<casilla>> &board, int area);

    void locate(vector<vector<casilla>> &board, int area);

    void locatecomputer(vector<vector<casilla>> &board, int area);

};



#endif //PROYECTOBATTLESHIP_SHIP_H
