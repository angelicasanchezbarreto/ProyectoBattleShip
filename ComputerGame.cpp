//
// Created by lica-pc on 11/25/19.
//

#include "ComputerGame.h"

void ComputerGame::setsize(int tamano) {size = tamano;}

void ComputerGame::createtable()
{
    computerboard = new string *[size];
    referenceboard = new string*[size];

    for (int k = 0; k < size; ++k)
    {
        computerboard[k] = new string[size];

        referenceboard[k] = new string[size];
    }

    for (int i = 0; i < size; ++i) {

        for (int j = 0; j < size; ++j) {

            computerboard[i][j] = "~ ";

            referenceboard[i][j] = "~ ";

        }

    }

}

void ComputerGame::printcomputer()
{

    for (int i = 0; i < size; ++i) {

        for (int j = 0; j < size; ++j) {

            cout << computerboard[i][j];

        }

        cout << endl;
    }
}


void ComputerGame::printreference()
{
    for (int i = 0; i < size; ++i) {

        for (int j = 0; j < size; ++j) {

            cout << referenceboard[i][j];
        }

        cout << endl;

    }
}

void ComputerGame::settable()
{
    computerbattleship.setcomputership(computerboard, size);

    computercruiser.setcomputership(computerboard, size);

    computercruiser1.setcomputership(computerboard, size);

    computerdestroyer.setcomputership(computerboard, size);

    computerdestroyer1.setcomputership(computerboard, size);

    computerdestroyer2.setcomputership(computerboard, size);

    computersubmarine.setcomputership(computerboard, size);

    computersubmarine1.setcomputership(computerboard, size);


}

int ComputerGame::playerturn(int counter)
{
    printreference();

    int x, y;

    cout << "Inserte la coordenada X de su ataque" << endl;

    cin >> x;
    x=x-1;

    cout << "Inserte la coordenada Y de su ataque" << endl;

    cin >> y;
    y = y-1;

    if (x >= size || y >= size)

    {
        cout << "No puedes disparar ahí" << endl;

        playerturn(counter);
    }

    else

    {

        if (computerboard[y][x] == "o "){

            cout << "Has acertado" << endl;

            computerboard[y][x] = "+ ";

            referenceboard[y][x] = "+ ";

            counter++;

            playerturn(counter);

        }

        else

        {
            if (computerboard[y][x] == "~ ")
            {
                cout << "Has fallado" << endl;

                referenceboard[y][x] = "- ";
            }

            else
            {
                if (referenceboard[y][x] == "+ " || referenceboard[y][x] == "- ") {

                    cout << "Ya has disparado aqui." << endl;

                    playerturn(counter);

                }

            }

        }

    }

    return counter;

}


