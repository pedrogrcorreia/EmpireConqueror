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
using namespace std;


class Mundo {
    vector<Territorio*> m;
    map<string, Territorio*> terr = { {"territorioinicial", new TerritorioInicial()},
                                      {"planicie", new Planicie()},
                                      {"montanha", new Montanha()},
                                      {"fortaleza", new Fortaleza()},
                                      {"mina", new Mina()},
                                      {"duna", new Duna()},
                                      {"castelo", new Castelo()},
                                      {"refugio", new Refugio()},
                                      {"pescaria", new Pescaria()}

    };
public:
    bool addTerritorio(string n);
    string getAsString() const;
    Territorio* getTerritorio(string n) const;
};


#endif //Mundo
