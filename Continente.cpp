//
// Created by Pedro Correia.
//

#include "Continente.h"

Continente::Continente(string a, int b):Territorio(a, b){};

int Continente::getWin() const{
    return win;
}