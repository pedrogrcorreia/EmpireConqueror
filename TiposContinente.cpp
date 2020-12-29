//
// Created by Pedro Correia.
//

#include "TiposContinente.h"

TerritorioInicial::TerritorioInicial():Continente("Territorio Inicial", 9){};

// Planicie
Planicie::Planicie():Continente("planicie"+to_string(count++), 3){};

int Planicie::count = 1;

//Montanha

Montanha::Montanha():Continente("montanha"+to_string(count++), 6){};

int Montanha::count = 1;

//Fortaleza

Fortaleza::Fortaleza():Continente("fortaleza"+to_string(count++), 8){};

int Fortaleza::count = 1;

// Mina

Mina::Mina():Continente("mina"+to_string(count++), 5){};

int Mina::count = 1;

// Duna

Duna::Duna():Continente("duna"+to_string(count++), 4){};

int Duna::count = 1;

// Castelo

Castelo::Castelo():Continente("castelo"+to_string(count++), 7){};

int Castelo::count = 1;
