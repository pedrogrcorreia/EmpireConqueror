//
// Created by Pedro Correia.
//

#include "Territorio.h"
#include "Jogo.h"

Territorio::Territorio(string a, int b):nome(a),res(b){};

bool Territorio::ligaJogo(Jogo* j) {
    jogo = j;
    return true;
}

void Territorio::conquista(){
    conquistado = jogo->getTurno();
}

bool Territorio::checkConquista() {
    if(conquistado == -1){
        return false;
    }
    return true;
}

void Territorio::invade(){
    conquistado = -1;
}

string Territorio::getNome() const{
    return nome;
}

int Territorio::getRes() const{
    return res;
}

int Territorio::getWin() const{
    return 0;
}

int Territorio::addOuro() const{
    return 0;
}

int Territorio::addProd() const{
    return 0;
}

string Territorio::getAsString() const {
    ostringstream os;
    os << "Territorio " << nome << " com resistencia " << res << "." << endl;
    if(conquistado != -1){
        os << "Conquistado no turno: " << conquistado << "." << endl;
        os << "Produz " << addOuro() << " ouro e " << addProd() << " produtos." << endl;
    }
    return os.str();
}

Territorio* Territorio::clone(){
    return new Territorio(*this);
}


