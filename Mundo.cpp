//
// Created by Pedro Correia.
//

#include "Mundo.h"
#include <sstream>

Mundo::~Mundo(){
    for(auto it : m){
        delete it;
    }
}

bool Mundo::addTerritorio(Territorio *t) {
    m.push_back(t);
    return true;
}

Territorio* Mundo::getTerritorio(string n) const {
    for(auto it : m){
        if(it->getNome() == n){
            return it;
        }
    }
    return nullptr;
}

string Mundo::listaTerritorio(string n) const {
    for(auto it : m){
        if(it->getNome() == n){
            return it->getAsString();
        }
    }
    return "Territorio nao existe.\n";
}

string Mundo::getAsString() const{
    ostringstream os;
    os << "O Mundo tem os seguintes territorios: " << endl;
    for(auto it : m){
        os << it->getAsString() << endl;
    }
    return os.str();
}

Mundo* Mundo::clone(){
    Mundo* novo = new Mundo();
    for(auto it : m){
        novo->addTerritorio(it->clone());
    }
    return novo;
}
