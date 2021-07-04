//
// Created by Pedro Correia.
//

#include "Tecnologias.h"
#include <sstream>

bool Tecnologias::addTec(string tec){
    for(auto& entry : mTec){
        if(entry.first.first == tec){
            if(entry.second.first != true){
                entry.second.first = true;
                return true;
            }
        }
    }
    return false;
}

bool Tecnologias::checkTecnologia(string tec) {
    for(auto& entry : mTec){
        if(entry.first.first == tec) {
            return entry.second.first;
        }
    }
    return false;
}

int Tecnologias::getPreco(string n){
    for(auto& entry : mTec){
        if(entry.first.first == n){
            return entry.second.second;
        }
    }
    return 0;
}

int Tecnologias::getNTecnologias() const{
    int conta = 0;
    for(auto& entry : mTec){
        if(entry.second.first == true){
            conta++;
        }
    }
    return conta;
}

string Tecnologias::getTecnologias() const{
    ostringstream os;
    for(auto& entry: mTec){
        if (entry.second.first == true) {
            os << entry.first.first << ". " << entry.first.second << endl;
            os << "Custou: " << entry.second.second << " ouro." << endl;
        }
    }
    return os.str();
}

string Tecnologias::getTecnologiasN() const{
    ostringstream os;
    for(auto& entry: mTec){
        if (entry.second.first == false) {
            os << entry.first.first << ". " << entry.first.second << endl;
            os << "Custa: " << entry.second.second << " ouro." << endl;
        }
    }
    return os.str();
}

string Tecnologias::getAsString() const{
    ostringstream os;
    for(auto entry : mTec){
        os << "Tecnologia " << entry.first.first << ". " << entry.first.second << endl;
        os << "Custa: " << entry.second.second << endl;
    }
    return os.str();
}


