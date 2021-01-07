//
// Created by Pedro Correia.
//

#include "Tecnologias.h"
#include <sstream>
#include <iostream>

int Tecnologias::addTec(string tec, int v){
    if(mTec[tec].first != true && mTec[tec].second <= v) {
        mTec[tec].first = true;
        return mTec[tec].second;
    }
    return -1;
}

bool Tecnologias::checkTecnologia(string tec) {
    for(auto entry : mTec){
        return mTec[tec].first;
    }
    return false;
}

string Tecnologias::getTecnologias() const {
    ostringstream os;
    for(auto entry: mTec){
        if (entry.second.first == true) {
            os << entry.first << endl;
        }
    }
    return os.str();
}

string Tecnologias::getAsString() const {
    ostringstream os;
    for(auto entry : mTec){
            os << entry.first << ":" << endl;
            os << entry.second.first << " " << entry.second.second;
            os << endl;
    }
    return os.str();
}



