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
    Tecnologias tec;
    int cofre = 3;
    int armazem = 3;
    int ouro = 0;
    int prod = 0;
    int forMilitar = 3;
    int forMilitarMax = 4;
public:
    ~Imperio();
    bool addTerritorio(Territorio* t);
    bool addTecnologia(string n);
    bool checkTecnologia(string n);
    bool addRecursos();
    bool addMilitar();
    bool maisOuro();
    bool maisProd();
    bool addOuro(int n);
    bool addProd(int n);
    bool invadeTerritorio();
    string ultimoTerritorio();
    int getOuro() const;
    int getProd() const;
    int getPreco(string n);
    int getMilitar() const;
    int getSize() const;
    int getPontos() const;
    int getNTecnologias() const;
    string getAsString() const;
    Imperio* clone();
};


#endif //Imperio
