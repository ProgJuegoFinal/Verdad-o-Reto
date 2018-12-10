/*#include "Temporizador.h"
#include <iostream>
#include <windows.h>
#include <sstream>
#include <string>
#include "Niveles.h"
using namespace std;

Temporizador::Temporizador()
{
    this->tiempo=1;
}
Temporizador::Temporizador(T a)
{
    this->tiempo=a;
}
Temporizador::~Temporizador()
{
    //dtor
}

void Temporizador::alarma()
{

 int temporizador = 1;
 while (true)
 {
   cout << temporizador << endl;
   if (temporizador == tiempo) cout << "**** ALARMA ****" << endl;
   Sleep(1000); //1 segundo
   temporizador++;
   if (temporizador > tiempo) {
        cout << "\a"; //BEEP
        temporizador=1;
        break;
   }
 }
}
*/
