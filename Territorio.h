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
    int conquistado = 0;
public:
    Territorio(string a, int b);
    virtual ~Territorio(){
        cout << "Destruindo " << nome << ", "; // debug
    }
    bool ligaJogo(Jogo* j);
    string getNome() const;
    int getRes() const;
    string getAsString() const;
    void conquista(){conquistado = 1;}
    virtual int addOuro();
    virtual int addProd();
    virtual Territorio* clone(){
        return new Territorio(*this);
    }
};


#endif //Territorio
