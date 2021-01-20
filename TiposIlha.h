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
    virtual int addOuro() const;
    virtual Territorio* clone();
};

class Pescaria: public Ilha{
    static int count;
public:
    Pescaria();
    virtual int addProd() const;
    virtual Territorio* clone();
};


#endif //TiposIlha
