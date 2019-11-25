//
// Created by lica-pc on 11/25/19.
//

#ifndef PROYECTOBATTLESHIP_SHIP_H
#define PROYECTOBATTLESHIP_SHIP_H


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

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

    bool check(string **array, int area);

    void setship(string **array, int area);

    void setcomputership(string **array, int area);

    void locate(string **array, int area);

    void locatecomputer(string **array, int area);

};



#endif //PROYECTOBATTLESHIP_SHIP_H
