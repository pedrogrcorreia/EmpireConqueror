//
// Created by Pedro Correia.
//

#ifndef Interface_H
#define Interface_H
#include "Jogo.h"

using namespace std;

class Interface {
    vector<Jogo*> jogos;
    Jogo* ativo;
    string comando;
    vector<string> comandos = {"cria", "carrega", "lista", "avanca", "conquista", "passa", "maisouro", "maisprod", "maismilitar",
                               "adquire", "grava", "ativa", "apaga",
                                "toma", "modifica", "fevento"};
    vector<string> territorios = {"duna", "planicie", "montanha", "castelo", "fortaleza", "mina", "refugio", "pescaria"};
    vector<string> tecnologias = {"Drones militares", "Misseis teleguiados", "Defesas territoriais", "Bolsa de valores", "Banco central"};
    vector<string> eventos = {"recurso","invasao", "alianca", "nada"};
    int f = 0;
public:
    Interface();
    ~Interface();
    int validaCmd(string c) const;
    int validaNome(string n) const;
    int validaTecnologia(string n) const;
    int validaEvento(string n) const;
    string cria(istringstream& i) const;
    string lista(istringstream& i) const;
    string carrega(istringstream& i);
    string adquire(istringstream& i) const;
    string grava(istringstream& i);
    string carregaJogo(istringstream& i);
    string apaga(istringstream& i);
    string debug(istringstream& i, int vCmd);
    void start();
    bool config();
    bool PFase();
    bool SFase();
    bool TFase();
    bool QFase();
    void fim();
};


#endif //Interface
