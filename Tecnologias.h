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
    map<string, pair<bool, int>> mTec = { {"Drones militares", {false,3} },
                                         {"Misseis teleguiados", {false,4} },
                                         { "Defesas territoriais", {false,4} },
                                         { "Bolsa de valores", {false, 2} },
                                         { "Banco central", {false, 3}}
    };
public:
    int addTec(string tec, int v);
    bool checkTecnologia(string tec);
    string getTecnologias()const;
    string getAsString()const;
};


#endif //Tecnologias
