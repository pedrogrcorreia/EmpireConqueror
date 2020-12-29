//
// Created by Pedro Correia.
//

#include "Mundo.h"

//#include "Territorio.h"
//#include "Continente.h"
//#include "Ilha.h"
#include <sstream>



bool Mundo::addTerritorio(string n) {
//    for(auto entry : terr){
//        if(entry.first == n){
//            m.push_back(terr[n]);
//            return true;
//        }
//    }
    m.push_back(new Planicie());
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
    for(auto it : m){
        os << it->getAsString() << endl;
    }
    return os.str();
}
