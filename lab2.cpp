#include <iomanip>
#include <iostream>
#include <cmath>

namespace {
const int kTerm1 = 3;
const int kTerm2 = 5;
const int kTerm3 = 10;

const int kDefaultWidth = 5;
const int kTask3tWidth = 15;

const int kPrecisionX = 2;
const int kPrecisionYS = 8;

const int kALessZeroEndTask2 = 8;
const int kANotLessZeroEndTask2 = 9;

const int kStepALessZeroTask2 = 2;
const int kStepANotLessZeroTask2 = 2;
}  // namespace

void FirstTask() {
    int n{};
    int m{};
    std::cout << "Введите два натуральных, числовых значения n и m, таких что n>m" << '\n';
    std::cin >> n >> m;

    const int step = 5;
    const int rangeStart = 5;

    int sum{};
    for (int i = rangeStart; i <= n; i += step) {
        if (i % m != 0) {
            sum += i;
        }
    }
    std::cout << sum << '\n';
}

void SecondTask() {
    double a{};
    double product = 1.0;
    std::cout << "Введите числовое значение a " << '\n';
    std::cin >> a;
    if (a >= 0) {
        for (int i = 2; i <= kANotLessZeroEndTask2; i += kStepANotLessZeroTask2) {
            product *= (i * i - a);
        }
    } else {
        for (int i = 3; i <= kALessZeroEndTask2; i += kStepALessZeroTask2) {
            product *= (i - 2);
        }
    }

    std::cout << product << '\n';
}

double ComputeY(double x) {
    return (std::exp(x) + std::exp(-x)) / 2.0;
}

void ThirdTask() {
    const double h = 0.2;
    const double eps = 1e-6;

    std::cout << std::setw(kDefaultWidth) << "x" << std::setw(kTask3tWidth) << "Y(x)" << std::setw(kTask3tWidth) << "S(x)" << std::setw(kDefaultWidth)
              << "N" << '\n';

    for (double x = 0; x <= 1; x += h) {
        double Y = ComputeY(x);
        double S = 1.0;
        double term = 1.0;
        int n = 1;

        while (std::fabs(term) >= eps) {
            term *= x * x / (2.0 * n * (2.0 * n - 1.0));
            S += term;
            ++n;
        }

        std::cout << std::setw(kDefaultWidth) << std::fixed << std::setprecision(kPrecisionX) << x << std::setw(kTask3tWidth) << std::fixed
                  << std::setprecision(kPrecisionYS) << Y << std::setw(kTask3tWidth) << std::fixed << std::setprecision(kPrecisionYS) << S
                  << std::setw(kDefaultWidth) << n << '\n';
    }
}

double CalculateY(int n, int terms) {
    double sum = 0.0;
    int lastN = n - terms + 1;
    for (int i = 0; i < terms; i++) {
        sum = sqrt(2 * (lastN + i) + sum);
    }
    return sum;
}

void FourthTask() {
    int n;

    std::cout << "Введите натуральное число n: ";
    std::cin >> n;

    std::cout << "Результат для 3 слагаемых: " << CalculateY(n, kTerm1) << '\n';
    std::cout << "Результат для 5 слагаемых: " << CalculateY(n, kTerm2) << '\n';
    std::cout << "Результат для 10 слагаемых: " << CalculateY(n, kTerm3) << '\n';
    if (n != kTerm1 && n != kTerm2 && n != kTerm3) {
        std::cout << "Результат для " << n << " слагаемых: " << CalculateY(n, n) << '\n';
    }
}
int main(int, char**){
    char continueExecution = 'y';
    while (continueExecution == 'y') {
        std::cout << "Задача 1: Поиск суммы натуральных чисел на отрезке от 1 до n" << std::endl;
        std::cout << "Задача 2: Вычисление произведения ряда чисел с заданным условием" << std::endl;
        std::cout << "Задача 3: Вычисление значения суммы ряда Тейлора" << std::endl;
        std::cout << "Задача 4: Вычисление Y по предоставленной формуле" << std::endl << std::endl;
        std::cout << "Для выполнения задачи 1 - нажмите '1', для задачи 2 - '2', для задачи 3 - '3', для задачи 4 - '4'" << std::endl;

        char enteredTaskNum = {};
        std::cin >> enteredTaskNum;
        switch (enteredTaskNum) {
            case '1':
                FirstTask();
                break;
            case '2':
                SecondTask();
                break;
            case '3':
                ThirdTask();
                break;
            case '4':
                FourthTask();
                break;
            default:
                std::cout << "Введён несуществующий номер задачи" << '\n';
                break;
        }
        std::cout << "Хотите продолжить работу (y - продолжить, n - завершить)? ";
        std::cin >> continueExecution;
    }

    return 0;
}
