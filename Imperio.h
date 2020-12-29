//
// Created by Pedro Correia.
//

#ifndef Imperio_H
#define Imperio_H
#include <vector>
#include "Territorio.h"

using namespace std;

class Imperio {
    vector<Territorio*> imp;
    int cofre;
    int armazem;
    int form;
public:
    bool addTerritorio(Territorio* t);
    string getAsString() const;
};


#endif //Imperio
