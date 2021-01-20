//
// Created by Pedro Correia.
//

#ifndef TiposContinente_H
#define TiposContinente_H
#include "Continente.h"
#include <sstream>

using namespace std;

class TerritorioInicial: public Continente{
public:
    TerritorioInicial();
    virtual int addOuro() const;
    virtual int addProd() const;
    virtual int getWin() const;
    virtual string getAsString() const;
    virtual Territorio* clone();
};

class Planicie: public Continente {
    static int count;
public:
    Planicie();
    virtual int addOuro() const;
    virtual int addProd() const;
    virtual Territorio* clone();
};

class Montanha: public Continente {
    static int count;
public:
    Montanha();
    virtual int addProd() const;
    virtual Territorio* clone();
};

class Fortaleza: public Continente{
    static int count;
public:
    Fortaleza();
    virtual Territorio* clone();
};

class Mina: public Continente{
    static int count;
public:
    Mina();
    virtual int addOuro() const;
    virtual Territorio* clone();
};

class Duna: public Continente{
    static int count;
public:
    Duna();
    virtual int addProd() const;
    virtual Territorio* clone();
};

class Castelo: public Continente{
    static int count;
public:
    Castelo();
    virtual int addOuro() const;
    virtual int addProd() const;
    virtual Territorio* clone();
};

#endif //TiposContinente
