//
// Created by Pedro Correia.
//

#include "TiposIlha.h"
#include "Jogo.h"

Refugio::Refugio():Ilha("refugio dos piratas"+to_string(count++),9){};

int Refugio::addOuro() {
    return 1;
}

int Refugio::count = 1;

Pescaria::Pescaria():Ilha("pescaria"+to_string(count++), 9){};

int Pescaria::addProd() {
    if(jogo->getTurno() > 6){
        return 4;
    }
    return 2;
}

int Pescaria::count = 1;