//
// Created by Pedro Correia.
//

#ifndef TiposContinente_H
#define TiposContinente_H
#include "Continente.h"

using namespace std;

class TerritorioInicial: public Continente{
public:
    TerritorioInicial();
};

class Planicie: public Continente {
    static int count;
public:
    Planicie();
    virtual int addOuro();
    virtual int addProd();
};

class Montanha: public Continente {
    static int count;
    int conq;
public:
    Montanha();
    virtual int addProd();
};

class Fortaleza: public Continente{
    static int count;
public:
    Fortaleza();
};

class Mina: public Continente{
    static int count;
public:
    Mina();
    virtual int addOuro();
};

class Duna: public Continente{
    static int count;
public:
    Duna();
    virtual int addProd();
};

class Castelo: public Continente{
    static int count;
public:
    Castelo();
    virtual int addOuro();
    virtual int addProd();
};

#endif //TiposContinente
