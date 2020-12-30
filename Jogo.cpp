//
// Created by Pedro Correia.
//
#include <iostream>
#include "Jogo.h"
#include <sstream>

Jogo::Jogo(){
    terr["territorioinicial"] = &createInstance<TerritorioInicial>;
    terr["planicie"] = &createInstance<Planicie>;
    terr["montanha"] = &createInstance<Montanha>;
    terr["fortaleza"] = &createInstance<Fortaleza>;
    terr["mina"] = &createInstance<Mina>;
    terr["duna"] = &createInstance<Duna>;
    terr["castelo"] = &createInstance<Castelo>;
    terr["refugio"] = &createInstance<Refugio>;
    terr["pescaria"] = &createInstance<Pescaria>;
}

Jogo::~Jogo(){
    delete mundo;
}

bool Jogo::criaJogo() {
    mundo = new Mundo();
    imperio = new Imperio();
    if(!mundo || !imperio){
        return false;
    }
    Territorio* ti = terr["territorioinicial"]();
    ti->ligaJogo(this);
    mundo->addTerritorio(ti);
    imperio->addTerritorio(mundo->getTerritorio("Territorio Inicial"));
    return true;
}

int Jogo::getTurno()const{
    return turno;
}

int Jogo::getSorte()const{
    return sorte;
}

void Jogo::setTurno(){
    turno = 3;
}

bool Jogo::addTerritorio(string n){
    Territorio *novo = terr[n]();
    novo->ligaJogo(this);
    mundo->addTerritorio(novo);
    return true;
}

bool Jogo::conquistaTerritorio(string n){
    imperio->addTerritorio(mundo->getTerritorio(n));
    return true;
}

bool Jogo::addTecnologia(string n) {
    imperio->addTecnologia(n);
    return true;
}

bool Jogo::addRecursos(){
    imperio->addRecursos();
    return true;
}

string Jogo::getAsString() const {
    ostringstream os;
    os << mundo->getAsString() << endl;
    os << imperio->getAsString() << endl;
    return os.str();
}