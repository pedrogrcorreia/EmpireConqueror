#ifndef UTILS_H
#define UTILS_H
#include <random>
#include <ctime>

double getRandomConquista(){
    static default_random_engine e(time(0));
    static uniform_real_distribution<double> u(0.0, 6.0);
    return u(e);
}
#endif //UTILS_H
