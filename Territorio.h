//
// Created by Pedro Correia.
//

#ifndef Territorio_H
#define Territorio_H

#include <string>
#include <iostream>
using namespace std;

class Jogo;

class Territorio {
    string nome;
    int res;
protected:
    Jogo* jogo;
public:
    Territorio(string a, int b);
    virtual ~Territorio(){
        cout << "Destruindo " << nome << ", "; // debug
    }
    bool ligaJogo(Jogo* j);
    string getNome() const;
    string getAsString() const;
    virtual int addOuro();
    virtual int addProd();
};


#endif //Territorio
