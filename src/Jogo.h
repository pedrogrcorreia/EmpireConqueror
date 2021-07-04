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
    string nome;
    Mundo* mundo;
    Imperio* imperio;
    map_type terr;
    int turno = 0;
    double sorte = 0;
public:
    Jogo(string n);
    Jogo(const Jogo& ref);
    ~Jogo();
    bool criaJogo();
    int getTurno()const;
    int getSorte()const;
    string getNome() const;
    void setTurno();
    bool addTerritorio(string n);
    string conquistaTerritorio(string n);
    string addTecnologia(string n);
    string addMilitar();
    string addRecursos();
    string maisOuro();
    string maisProd();
    string evento(int n);
    string fim();
    string addTerritorioDebug(string n);
    string addTecnologiaDebug(string n);
    string addOuroDebug(int n);
    string addProdDebug(int n);
    string listaTerritorio(string n)const;
    string getAsString() const;
    Jogo& operator=(const Jogo& ref);
};


#endif //Jogo
