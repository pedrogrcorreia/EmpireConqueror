//
// Created by Pedro Correia.
//

#include "TiposContinente.h"
#include "Jogo.h"
#include <iostream>

TerritorioInicial::TerritorioInicial():Continente("Territorio Inicial", 9){};

int TerritorioInicial::addOuro() const{
    return 1;
}

int TerritorioInicial::addProd() const{
    return 1;
}

int TerritorioInicial::getWin() const{
    return 0;
}

string TerritorioInicial::getAsString() const{
    ostringstream os;
    os << "Territorio " << getNome() << " com resistencia " << getRes() << "." << endl;
    os << "Produz " << addOuro() << " ouro e " << addProd() << " produtos." << endl;
    return os.str();
}

Territorio* TerritorioInicial::clone(){
    return new TerritorioInicial(*this);
}

// Planicie
Planicie::Planicie():Continente("planicie"+to_string(count++), 3){};

int Planicie::addOuro() const{
    return 1;
}

int Planicie::addProd() const{
    if(jogo->getTurno() <= 6){
        return 1;
    }
    return 2;
}

Territorio* Planicie::clone(){
    return new Planicie(*this);
}

int Planicie::count = 1;

//Montanha

Montanha::Montanha():Continente("montanha"+to_string(count++), 6){};

int Montanha::addProd() const{
    if(jogo->getTurno() >= (conquistado + 2) ) {
        return 2;
    }
    return 0;
}

Territorio* Montanha::clone(){
    return new Montanha(*this);
}

int Montanha::count = 1;

//Fortaleza

Fortaleza::Fortaleza():Continente("fortaleza"+to_string(count++), 8){};

Territorio* Fortaleza::clone(){
    return new Fortaleza(*this);
}

int Fortaleza::count = 1;

// Mina

Mina::Mina():Continente("mina"+to_string(count++), 5){};

int Mina::addOuro() const{
    int t = jogo->getTurno();
    if(t <= 3 || (t > 6 && t <= 9) ){
        return 1;
    }
    return 2;
}

Territorio* Mina::clone(){
    return new Mina(*this);
}

int Mina::count = 1;

// Duna

Duna::Duna():Continente("duna"+to_string(count++), 4){};

int Duna::addProd() const{
    return 1;
}

Territorio* Duna::clone(){
    return new Duna(*this);
}

int Duna::count = 1;

// Castelo

Castelo::Castelo():Continente("castelo"+to_string(count++), 7){};

int Castelo::addOuro() const{
    return 1;
}

int Castelo::addProd() const{
    int t = jogo->getTurno();
    if(t <= 2){
        return 3;
    }
    if(t >= 7 && t < 8){
        return 3;
    }
    return 0;
}

Territorio* Castelo::clone(){
    return new Castelo(*this);
}

int Castelo::count = 1;
