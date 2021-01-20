//
// Created by Pedro Correia.
//
#include "Jogo.h"
#include "utils.h"
#include <sstream>

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
    delete imperio;
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
        ti->conquista();
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

string Jogo::getNome() const{
    return nome;
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
    sorte = getRandomDouble(1.0, 6.0);
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
    int ouro = imperio->getOuro();
    int preco = imperio->getPreco(n);
    if(ouro >= preco){
        if(imperio->addTecnologia(n)){
            imperio->addOuro(-preco);
            return "Tecnologia adicionada com sucesso.\n";
        }
        return "Tecnologia ja existente\n";
    }
    else{
        return "Impossivel adicionar tecnologia.\n";
    }
}

string Jogo::addMilitar(){
    if(imperio->getOuro() >= 1 && imperio->getProd() >= 1) {
        if (imperio->addMilitar()) {
            imperio->addProd(-1);
            imperio->addOuro(-1);
            return "Forca militar adicionada.\n";
        }
        return "Nao tem recursos suficientes.\n";
    }
    return "Forca militar nao adicionada.\n";
}

string Jogo::addRecursos(){
    if(imperio->addRecursos()){
        return "Recursos adicionados.\n";
    }
    return "ERRO - Impossivel adicionar recursos.\n";
}

string Jogo::maisOuro(){
    if(imperio->checkTecnologia("Bolsa de valores")){
        if(imperio->maisOuro()){
            return "Ouro adicionado com sucesso\n";
        }
        else{
            return "Nao foi possivel adicionar ouro.\n";
        }
    }
    else{
        return "Nao tem a tecnologia bolsa de valores.\n";
    }
}

string Jogo::maisProd(){
    if(imperio->checkTecnologia("Bolsa de valores")){
        if(imperio->maisProd()){
            return "Produtos adicionados com sucesso.\n";
        }
        else{
            return "Nao foi possivel adicionar produtos.\n";
        }
    }
    else{
        return "Nao tem a tecnologia Bolsa de valores.\n";
    }
}

string Jogo::evento(int n){
    int s;
    if(n != -1){
        s = n;
    }
    else {
        s = getRandomInt(0, 3);
    }
    switch(s){
        case 0:
            if(turno <= 6){
                if(imperio->addProd(1)){
                    return "Recurso abandonado encontrado. Adicionado 1 unidade de produtos.\n";
                }
            }
            else {
                if (imperio->addOuro(1)) {
                    return "Recurso abandonado encontrado. Adicionado 1 unidade de ouro.\n";
                }
            }
            return "Recurso abandonado encontrado. Cheio, impossivel adicionar.\n";
        case 1:
            int forInvasao, total, res;
            if(turno <= 6){
                forInvasao = 2;
            }
            else{
                forInvasao = 3;
            }
            sorte = getRandomDouble(1.0, 6.0);
            total = sorte + forInvasao;
            Territorio* invadido;
            invadido = mundo->getTerritorio(imperio->ultimoTerritorio());
            res = invadido->getRes();
            if(imperio->checkTecnologia("Defesas Territoriais")){
                res += 1;
            }
            if(total < res){
                return "Invasao falhada.\n";
            }
            else{
                if(imperio->invadeTerritorio()) {
                    return "Invasao sucedida.\n";
                }
                else{
                    return "Perdeu.\n";
                }
            }
        case 2:
            if(imperio->addMilitar()){
                return "Aliancia diplomatica. Forca militar aumentada em 1 unidade.\n";
            }
            return "Alianca diplomatica. Forca militar no maximo, impossivel aumentar.\n";
        case 3:
            return "Nenhum evento ocorrido.\n";
    }
    return "ERRO - Nenhum evento ocorrido.\n";
}

string Jogo::fim(){
    ostringstream os;
    int pontos = 0;
    os << "Pontos dos territorios conquistados: " << imperio->getPontos() << endl;
    pontos += imperio->getPontos();
    os << "Pontos das tecnologias conquistadas: " << imperio->getNTecnologias() << endl;
    pontos += imperio->getNTecnologias();
    if(imperio->getNTecnologias() == 5){
        os << "Bonus Cientifico: " << 1 << endl;
        pontos += 1;
    }
    if(mundo->getSize() == imperio->getSize()){
        os << "Bonus Imperador Supremo: " << 3 << endl;
        pontos += 3;
    }
    os << "Pontos totais: " << pontos << endl;
    return os.str();
}

string Jogo::addTerritorioDebug(string n) {
    Territorio* debug = mundo->getTerritorio(n);
    if(debug == nullptr){
        return "Territorio nao existe.";
    }
    else if(imperio->addTerritorio(debug)){
        debug->conquista();
        return "Territorio adicionado com sucesso ao Imperio.\n";
    }
    return "Impossivel adicionar o Territorio ao Imperio.\n";
}

string Jogo::addTecnologiaDebug(string n) {
    if(imperio->addTecnologia(n)){
        return "Tecnologia adicionada com sucesso";
    }
    return "Tecnologia ja existente";
}

string Jogo::addOuroDebug(int n) {
    if(imperio->addOuro(n)){
        return "Ouro adicionado com sucesso.\n";
    }
    return "Cofre cheio.\n";
}

string Jogo::addProdDebug(int n) {
    if(imperio->addProd(n)){
        return "Produtos adicionados com sucesso.\n";
    }
    return "Armazem cheio.\n";
}

string Jogo::listaTerritorio(string n) const{
    ostringstream os;
    os << mundo->listaTerritorio(n) << endl;
    return os.str();
}

string Jogo::getAsString() const {
    ostringstream os;
    os << "Nome do jogo: " << nome << endl;
    if(turno <= 6){
        os << "Ano: 1" << endl;
    }
    else{
        os << "Ano: 2" << endl;
    }
    os << "Turno: " << turno << endl;
    os << "Sorte: " << sorte << endl;
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