//
// Created by Pedro Correia.
//

#include "Imperio.h"
#include <sstream>
bool Imperio::addTerritorio(Territorio *t) {
    imp.push_back(t);
    return true;
}

string Imperio::getAsString() const {
    ostringstream os;
    for(auto it : imp){
        os << it->getAsString() << endl;
    }
    return os.str();
}
