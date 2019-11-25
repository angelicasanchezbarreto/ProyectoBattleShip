//
// Created by lica-pc on 11/25/19.
//

#include "Ship.h"

Ship::Ship(int tamano, int dano, string nombre) {size = tamano; damage = dano; name = nombre;}

void Ship::dmg() {damage += 1; cout << "Le has dado a " << name;}

int Ship::getsize() {return size;}

string Ship::getname() {return name;}

void Ship::setship(string **array, int area)

{   int x;

    int y;

    char o;

    do{cout << "Ingrese sus coordenada X para su " << name << endl;

        cin >> x;

        cout << "Ingrese su coordenada Y para su " << name << endl;

        cin >> y;

        cout << "Ingrese su orientacion (H o V) para su " << name << endl;

        cin >> o;}

    while((o == 'H' && (x + size > area - 1 || y > area)) || ((o == 'V' && (y + size > area || x > area ))) || (o != 'H' && o != 'V'));

    cx = x;

    cy = y;

    orientation = o;

    locate(array, area);}


void Ship::setcomputership(string **array, int area)
{
    int x; int y; char o;

    do{
        x = rand()%area; y = rand()%area;

        if (rand()%2 == 1) o = 'H'; else o = 'V';}

    while((o == 'H' && (x + size - 1 > area - 1 || y > area - 1)) || ((o == 'V' && (y + size - 1 > area - 1|| x > area - 1))) || (o != 'H' && o != 'V'));

    cx = x;

    cy = y;

    orientation = o;

    locatecomputer(array, area);
}


void Ship::locate(string **array, int area)

{
    if (check(array, area)) {

        if (orientation == 'V')

            for (int i = 0; i < size; i++) { array[cy + i][cx] = "o "; }

        else

            for (int i = 0; i < size; i++) { array[cy][cx + i] = "o "; }

    }

    else {

        cout << "Ya hay un barco en esta posición, por favor, vuelve a poner los numeros" << endl;

        setship(array, area);
    }
}

void Ship::locatecomputer(string **array, int area)

{
    if (check(array, area)) {

        if (orientation == 'V')

            for (int i = 0; i < size; i++) { array[cy + i][cx] = "o "; }

        else

            for (int i = 0; i < size; i++) { array[cy][cx + i] = "o "; }

    }

    else {

        setcomputership(array, area);

    }
}



bool Ship::check(string **array, int area)

{
    bool flag = true;

    for(int i = cx; i < size; i++) {

        if (array[cy][i] == "o ") {

            flag = false;

            return flag;
        }

    }

    return flag;
}

