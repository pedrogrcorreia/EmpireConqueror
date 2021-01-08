//
// Created by Pedro Correia.
//

#include "Interface.h"
#include <iostream>
#include <sstream>
#include <fstream>

Interface::Interface(Jogo* jogo):j(jogo){};

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
            if (!j->addTerritorio(territorios[vN])) {
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
        return j->getAsString();
    }
    else{
        return j->listaTerritorio(nome);
    }
}

string Interface::adquire(istringstream& i) const{
    string nome, comp;
    int vT = -1;
    i >> nome;
    if(i >> comp){
        nome += " "+comp;
    }
    vT = validaTecnologia(nome);
    if(vT == -1){
        return "Nome da tecnologia errado. Tente novamente.";
    }
    else {
        return j->addTecnologia(nome);
    }
}

void Interface::config(){
    string cmd;
    int vCmd;
    if(!j->criaJogo()){
        cout << "Impossivel jogar. Tente novamente." << endl;
    }
    cout << "Bem vindo." << endl;
    while(1){
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
            case 3:
                cout << "Configuracao concluida." << endl;
                return;
            default:
                cout << "Comando invalido para configuracao." << endl;
                break;
        }
    }
}


void Interface::PFase(){
    j->setTurno();
    string cmd;
    int vCmd = -1;
    int acao = 0;
    while(1){
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
                return;
            case 4:
                if(acao == 1){
                    cout << "Ja tomou uma acao nesta fase, por favor avance." << endl;
                }
                else {
                    iss >> cmd;
                    cout << j->conquistaTerritorio(cmd);
                }
                acao = 1;
                break;
            case 5:
                if(acao == 1){
                    cout << "Ja tomou uma acao nesta fase, por favor avance." << endl;
                }
                acao = 1;
                break;
            default:
                cout << "Comando invalido para esta fase." << endl;
                break;
        }
    }
}

void Interface::SFase() {
    cout << "Segunda Fase" << endl;
    j->addRecursos();
    return;
}

void Interface::TFase() {
    cout << "Terceira Fase" << endl;
    string cmd;
    int vCmd = -1;
    int tec = 0, mil = 0;
    while(1){
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
                return;
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
                    cout << j->addMilitar();
                    mil = 1;
                }
                else {
                    cout << "Ja adicionou forca nesta ronda." << endl;
                }
                break;
            default:
                cout << "Comando invalido para esta fase." << endl;
                break;
        }
    }
}

void Interface::QFase() {
    return;
}