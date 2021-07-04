//
// Created by Pedro Correia.
//

#include "TiposIlha.h"
#include "Jogo.h"

Refugio::Refugio():Ilha("refugio_dos_piratas"+to_string(count++),9){};

int Refugio::addOuro() const{
    return 1;
}

Territorio* Refugio::clone(){
    return new Refugio(*this);
}

int Refugio::count = 1;

Pescaria::Pescaria():Ilha("pescaria"+to_string(count++), 9){};

int Pescaria::addProd() const{
    if(jogo->getTurno() > 6){
        return 4;
    }
    return 2;
}

Territorio* Pescaria::clone(){
    return new Pescaria(*this);
}

int Pescaria::count = 1;