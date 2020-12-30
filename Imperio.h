//
// Created by Pedro Correia.
//

#ifndef Imperio_H
#define Imperio_H
#include <vector>
#include "Territorio.h"
#include "Tecnologias.h"

using namespace std;

class Imperio {
    vector<Territorio*> imp;
    Tecnologias* tec = new Tecnologias();
    int cofre = 0;
    int armazem = 0;
    int form = 3;
public:
    ~Imperio();
    bool addTerritorio(Territorio* t);
    bool addTecnologia(string n);
    bool addRecursos();
    string getAsString() const;
};


#endif //Imperio
