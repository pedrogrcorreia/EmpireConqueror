//
// Created by Pedro Correia.
//

#ifndef TPPOO_UTILS_H
#define TPPOO_UTILS_H

#include <random>       // 1. Biblioteca random
#include <ctime>

using namespace std;


double getRandomConquista(){
    static default_random_engine e(time(0));        // gerador de numeros aleatorios (unsigned int)
    static uniform_real_distribution<double> u(0.0, 6.0);
    return  u(e);
}

#endif //TPPOO_UTILS_H
