//
// Created by Pedro Correia.
//

#ifndef Tecnologias_H
#define Tecnologias_H

#include <map>
#include <string>
#include <sstream>

using namespace std;

class Tecnologias {
    map<string, pair<bool, int>> Tec = { {"Drones militares", {false,3} },
                                         {"Misseis Teleguiados", {false,4} },
                                         { "Defesas territoriais", {false,4} },
                                         { "Bolsa de valores", {false, 2} },
                                         { "Bando central", {false, 3}}
    };
public:
    string getAsString(){
        ostringstream os;
        for(auto entry : Tec){
            os << entry.first << ":" << endl;
            os << entry.second.first << " " << entry.second.second;
            os << endl;
        }
        return os.str();
    }
    void addTec(string tec){
        Tec[tec].first = true;
    }
};


#endif //Tecnologias
