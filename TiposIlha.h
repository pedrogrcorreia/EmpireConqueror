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
    virtual int addOuro();
};

class Pescaria: public Ilha{
    static int count;
public:
    Pescaria();
    virtual int addProd();
};


#endif //TiposIlha
