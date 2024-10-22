#include <iostream>
#include "variables.hpp"

double FirstTaskInputVariable() {
    std::cout << "Введите значение допустимой погрешности (например: 1e-6; 1e-8):   ";
    std::cin >> permissibleError;
    return permissibleError;
}
