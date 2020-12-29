//
// Created by Pedro Correia.
//

#include "Territorio.h"
#include <sstream>

Territorio::Territorio(string a, int b):nome(a),res(b){};

string Territorio::getNome() const{
    return nome;
}

string Territorio::getAsString() const {
    ostringstream os;
    os << "Territorio " << nome << " com resistencia " << res << endl;
    return os.str();
}


