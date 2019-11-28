//
// Created by lica-pc on 11/25/19.
//

#include "Ship.h"

Ship::Ship(int tamano, int dano, string nombre) {size = tamano; damage = dano; name = nombre;}

void Ship::dmg() {damage += 1; cout << "Le has dado a " << name;}

int Ship::getsize() {return size;}

string Ship::getname() {return name;}

void Ship::setship(vector<vector<casilla>> &board, int area)

{   int x;

    int y;

    char o;

    do{
        cout << "Ingrese sus coordenada X para su " << name << endl;
        cin >> x;

        cout << "Ingrese su coordenada Y para su " << name << endl;
        cin >> y;

        cout << "Ingrese su orientacion (H o V) para su " << name << endl;
        cin >> o;}

    while((o == 'H' && (x + size > area - 1 || y > area)) || ((o == 'V' && (y + size > area || x > area ))) || (o != 'H' && o != 'V'));

    cx = x;

    cy = y;

    orientation = o;

    locate(board, area);
}


void Ship::setcomputership(vector<vector<casilla>> &board, int area)
{
    int x; int y; char o;

    do{
        x = rand()%area; y = rand()%area;

        if (rand()%2 == 1) o = 'H'; else o = 'V';}

    while((o == 'H' && (x + size - 1 > area - 1 || y > area - 1)) || ((o == 'V' && (y + size - 1 > area - 1|| x > area - 1))) || (o != 'H' && o != 'V')); //Corregir 

    cx = x;

    cy = y;

    orientation = o;

    locatecomputer(board, area);
}


void Ship::locate(vector<vector<casilla>> &board, int area)

{
    if (check(board, area)) 
    {
        if (orientation == 'V')
        {
            for (int i = 0; i < size; i++) 
            {
                board[cy + i][cx].ocupar(name[0]);
            }
        }
        else
        {
            for (int i = 0; i < size; i++) 
            {
                board[cy][cx + i].ocupar(name[0]);
            }
        }
    }

    else 
    {
        cout << "Ya hay un barco en esta posición, por favor, vuelve a poner los numeros" << endl;
        setship(board, area);
    }
}

void Ship::locatecomputer(vector<vector<casilla>> &board, int area)

{
    if (check(board, area)) 
    {
        if (orientation == 'V'){

            for (int i = 0; i < size; i++) 
                board[cy + i][cx].ocupar(name[0]);
        }
        else{

            for (int i = 0; i < size; i++) 
                board[cy][cx + i].ocupar(name[0]);
        }
    }

    else 
    {
        setship(board, area);
    }
}



bool Ship::check(vector<vector<casilla>> board, int area)
{
    if (orientation == 'V')
    {
        for (int i = 0; i < size; i++)
        {
            if(board[cy+i][cx].isOccupied())
                return false; 
        }
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if(board[cy][cx+i].isOccupied())
                return false; 
        }
    }
    return true; 
}

