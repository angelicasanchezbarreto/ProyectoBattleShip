//
// Created by lica-pc on 11/25/19.
//

#include "ComputerGame.h"

void ComputerGame::setsize(int tamano) {size = tamano;}

void ComputerGame::createtable()
{
    for (size_t i = 0; i < size; i++)
    {
        vector<casilla> vectorTemporal;
        for (size_t j = 0; j < size; j++)
        {
            casilla casillaTemporal; 
            vectorTemporal.push_back(casillaTemporal);
        }
        tableroPC.push_back(vectorTemporal); 
        tableroRef.push_back(vectorTemporal); 
    }
}

void ComputerGame::printcomputer()
{

    for (int i = 0; i < size; ++i) {

        for (int j = 0; j < size; ++j) {

            cout << setw(2) << tableroPC[i][j].getChar();
        }

        cout << endl;
    }
}


void ComputerGame::printreference()
{
    for (int i = 0; i < size; ++i) {

        for (int j = 0; j < size; ++j) {

            cout << setw(2) <<tableroRef[i][j].getChar();
        }

        cout << endl;

    }
}

void ComputerGame::settable()
{
    computerbattleship.setcomputership(tableroPC, size);

    computercruiser.setcomputership(tableroPC, size);

    computercruiser1.setcomputership(tableroPC, size);

    computerdestroyer.setcomputership(tableroPC, size);

    computerdestroyer1.setcomputership(tableroPC, size);

    computerdestroyer2.setcomputership(tableroPC, size);

    computersubmarine.setcomputership(tableroPC, size);

    computersubmarine1.setcomputership(tableroPC, size);


}

int ComputerGame::playerturn(int counter)
{
    printreference();

    int x, y;

    cout << "Inserte la coordenada X de su ataque" << endl;

    cin >> x;

    cout << "Inserte la coordenada Y de su ataque" << endl;

    cin >> y;

    if (x >= size || y >= size)

    {
        cout << "No puedes disparar ahí" << endl;

        playerturn(counter);
    }

    else

    {
        if (tableroRef[y][x].isAttacked()) 
        {

            cout << "Ya has disparado aqui." << endl;

            playerturn(counter);

        }
        else
        {

            if (tableroPC[y][x].isOccupied()){

                cout << "Has acertado" << endl;

                tableroPC[y][x].attackHit();

                tableroRef[y][x].attackHit();

                counter++;

                playerturn(counter);

            }

            else
            {
                if (!tableroPC[y][x].isOccupied())
                {
                    cout << "Has fallado" << endl;

                    tableroRef[y][x].attackMiss();
                }

                else
                {
                    if (tableroRef[y][x].isAttacked()) {

                        cout << "Ya has disparado aqui." << endl;

                        playerturn(counter);

                    }

                }

            }
        }

    }

    return counter;

}


