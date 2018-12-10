#include "Participantes.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace sf;
using namespace std;
#include "juego.h"

void Participantes::jug()
{
    ofstream filesP("base.txt");
    int cantJugadores;
    cin>> cantJugadores;
    string jugadores[cantJugadores];
    int i=0;
    while (i<cantJugadores){
        jugadores[i]="Jugador";
        i++;
    }
    for(int i=0 ; i< cantJugadores ; i++){
        filesP<<jugadores[i]<<" "<<i+1<<endl;
    }


    srand(time(NULL));
    int turno= (rand()%cantJugadores)+1;
    cout<< jugadores[turno]<<" "<<turno<< " es tu turno"<< endl;
    system("pause>nul");


}

void Participantes::seleccionrul()
{

}
