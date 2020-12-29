//
// Created by Pedro Correia.
//

#ifndef Territorio_H
#define Territorio_H

#include <string>
using namespace std;

class Territorio {
protected:
    string nome;
    int res;
public:
    Territorio(string a, int b);
    string getNome() const;
    string getAsString() const;
};


#endif //Territorio
