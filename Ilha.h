//
// Created by Pedro Correia.
//

#ifndef Ilha_H
#define Ilha_H
#include "Territorio.h"

using namespace std;

class Ilha: public Territorio{
    const int win = 2;
public:
    Ilha(string a, int b);
    virtual int getWin() const;
};


#endif //Ilha
