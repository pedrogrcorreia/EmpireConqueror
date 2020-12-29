//
// Created by Pedro Correia.
//

#ifndef Jogo_H
#define Jogo_H
#include "Mundo.h"
#include "Imperio.h"

class Territorio;
class Planicie;

using namespace std;

class Jogo {
    Mundo* mundo;
    Imperio* imperio;
    int turno;
    int sorte;
public:
    bool criaJogo();
    bool addTerritorio(string n);
    string getAsString() const;
};


#endif //Jogo
