//
// Created by Pedro Correia.
//

#include "Imperio.h"
#include <sstream>

Imperio::~Imperio(){
    imp.clear();
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
    if(tec.addTec(n)) {
        if (n == "Drones militares") {
            forMilitarMax = 5;
        }
        if (n == "Banco central") {
            cofre = 5;
            armazem = 5;
        }
        return true;
    }
    return false;
}

bool Imperio::checkTecnologia(string n) {
    return tec.checkTecnologia(n);
}

bool Imperio::addRecursos(){
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
    if (forMilitar < forMilitarMax){
        forMilitar += 1;
        return true;
    }
    return false;
}

bool Imperio::maisOuro(){
    if(prod >= 2){
        addProd(-2);
        addOuro(1);
        return true;
    }
    return false;
}

bool Imperio::maisProd(){
    if(ouro >= 2){
        addOuro(-2);
        addProd(1);
        return true;
    }
    return false;
}

bool Imperio::addOuro(int n){
    if(ouro == cofre && n > 0){
        return false;
    }
    int total = ouro + n;
    if( total >= cofre ){
        ouro = cofre;
        return true;
    }
    else if(total <= 0){
        ouro = 0;
        return true;
    }
    else{
        ouro += n;
        return true;
    }
}

bool Imperio::addProd(int n){
    if(prod == armazem && n > 0){
        return false;
    }
    int total = prod + n;
    if( total >= armazem ){
        prod = armazem;
        return true;
    }
    else if(total <= 0){
        prod = 0;
        return true;
    }
    else{
        prod += n;
        return true;
    }
}

bool Imperio::invadeTerritorio(){
    imp.back()->invade();
    imp.pop_back();
    if(imp.size() > 0) {
        return true;
    }
    return false;
}

string Imperio::ultimoTerritorio(){
    return imp.back()->getNome();
}

int Imperio::getOuro() const {
    return ouro;
}

int Imperio::getProd() const{
    return prod;
}

int Imperio::getPreco(string n){
    return tec.getPreco(n);
}

int Imperio::getMilitar()const {
    return forMilitar;
}

int Imperio::getSize() const{
    return imp.size();
}

int Imperio::getPontos() const{
    int vitoria = 0;
    for(auto it : imp){
        vitoria += it->getWin();
    }
    return vitoria;
}

int Imperio::getNTecnologias() const {
    return tec.getNTecnologias();
}

string Imperio::getAsString() const {
    int o = 0, p = 0;
    for(auto it : imp){
        o += it->addOuro();
        p += it->addProd();
    }
    ostringstream os;
    os << "Imperio tem os seguintes territorios:" << endl;
    for(auto it : imp){
        os << it->getAsString() << endl;
    }
    if(!tec.getTecnologias().empty()){
        os << "Tem as tecnologias:" << endl;
        os << tec.getTecnologias() << endl;
    }
    else{
        os << "Nao tem tecnologias ativas." << endl;
    }
    os << "Pode adquirir as tecnologias: " << endl;
    os << tec.getTecnologiasN() << endl;
    os << "Tem " << ouro << " de ouro e " << prod << " de produtos." << endl;
    os << "Pode armazenar " << cofre << " de ouro e " << armazem << " de produtos." << endl;
    os << "Neste turno produz um total de " << o << " ouro e " << p << " produtos." << endl;
    os << "Tem forca militar " << forMilitar << " que pode aumentar ate " << forMilitarMax << endl;
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
