//
// Created by Pedro Correia.
//

#ifndef Tecnologias_H
#define Tecnologias_H

#include <map>
#include <string>

using namespace std;

class Tecnologias {
    map<string, pair<bool, int>> Tec = { {"Drones militares", {false,3} },
                                         {"Misseis Teleguiados", {false,4} },
                                         { "Defesas territoriais", {false,4} },
                                         { "Bolsa de valores", {false, 2} },
                                         { "Bando central", {false, 3}}
    };
public:
    void addTec(string tec);
    string getTecnologias()const;
    string getAsString()const;
};


#endif //Tecnologias
