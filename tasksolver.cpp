#include <cmath>
#include "variables.hpp"

// Итерационный метод для нахождения корня уравнения x = cos(x)
double FindRoot() {
    double permissibleError = FirstTaskInputVariable();
    nextX = cos(xN);
    while (std::abs(nextX - xN) >= permissibleError && iterationsCounter <= kMaxIterations) {
        xN = nextX;
        nextX = cos(xN);
        ++iterationsCounter;
    }
    return xN;                   // найденное приближение корня
}
