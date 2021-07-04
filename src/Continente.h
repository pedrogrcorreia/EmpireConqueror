//
// Created by Pedro Correia.
//

#ifndef Continente_H
#define Continente_H
#include "Territorio.h"

using namespace std;

class Continente: public Territorio{
    const int win = 1;
public:
    Continente(string a, int b);
    virtual int getWin() const;
};




#endif //Continente
