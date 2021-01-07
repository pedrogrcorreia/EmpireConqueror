//
// Created by Pedro Correia.
//
#include <iostream>
#include "Jogo.h"
#include "utils.h"
#include <sstream>

double getRandomConquista();

Jogo::Jogo(string n){
    nome = n;
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

Jogo::Jogo(const Jogo& ref){
    turno = ref.getTurno();
    sorte = ref.getSorte();
    imperio = ref.imperio->clone();
    mundo = ref.mundo->clone();
}

bool Jogo::criaJogo() {
    mundo = new Mundo();
    imperio = new Imperio();
    if(!mundo || !imperio){
        return false;
    }
    Territorio* ti = terr["territorioinicial"]();
    ti->ligaJogo(this);
    if(mundo->addTerritorio(ti) && imperio->addTerritorio(mundo->getTerritorio("Territorio Inicial"))){
        return true;
    }
    return true;
}

int Jogo::getTurno()const{
    return turno;
}

int Jogo::getSorte()const{
    return sorte;
}

void Jogo::setTurno(){
    turno++;
}

bool Jogo::addTerritorio(string n){
    Territorio *novo = terr[n]();
    novo->ligaJogo(this);
    if(mundo->addTerritorio(novo)){
        return true;
    }
    return false;
}

string Jogo::conquistaTerritorio(string n){
    int fm;
    double total;
    sorte = getRandomConquista();
    fm = imperio->getMilitar();
    total = sorte+fm;
    Territorio* conq = mundo->getTerritorio(n);
    if(conq == nullptr){
        return "Territorio nao existe.\n";
    }
    if (dynamic_cast<Ilha*>(conq)) {
        if (!imperio->checkTecnologia("Misseis teleguiados")) {
            return "Territorio impossivel de conquistar pois e uma ilha.\n";
        }
        else {
            if (conq->getRes() <= total) {
                return "Falha ao conquistar territorio.\n";
            } else {
                if (imperio->addTerritorio(conq)) {
                    conq->conquista();
                    return "Territorio conquistado com sucesso.\n";
                }
                return "ERRO - Territorio nao conquistado.\n";
            }
        }
    }
    else{
        if (conq->getRes() <= total) {
            if(imperio->addTerritorio(conq)){
                conq->conquista();
                return "Territorio conquistado com sucesso.\n";
            }
            else{
                return "ERRO - Territorio nao conquistado.\n";
            }
        }
        return "Falha ao conquistar territorio.\n";
    }
}

string Jogo::addTecnologia(string n) {
    if(imperio->addTecnologia(n)){
        return "Tecnologia adicionada com sucesso.";
    }
    return "Tecnologia nao adicionada.";
}

string Jogo::addMilitar(){
    if(imperio->addMilitar()){
        return "Forca militar adicionada.";
    }
    return "Forca militar nao adicionada";
}

string Jogo::addRecursos(){
    if(imperio->addRecursos()){
        return "Recursos adicionados.\n";
    }
    return "ERRO - Impossivel adicionar recursos.\n";
}

string Jogo::listaTerritorio(string n) const{
    ostringstream os;
    os << mundo->listaTerritorio(n) << endl;
    return os.str();
}

string Jogo::getAsString() const {
    ostringstream os;
    os << "Nome do jogo: " << nome << endl;
    os << "Turno: " << turno << endl;
    os << "Sorte:" << sorte << endl;
    os << mundo->getAsString() << endl;
    os << imperio->getAsString() << endl;
    return os.str();
}

Jogo& Jogo::operator=(const Jogo& ref){
    turno = ref.getTurno();
    sorte = ref.getSorte();
    imperio = ref.imperio->clone();
    mundo = ref.mundo->clone();
    return *this;
}
