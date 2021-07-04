//
// Created by Pedro Correia.
//

#ifndef UTILS_H
#define UTILS_H
#include <random>
#include <ctime>

double getRandomDouble(double min, double max){
    static default_random_engine e(time(0));
    static uniform_real_distribution<double> u(min, max);
    return u(e);
}

int getRandomInt(int min, int max){
    static default_random_engine e(time(0));
    static uniform_int_distribution<int> u(min, max);
    return u(e);
}
#endif //UTILS_H
