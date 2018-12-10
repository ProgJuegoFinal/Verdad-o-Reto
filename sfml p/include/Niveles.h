#ifndef NIVELES_H
#define NIVELES_H

template <typename T>
class Niveles
{
    public:
        T score=0;//
        T tiempo=1;
        Niveles(T score){
          if (score <=5) { tiempo=20;}
          if ((score >=5)&&(score <=10)) { tiempo=10;}
          if ((score >=10)&&(score <=15)) { tiempo=5;}
        }
        Niveles (){
        tiempo=1;
        }
        T getNivelcar(){return tiempo;}



    protected:

    private:
};

#endif // NIVELES_H
