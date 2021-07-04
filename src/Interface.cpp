//
// Created by Pedro Correia.
//

#include "Interface.h"
#include <iostream>
#include <fstream>

Interface::Interface(){
    Jogo* j = new Jogo("Inicial");
    jogos.push_back(j);
    ativo = jogos[0];
};

Interface::~Interface(){
    for(auto it : jogos){
        delete it;
    }
}

int Interface::validaCmd(string c) const{
    istringstream iss(c);
    iss >> c;
    for(int i = 0; i<comandos.size(); i++){
        if(c == comandos[i]){
            return i;
        }
    }
    return -1;
}

int Interface::validaNome(string n) const{
    for(int i = 0; i<territorios.size(); i++){
        if(n == territorios[i]){
            return i;
        }
    }
    return -1;
}

int Interface::validaTecnologia(string n) const{
    for(int i=0; i<tecnologias.size(); i++){
        if(n == tecnologias[i]){
            return i;
        }
    }
    return -1;
}

int Interface::validaEvento(string n) const{
    for(int i=0; i<eventos.size(); i++){
        if(n == eventos[i]){
            return i;
        }
    }
    return -1;
}

string Interface::cria(istringstream& i) const{
    string nome;
    int n = 1, vN = -1;
    if( (i >> nome).fail()){
        return "Nome invalido.\n";
    }
    if( (i >> n).fail()){
        return "Numero invalido.\n";
    }
    vN = validaNome(nome);
    if(vN == -1){
        return "Nome do territorio nao existe.\n";
    }
    else{
        for(int i=0; i<n; i++) {
            if (!ativo->addTerritorio(territorios[vN])) {
                return "Impossivel criar territorios.\n";
            }
        }
    }
    return "Territorio " + nome + " criados " + to_string(n) + " vezes com sucesso.\n";
}

string Interface::carrega(istringstream& i){
    fstream f;
    string fnome, cmd, r;
    int linha=1, vCmd=-1;
    i >> fnome;
    f.open(fnome+".txt");
    if(!f){
        return "Impossivel abrir o ficheiro.\n";
    }
    while(!f.eof()){
        getline(f, comando);
        istringstream is(comando);
        is >> cmd;
        vCmd = validaCmd(cmd);
        if(vCmd == -1){
            r.append("Comando invalido na linha " + to_string(linha) + " do ficheiro " + fnome + ".\n");
        }
        else if(vCmd == 0){
            r.append(cria(is));
        }
        linha++;
    }
    return r;
}

string Interface::lista(istringstream& i)const{
    string nome;
    i >> nome;
    if(nome.empty()){
        return ativo->getAsString();
    }
    else{
        return ativo->listaTerritorio(nome);
    }
}

string Interface::adquire(istringstream& i) const{
    string nome, comp;
    int vT = -1;
    i >> nome;
    while(i >> comp){
        nome += " "+comp;
    }
    vT = validaTecnologia(nome);
    if(vT == -1){
        return "Nome da tecnologia errado. Tente novamente.\n";
    }
    else {
        return ativo->addTecnologia(nome);
    }
}

string Interface::grava(istringstream& i){
    string nome, comp;
    i >> nome;
    while(i >> comp){
        nome += " "+comp;
    }
    Jogo* novo = new Jogo(nome);
    *novo = *ativo;
    jogos.push_back(novo);
    return "Jogo gravado com sucesso.";
}

string Interface::carregaJogo(istringstream& i){
    string nome, comp;
    i >> nome;
    while(i >> comp){
        nome += " "+comp;
    }
    for(auto it : jogos){
        if(it->getNome() == nome){
            ativo = it;
            return it->getNome() + " carregado com sucesso.\n";
        }
    }
    return "Impossivel carregar jogo\n";
}

string Interface::apaga(istringstream& i){
    string nome, comp, r;
    i >> nome;
    while(i >> comp){
        nome += " "+comp;
    }
    if(nome == "Inicial"){
        return "Impossivel apagar jogo Inicial.\n";
    }
    auto it = jogos.begin();
    while (it < jogos.end()){
        if ((*it)->getNome() == nome) {
            if(ativo == *it){
                ativo = jogos[0];
            }
            delete *it;
            it = jogos.erase(it);
            r.append("Jogo apagado com sucesso.\n");
        }
        else
            it++;
    }
    if(r.empty()){
        r.append("Jogo nao existe.\n");
    }
    return r;
}

string Interface::debug(istringstream& i, int vCmd){
    string cmd, nome, comp;
    if(vCmd == 13){
        i >> cmd;
        if(cmd == "terr"){
            i >> nome;
            return ativo->addTerritorioDebug(nome);
        }
        else if(cmd == "tec"){
            i >> nome;
            while(i >> comp){
                nome += " "+comp;
            }
            int vTec = validaTecnologia(nome);
            if(vTec != -1) {
                return ativo->addTecnologiaDebug(nome);
            }
            else{
                return "Tecnologia nao existe.\n";
            }
        }
        else {
            return "Parametro invalido.\n";
        }
    }
    if(vCmd == 14){
        i >> cmd;
        int n;
        if(cmd == "ouro"){
            i >> n;
            return ativo->addOuroDebug(n);
        }
        else if(cmd == "prod"){
            i >> n;
            return ativo->addProdDebug(n);
        }
        else{
            return "Parametro invalido.\n";
        }
    }
    if(vCmd == 15){
        int vEve;
        i >> cmd;
        vEve = validaEvento(cmd);
        if(vEve == -1){
            return "Evento nao existe.\n";
        }
        else {
            string ret = ativo->evento(vEve);
            if(ret == "Perdeu.\n"){
                f = 1;
            }
            return ret;
        }
    }
    return "ERRO.\n";
}

void Interface::start(){
    if(config()){
        fim();
        return;
    }
    while(ativo->getTurno() < 12){
        if(PFase()){
            fim();
            return;
        }
        if(SFase()){
            fim();
            return;
        }
        if(TFase()){
            fim();
            return;
        }
        if(QFase()){
            fim();
            return;
        }
    }
    fim();
    return;
}

bool Interface::config(){
    string cmd;
    int vCmd;
    if(!jogos[0]->criaJogo()){
        cout << "Impossivel jogar. Tente novamente." << endl;
    }
    cout << "Bem vindo." << endl;
    while(f != 1){
        cout << "Introduza o comando que pretende realizar: (avanca para terminar)" << endl;
        getline(cin, comando);
        istringstream iss(comando);
        iss >> cmd;
        vCmd = validaCmd(cmd);
        switch(vCmd){
            case 0:
                cout << cria(iss) << endl;
                break;
            case 1:
                cout << carrega(iss) << endl;
                break;
            case 2:
                cout << lista(iss) << endl;
                break;
            case 10:
                cout << grava(iss) << endl;
                break;
            case 11:
                cout << carregaJogo(iss) << endl;
                break;
            case 12:
                cout << apaga(iss) << endl;
                break;
            case 13:
            case 14:
            case 15:
                cout << debug(iss, vCmd) << endl;
                break;
            case 3:
                cout << "Configuracao concluida." << endl;
                return false;
            default:
                cout << "Comando invalido para configuracao." << endl;
                break;
        }
    }
    return true;
}


bool Interface::PFase(){
    ativo->setTurno();
    string cmd;
    int vCmd = -1;
    int acao = 0;
    while(f != 1){
        cout << "Introduza o comando que pretende realizar (passa/conquista/lista): (avanca para continuar)" << endl;
        getline(cin, comando);
        istringstream iss(comando);
        iss >> cmd;
        vCmd = validaCmd(cmd);
        switch(vCmd){
            case 2:
                cout << lista(iss) << endl;
                break;
            case 3:
                if(acao == 0){
                    cout << "Nao tomou nenhuma acao nesta fase. (passa ou conquista)." << endl;
                    break;
                }
                return false;
            case 4:
                if(acao == 1){
                    cout << "Ja tomou uma acao nesta fase, por favor avance." << endl;
                }
                else {
                    iss >> cmd;
                    cout << ativo->conquistaTerritorio(cmd);
                }
                acao = 1;
                break;
            case 5:
                if(acao == 1){
                    cout << "Ja tomou uma acao nesta fase, por favor avance." << endl;
                }
                acao = 1;
                break;
            case 10:
                cout << grava(iss) << endl;
                break;
            case 11:
                cout << carregaJogo(iss) << endl;
                break;
            case 12:
                cout << apaga(iss) << endl;
                break;
            case 13:
            case 14:
            case 15:
                cout << debug(iss, vCmd) << endl;
                break;
            default:
                cout << "Comando invalido para esta fase." << endl;
                break;
        }
    }
    return true;
}

bool Interface::SFase() {
    cout << "Segunda Fase" << endl;
    ativo->addRecursos();
    string cmd;
    int vCmd = -1;
    while(f != 1){
        cout << "Pretende trocar ouro por produtos ou vice-versa? (maisprod ou maisouro): (avanca para continuar)" << endl;
        getline(cin, comando);
        istringstream iss(comando);
        iss >> cmd;
        vCmd = validaCmd(cmd);
        switch(vCmd){
            case 2:
                cout << lista(iss) << endl;
                break;
            case 3:
                return false;
            case 6:
                cout << ativo->maisOuro() << endl;
                break;
            case 7:
                cout << ativo->maisProd() << endl;
                break;
            case 10:
                cout << grava(iss) << endl;
                break;
            case 11:
                cout << carregaJogo(iss) << endl;
                break;
            case 12:
                cout << apaga(iss) << endl;
                break;
            case 13:
            case 14:
            case 15:
                cout << debug(iss, vCmd) << endl;
                break;
        }
    }
    return true;
}

bool Interface::TFase() {
    cout << "Terceira Fase" << endl;
    string cmd;
    int vCmd = -1;
    int tec = 0, mil = 0;
    while(f != 1){
        cout << "Introduza o comando que pretende realizar (adquire/maismilitar): (avanca para continuar)" << endl;
        getline(cin, comando);
        istringstream iss(comando);
        iss >> cmd;
        vCmd = validaCmd(cmd);
        switch(vCmd){
            case 2:
                cout << lista(iss) << endl;
                break;
            case 3:
                return false;
            case 9:
                if(tec != 1) {
                    cout << adquire(iss);
                    tec = 1;
                }
                else {
                    cout << "Ja adquiriu tecnologias nesta ronda." << endl;
                }
                break;
            case 8:
                if(mil != 1) {
                    cout << ativo->addMilitar();
                    mil = 1;
                }
                else {
                    cout << "Ja adicionou forca nesta ronda." << endl;
                }
                break;
            case 10:
                cout << grava(iss) << endl;
                break;
            case 11:
                cout << carregaJogo(iss) << endl;
                break;
            case 12:
                cout << apaga(iss) << endl;
                break;
            case 13:
            case 14:
            case 15:
                cout << debug(iss, vCmd) << endl;
                break;
            default:
                cout << "Comando invalido para esta fase." << endl;
                break;
        }
    }
    return true;
}

bool Interface::QFase() {
    cout << "Quarta fase" << endl;
    string ret = ativo->evento(-1);
    if(ret == "Perdeu.\n"){
        cout << "Invasao sucedida. Perdeu o jogo." << endl;
        fim();
        return true;
    }
    else {
        cout << ret << endl;
        return false;
    }
}

void Interface::fim(){
    cout << "Acabou o jogo" << endl;
    cout << ativo->fim();
    return;
}