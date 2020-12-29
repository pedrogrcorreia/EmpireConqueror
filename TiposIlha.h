//
// Created by Pedro Correia.
//

#ifndef TiposIlha_H
#define TiposIlha_H

#include "Ilha.h"
using namespace std;

class Refugio: public Ilha{
    static int count;
public:
    Refugio();
};

class Pescaria: public Ilha{
    static int count;
public:
    Pescaria();
};


#endif //TiposIlha
