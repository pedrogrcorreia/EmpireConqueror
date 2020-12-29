//
// Created by Pedro Correia.
//
#include <iostream>
#include "Jogo.h"
#include <sstream>

bool Jogo::criaJogo() {
    mundo = new Mundo();
    imperio = new Imperio();

//    if(!mundo || !imperio){
//        return false;
//    }
//    mundo->addTerritorio("territorioinicial");
//    imperio->addTerritorio(mundo->getTerritorio("Territorio Inicial"));
    return true;
}

bool Jogo::addTerritorio(string n) {
    mundo->addTerritorio(n);
    return true;
}

string Jogo::getAsString() const {
    ostringstream os;
    os << "Mundo: " << endl;
    os << mundo->getAsString() << endl;
    os << "Imperio: " << endl;
    os << imperio->getAsString() << endl;
    return os.str();
}