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
    return false;
}

Territorio* Mundo::getTerritorio(string n) const {
    for(auto it : m){
        if(it->getNome() == n){
            return it;
        }
    }
    return nullptr;
}

string Mundo::getAsString() const{
    ostringstream os;
    os << "O Mundo tem os seguintes territorios: " << endl;
    for(auto it : m){
        os << it->getAsString() << endl;
    }
    return os.str();
}
