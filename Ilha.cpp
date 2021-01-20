//
// Created by Pedro Correia.
//

#include "Ilha.h"

Ilha::Ilha(string a, int b):Territorio(a, b){};

int Ilha::getWin() const {
    return win;
}