//
// Created by Pedro Correia.
//

#ifndef Tecnologias_H
#define Tecnologias_H

#include <map>
#include <string>
#include <vector>

using namespace std;

class Tecnologias {
    map<pair<string,string>, pair<bool, int>> mTec = {
            { {"Drones militares", "Aumenta forca militar para 5."}, {false, 3} },
            { {"Misseis teleguiados", "Necessario para conquistar ilhas."}, {false, 4} },
            { {"Defesas territoriais", "Acrescenta 1 de resistencia a um territorio invadido"}, {false, 4} },
            { {"Bolsa de valores",     "Permite trocas entre ouro e produtos"}, {false, 2} },
            { {"Banco central",        "Aumenta a capacidade do cofre e armazem para 5."}, {false, 3} }
    };
public:
    bool addTec(string tec);
    bool checkTecnologia(string tec);
    int getPreco(string n);
    int getNTecnologias() const;
    string getTecnologias() const;
    string getTecnologiasN() const;
    string getAsString() const;
};


#endif //Tecnologias
