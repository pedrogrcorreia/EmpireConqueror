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
    int conquistado = -1;
public:
    Territorio(string a, int b);
    virtual ~Territorio(){
        cout << "Destruindo " << nome << ", "; // debug
    }
    bool ligaJogo(Jogo* j);
    void conquista();
    bool checkConquista();
    void invade();
    string getNome() const;
    int getRes() const;
    virtual string getAsString() const;
    virtual int addOuro() const;
    virtual int addProd() const;
    virtual int getWin() const;
    virtual Territorio* clone();
};


#endif //Territorio
