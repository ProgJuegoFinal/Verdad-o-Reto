#ifndef TEMPORIZADOR_H
#define TEMPORIZADOR_H
#include <iostream>
#include <windows.h>
#include <sstream>
#include <string>
#include "Niveles.h"
using namespace std;


template <typename T>
class Niveles;


template <typename T>
class Temporizador : public Niveles<T>
{
    public:
        T tiempo;
        Temporizador(){
            this->tiempo=1;
        }

        Temporizador(T tiempo){
            this->tiempo=tiempo;
        }
        void alarma(){

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

    protected:

    private:
};

#endif // TEMPORIZADOR_H
