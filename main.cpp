#include <iostream>
#include "Jogo.h"
#include "TiposContinente.h"

using namespace std;

/*template<typename T> Territorio * createInstance() { return new T; }

typedef std::map<std::string, Territorio*(*)()> map_type;



int main(){
//    Mundo m;
    map_type map1;
    map1["DerivedA"] = &createInstance<Planicie>;
    map1["DerivedB"] = &createInstance<Montanha>;
    Territorio* t = map1["DerivedA"]();
    Territorio* t2 = map1["DerivedA"]();
    Territorio* t3 = map1["DerivedB"]();
    cout << t->getAsString();
    cout << t2->getAsString();
    cout << t3->getAsString();
//    cout << m.getAsString();
    return 0;
} this works map */

int main() {
    Jogo j;
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
    j.addTecnologia("Drones militares");
    j.addRecursos();
    j.addRecursos();
    cout << j.getAsString();
    return 0;
}
