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
    playerboard = new string*[size];

    for (int k = 0; k < size; ++k)

    {
        playerboard[k] = new string[size];

    }

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            playerboard[i][j] = "~ ";

        }

    }
}

void Game::printplayer()
{
    for (int i = 0; i < size; ++i) {

        for (int j = 0; j < size; ++j) {

            cout << playerboard[i][j];
        }

        cout << endl;

    }
}


void Game::settable() {

    playerbattleship.setship(playerboard, size);

    printplayer();

    playercruiser.setship(playerboard, size);

    printplayer();

    playercruiser1.setship(playerboard, size);

    printplayer();

    playerdestroyer.setship(playerboard, size);

    printplayer();

    playerdestroyer1.setship(playerboard, size);

    printplayer();

    playerdestroyer2.setship(playerboard, size);

    printplayer();

    playersubmarine.setship(playerboard, size);

    printplayer();

    playersubmarine1.setship(playerboard, size);

    printplayer();}


int Game::computerturn(int counter)
{
    int x = rand()%size;

    int y = rand()%size;


    if (playerboard[y][x] == "o "){

        cout << "La computadora ha acertado" << endl;

        playerboard[y][x] = "+ ";

        printplayer();

        counter++;

        computerdoubleturn(counter, x, y);

    }

    else

    {
        if (playerboard[y][x] == "~ ")
        {

            cout << "La computadora fallo, es tu turno" << endl;

            playerboard[y][x] = "- ";
        }

        else
        {

            if(playerboard[y][x] == "+ " || playerboard[y][x] == "- ") computerturn(counter);

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

    else

    {

        if (playerboard[cy][cx] == "o "){

            cout << "La computadora ha acertado" << endl;

            playerboard[cy][cx] = "+ ";

            printplayer();

            counter++;

            computerdoubleturn(counter, cx, cy);

        }

        else

        {
            if (playerboard[cy][cx] == "~ ")

            {
                cout << "La computadora fallo, es tu turno" << endl;

                playerboard[cy][cx] == "- ";
            }

            else

            {
                if(playerboard[cy][cx] == "+ " || playerboard[cy][cx] == "- ") computerturn(counter);
            }
        }

    }

    return counter;

}
