//
// Created by Pedro Correia.
//

#include "TiposIlha.h"

Refugio::Refugio():Ilha("refugio dos piratas"+to_string(count++),9){};

int Refugio::count = 1;

Pescaria::Pescaria():Ilha("pescaria"+to_string(count++), 9){};

int Pescaria::count = 1;