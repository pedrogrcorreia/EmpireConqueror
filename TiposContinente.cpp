//
// Created by Pedro Correia.
//

#include "TiposContinente.h"
#include "Jogo.h"

TerritorioInicial::TerritorioInicial():Continente("Territorio Inicial", 9){};

// Planicie
Planicie::Planicie():Continente("planicie"+to_string(count++), 3){};

int Planicie::addOuro() {
    return 1;
}

int Planicie::addProd() {
    if(jogo->getTurno() <= 6){
        return 1;
    }
    return 2;
}

int Planicie::count = 1;

//Montanha

Montanha::Montanha():Continente("montanha"+to_string(count++), 6){};

int Montanha::addProd() {
    if(conq > 2){
        return 2;
    }
    return 0;
}

int Montanha::count = 1;

//Fortaleza

Fortaleza::Fortaleza():Continente("fortaleza"+to_string(count++), 8){};

int Fortaleza::count = 1;

// Mina

Mina::Mina():Continente("mina"+to_string(count++), 5){};

int Mina::addOuro(){
    int t = jogo->getTurno();
    if(t <= 3 || (t > 6 && t <= 9) ){
        return 1;
    }
    return 2;
}

int Mina::count = 1;

// Duna

Duna::Duna():Continente("duna"+to_string(count++), 4){};

int Duna::addProd() {
    return 1;
}

int Duna::count = 1;

// Castelo

Castelo::Castelo():Continente("castelo"+to_string(count++), 7){};

int Castelo::addOuro() {
    return 1;
}

int Castelo::addProd() {
    int t = jogo->getTurno();
    if(t <= 2){
        return 3;
    }
    if(t >= 7 && t < 8){
        return 3;
    }
    return 0;
}

int Castelo::count = 1;
