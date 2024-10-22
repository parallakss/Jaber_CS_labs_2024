#include <iostream>
#include "tasksolver.hpp"

int main() {
    double root = FindRoot();

    std::cout << "Приближённое значение корня: " << root << '\n';

    return 0;
}
