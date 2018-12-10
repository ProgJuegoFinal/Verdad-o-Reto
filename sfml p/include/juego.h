#ifndef JUEGO_H
#define JUEGO_H
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
#include "Participantes .h"

class juego
{
    public:
        juego(int resolucion_x, int resolucion_y, string titulo);
        void abrirp();
        int aleatorio(int numero);
        void gameloop();// funcion que se repite constantemente para que el programa corra
        void pantallas();
        void procesar_eventos();
    protected:
        Texture *pantalla3;
        Sprite *spritep3;
    private:
        RenderWindow *ventana;

        int fps;
        int score=0;


        Texture *pantalla1;
        Sprite *spritep1;
        Texture *pantalla2;
        Sprite *spritep2;

        Texture *pantalla4reto;
        Sprite *spritep4reto;
        Texture *pantalla4verdad;
        Sprite *spritep4verdad;

        Event *evento1;

        Texture ruleta3;
        Sprite rul3;
        Texture ruleta4;
        Sprite rul4;
        Texture ruleta5;
        Sprite rul5;

        Texture botella;
        Sprite btlla;

        Font *fuente1;
        Text verdades;
        Text retos;

        Text jugadores3A;
        Text jugadores3B;
        Text jugadores3C;
        Text array3[3];

        Text jugadores4;

        Text jugadores5;
        //sfml vuelve el texto de string a una imagen para poder mostrarla en la pantalla

        /*
        Text txt_ingresarjugadores;
        Text txt_verscore;
        */

};

#endif // JUEGO_H
