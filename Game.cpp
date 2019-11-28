//
// Created by lica-pc on 11/25/19.
//

#include "Game.h"
#include "Ship.cpp"

void Game::start()
{

    cout << "Bienvenido a Battleship" << endl;

    cout << endl;

    cout << "Por favor, introduzca las dimensiones del tablero." << endl;

}

void Game::setsize() {
    int tamano;
    do{
        cin >> tamano;
    } while(tamano < 5);
    size = tamano;
}

int Game::getsize() {
    return size;
}

void Game::createtable()
{
    for (size_t i = 0; i < size; i++)
    {
        vector<casilla> vectorTemporal;
        for (size_t j = 0; j < size; j++)
        {
            casilla casillaTemporal; 
            vectorTemporal.push_back(casillaTemporal);
        }
        tableroJugador.push_back(vectorTemporal); 
    }
    
}

void Game::printplayer()
{
    for (int i = 0; i < size; ++i) {

        for (int j = 0; j < size; ++j) {

            cout << setw(2) << tableroJugador[i][j].getChar();
        }
        cout << endl;
    }
}


void Game::settable() {

    playerbattleship.setship(tableroJugador, size);
    printplayer();

    playercruiser.setship(tableroJugador, size);

    printplayer();

    playercruiser1.setship(tableroJugador, size);

    printplayer();

    playerdestroyer.setship(tableroJugador, size);

    printplayer();

    playerdestroyer1.setship(tableroJugador, size);

    printplayer();

    playerdestroyer2.setship(tableroJugador, size);

    printplayer();

    playersubmarine.setship(tableroJugador, size);

    printplayer();

    playersubmarine1.setship(tableroJugador, size);

    printplayer();
}


int Game::computerturn(int counter)
{
    int x = rand()%size;

    int y = rand()%size;

    if(tableroJugador[y][x].isAttacked()) computerturn(counter);

    else
    {

        if (tableroJugador[y][x].isOccupied()){

            cout << "La computadora ha acertado" << endl;

            tableroJugador[y][x].attackHit();

            printplayer();

            counter++;

            computerdoubleturn(counter, x, y);
        }

        else

        {
            if (!tableroJugador[y][x].isOccupied())
            {

                cout << "La computadora fallo, es tu turno" << endl;

                tableroJugador[y][x].attackMiss();
            }
        }
    }

    return counter;

}

int Game::computerdoubleturn(int counter, int x, int y)
{
    int cx = x;

    int cy = y;

    int variable = rand()%4;

    if (variable == 0) cx++;

    else
    {
        if (variable == 1) cx -= 1;

        else
        {
            if (variable == 2) cy++;

            else cy -= 1;

        }
    }

    if (cx >= size || cx < 0 || cy >= size || cy < 0) computerdoubleturn(counter, x, y);

    if(tableroJugador[cy][cx].isAttacked()) computerturn(counter);

    else

    {

        if (tableroJugador[cy][cx].isOccupied()){

            cout << "La computadora ha acertado" << endl;

            tableroJugador[cy][cx].attackHit();

            printplayer();

            counter++;

            computerdoubleturn(counter, cx, cy);

        }

        else

        {
            if (!tableroJugador[cy][cx].isOccupied())

            {
                cout << "La computadora fallo, es tu turno" << endl;

                tableroJugador[cy][cx].attackMiss();
            }
        }

    }

    return counter;

}
