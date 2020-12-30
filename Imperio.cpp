//
// Created by Pedro Correia.
//

#include "Imperio.h"
#include <sstream>
#include <iostream>

Imperio::~Imperio(){ // não utilizado
    for(auto it : imp){
        delete it;
    }
}

bool Imperio::addTerritorio(Territorio *t) {
    imp.push_back(t);
    return true;
}

bool Imperio::addTecnologia(string n) {
    tec->addTec(n);
    return true;
}

bool Imperio::addRecursos(){
    for(auto it : imp){
        if(cofre < 3)
            cofre += it->addOuro();
        else
            cout << "Ouro desperdicado" << endl;
        if(armazem < 3)
            armazem += it->addProd();
    }
    return true;
}

string Imperio::getAsString() const {
    ostringstream os;
    os << "Imperio tem os seguintes territorios:" << endl;
    for(auto it : imp){
        os << it->getAsString() << endl;
    }
    os << "E as tecnologias:" << endl;
    os << tec->getTecnologias() << endl;
    os << "Tem " << cofre << " de ouro e " << armazem << " de produtos" << endl;
    return os.str();
}
