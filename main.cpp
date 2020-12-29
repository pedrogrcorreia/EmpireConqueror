#include <iostream>
#include "Jogo.h"
#include "TiposContinente.h"

using namespace std;

int mainL(){
    Mundo m;
    m.addTerritorio("planicie");
    m.addTerritorio("planicie");
    m.addTerritorio("planicie");
    m.addTerritorio("montanha");
    cout << m.getAsString();
    return 0;
}

int main() {
    Jogo j;
    j.criaJogo();
    for(int i = 0; i < 3 ; i++) {
        j.addTerritorio("planicie");
    }
    j.addTerritorio("planicie");
    j.addTerritorio("montanha");
    j.addTerritorio("montanha");
    cout << j.getAsString();
    return 0;
}
