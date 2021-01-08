//
// Created by Pedro Correia.
//

#ifndef Interface_H
#define Interface_H
#include "Jogo.h"

using namespace std;

class Interface {
    Jogo* j;
    string comando;
    vector<string> comandos = {"cria", "carrega", "lista", "avanca", "conquista", "passa", "maisouro", "maisprod", "maismilitar", "adquire"};
    vector<string> territorios = {"duna", "planicie", "montanha", "castelo", "fortaleza", "mina", "refugio", "pescaria"};
    vector<string> tecnologias = {"Drones militares", "Misseis teleguiados", "Defesas territoriais", "Bolsa de valores", "Banco central"};
public:
    Interface(Jogo* jogo);
    int validaCmd(string c) const;
    int validaNome(string n) const;
    int validaTecnologia(string n) const;
    string cria(istringstream& i) const;
    string lista(istringstream& i) const;
    string carrega(istringstream& i);
    string adquire(istringstream& i) const;
    void config();
    void PFase();
    void SFase();
    void TFase();
    void QFase();
};


#endif //Interface
