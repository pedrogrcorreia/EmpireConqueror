#include <iostream>
#include "Interface.h"
#include "TiposContinente.h"
#include <sstream>
#include <typeinfo>
using namespace std;


//int main2(){
//    Jogo j;
//    Interface i(&j);
//    i.config();
//    while(j.getTurno() != 12) {
//        i.PFase();
//        i.SFase();
//        i.TFase();
//        i.QFase();
//    }
//    return 0;
//}


int main() {
    vector<Jogo*> jogos;
    Jogo j("Jogo 1");

    j.criaJogo();
    for(int i = 0; i < 3 ; i++) {
        j.addTerritorio("planicie");
    }
    for(int i = 0; i < 3 ; i++) {
        j.addTerritorio("refugio");
    }
    for(int i = 0; i < 3 ; i++) {
        j.addTerritorio("duna");
    }
    j.conquistaTerritorio("planicie1");
    j.conquistaTerritorio("refugio dos piratas2");
    j.addRecursos();
    j.addRecursos();
    j.addTecnologia("Drones militares");

    //cout << j.getAsString();
    jogos.push_back(&j);
    Jogo j1("Jogo 2");
    j1 = j;
    jogos.push_back(&j1);
    for(auto it : jogos) {
        cout << it->getAsString();
    }
    return 0;
}
