#include <iostream>
#include <SFML/Graphics.hpp>
#include "juego.h"
//#include <MMSystem.h>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <SFML/Audio.hpp>
#include <SFML/Audio.hpp>
#include "windows.h"
#include "juego.h"
using namespace std;
using namespace sf;
int main()
{

    //PlaySound(TEXT("musicTF.wav"),NULL,SND_ASYNC);
    juego *verdadoreto;
    srand(time(NULL));
    verdadoreto= new juego(800,600,"Truth or Dare");


    return 0;
}
