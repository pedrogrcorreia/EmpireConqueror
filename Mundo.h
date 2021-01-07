//
// Created by Pedro Correia.
//

#ifndef Mundo_H
#define Mundo_H
#include "Territorio.h"
#include "TiposContinente.h"
#include "TiposIlha.h"
#include <vector>
#include <map>
#include <string>

using namespace std;

class Mundo {
    vector<Territorio*> m;
public:
    ~Mundo();
    bool addTerritorio(Territorio* t);
    string listaTerritorio(string n) const;
    string getAsString() const;
    Territorio* getTerritorio(string n) const;
    Mundo* clone();
};


#endif //Mundo
