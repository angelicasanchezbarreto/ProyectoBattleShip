#ifndef PROYECTOBATTLESHIP_CASILLA_H
#define PROYECTOBATTLESHIP_CASILLA_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector> 
#include <iomanip>
using namespace std; 

class casilla
{
    private:
        bool ocuppied; 
        char showChar; 
        bool attempted; 
    public:
        casilla()
        {
            ocuppied = false; 
            showChar = 'm';
            attempted = false; 
        }
        char getChar()
        {
            return showChar; 
        }
        void ocupar(char shipName)
        {
            ocuppied = true; 
            showChar = shipName;
        }
        bool isOccupied()
        {
            return ocuppied; 
        }
        void attackHit()
        {
            attempted = true; 
            showChar = '+';
        }
        void attackMiss()
        {
            attempted = true;
            showChar = '-'; 
        }
        bool isAttacked()
        {
            return attempted;
        }
};

#endif //PROYECTOBATTLESHIP_CASILLA_H