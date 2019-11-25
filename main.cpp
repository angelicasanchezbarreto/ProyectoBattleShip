#include "Game.cpp"
#include "ComputerGame.cpp"

int main() {

    int a = 0;

    int b = 0;

    srand(time(NULL));

    Game Juego;

    ComputerGame Juego1;

    Juego.start();

    Juego.setsize();

    Juego1.setsize(Juego.getsize());

    Juego.createtable();

    Juego1.createtable();

    cout << "Este es tu tablero, por favor, posiciona tus barcos." << endl;

    Juego.printplayer();

    Juego.settable();

    Juego1.settable();

    cout << "La computadora ha posicionado sus barcos." << endl;

    cout << "Este es tu tablero de referencia. Suerte!" << endl;

    do{a = Juego1.playerturn(a);

        b = Juego.computerturn(b); }while(a < 18 && b < 18);

    if (a == 18) cout << "Ganaste";

    else cout << "Perdiste";

    cout << "Fin del juego.";


}
