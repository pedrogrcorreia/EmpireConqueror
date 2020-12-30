//
// Created by Pedro Correia.
//

#include "Tecnologias.h"
#include <sstream>

string Tecnologias::getAsString() const {
    ostringstream os;
    for(auto entry : Tec){
        os << entry.first << ":" << endl;
        os << entry.second.first << " " << entry.second.second;
        os << endl;
    }
    return os.str();
}

string Tecnologias::getTecnologias() const {
    ostringstream os;
    for(auto entry: Tec){
        if(entry.second.first == true){
            os << entry.first << endl;
        }
    }
    return os.str();
}

void Tecnologias::addTec(string tec){
    Tec[tec].first = true;
}