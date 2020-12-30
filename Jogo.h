//
// Created by Pedro Correia.
//

#ifndef Jogo_H
#define Jogo_H
#include "Mundo.h"
#include "Imperio.h"


template<typename T> Territorio * createInstance() { return new T; }

typedef map<string, Territorio*(*)()> map_type;

class Jogo {
    Mundo* mundo;
    Imperio* imperio;
    map_type terr;
    int turno = 0;
    int sorte = 0;
public:
    Jogo();
    ~Jogo();
    bool criaJogo();
    int getTurno()const;
    int getSorte()const;
    void setTurno();
    bool addTerritorio(string n);
    bool conquistaTerritorio(string n);
    bool addTecnologia(string n);
    bool addRecursos();
    string getAsString() const;
};


#endif //Jogo
