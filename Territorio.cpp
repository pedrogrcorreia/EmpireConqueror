//
// Created by Pedro Correia.
//

#include "Territorio.h"
#include "Jogo.h"
#include <sstream>

Territorio::Territorio(string a, int b):nome(a),res(b){};

bool Territorio::ligaJogo(Jogo* j) {
    jogo = j;
    return true;
}

string Territorio::getNome() const{
    return nome;
}

int Territorio::addOuro() {
    return 0;
}

int Territorio::addProd(){
    return 0;
}

string Territorio::getAsString() const {
    ostringstream os;
    os << "Territorio " << nome << " com resistencia " << res << endl;
    return os.str();
}


