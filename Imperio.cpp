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
    for(auto it : imp){
        if(t == it){
            return false;
        }
    }
    imp.push_back(t);
    return true;
}

bool Imperio::addTecnologia(string n) {
    int valor = tec.addTec(n, ouro);
    if(valor == -1){
        return false;
    }
    ouro -= valor;
    if(n == "Drones militares"){   // Tentar melhor implementacao
        forMilitarMax = 5;
        return true;
    }
    if(n == "Banco central"){
        cofre = 5;
        armazem = 5;
        return true;
    }
    return true;
}

bool Imperio::checkTecnologia(string n) {
    return tec.checkTecnologia(n);
}

bool Imperio::addRecursos(){
//    for(auto it : imp){
//        if(ouro < cofre) {
//            if ((ouro += it->addOuro()) >= cofre) {
//                ouro = cofre;
//            }
//        }
//        if(prod < armazem) {
//            if( (prod += it->addProd()) >= armazem){
//                prod = armazem;
//            }
//        }
//    }
    for(auto it : imp){
        if( (ouro += it->addOuro() ) >= cofre){
            ouro = cofre;
        }
        if( (prod += it->addProd() ) >= armazem){
            prod = armazem;
        }
    }
    return true;
}

bool Imperio::addMilitar() {
    if (forMilitar <= forMilitarMax && prod >= 1 && ouro >= 1){
        forMilitar += 1;
        ouro--;
        prod--;
        return true;
    }
    return false;
}

int Imperio::getMilitar()const {
    return forMilitar;
}

string Imperio::getAsString() const {
    ostringstream os;
    os << "Imperio tem os seguintes territorios:" << endl;
    for(auto it : imp){
        os << it->getAsString() << endl;
    }
    os << "E as tecnologias:" << endl;
    os << tec.getTecnologias() << endl;
    os << tec.getAsString() << endl;
    os << "Tem " << ouro << " de ouro e " << prod << " de produtos." << endl;
    os << "Pode armazenar " << cofre << " de ouro e " << armazem << " de produtos." << endl;
    os << "Tem " << forMilitar << " que pode aumentar ate " << forMilitarMax << endl;
    return os.str();
}

Imperio* Imperio::clone(){
    Imperio* novo = new Imperio();
    novo->tec = tec;
    novo->cofre = cofre;
    novo->armazem = armazem;
    novo->ouro = ouro;
    novo->prod = prod;
    novo->forMilitar = forMilitar;
    novo->forMilitarMax = forMilitarMax;
    for(auto it : imp){
        novo->addTerritorio(it->clone());
    }
    return novo;
}
