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
};

class Montanha: public Continente {
    static int count;
public:
    Montanha();
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
};

class Duna: public Continente{
    static int count;
public:
    Duna();
};

class Castelo: public Continente{
    static int count;
public:
    Castelo();
};

#endif //TiposContinente
