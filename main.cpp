#include <iostream>
#include "tasksolver.hpp"

int main() {
    double roott = FindRoot();

    std::cout << "Приближённое значение корня: " << roott << '\n';

    return 0;
}
