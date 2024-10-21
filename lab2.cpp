#include <cmath>
#include <iomanip>
#include <iostream>

namespace {
const int kTerm1 = 3;
const int kTerm2 = 5;
const int kTerm3 = 10;

const int kDefaultWidth = 5;
const int kTask3tWidth = 15;

const int kPrecisionX = 2;
const int kPrecisionYS = 8;
}  // namespace

void FirstTask() {
    int n{};
    int m{};
    std::cout << "Введите два натуральных, числовых значения n и m, таких что n>m" << '\n';
    std::cin >> n >> m;

    const int step = 5;
    const int rangeBegin = 5;

    int sum{};
    for (int i = rangeBegin; i <= n; i += step) {
        if (i % m != 0) {
            sum += i;
        }
    }
    std::cout << sum << '\n';
}

void SecondTask() {
    double a{};
    double product = 1.0;

    const int kNotNegativeAEnd = 9;
    const int kNegativeAEnd = 8;
    const int kNotNegativeABeginRange = 2;
    const int kNegativeABeginRange = 3;
    const int kNotNegativeAStep = 2;
    const int kNegativeAStep = 3;
    const int kZero = 0;
    const int kTwo = 2;

    std::cout << "Введите числовое значение a " << '\n';
    std::cin >> a;

    if (a >= kZero) {
        for (int i = kNotNegativeABeginRange; i <= kNotNegativeAEnd; i += kNotNegativeAStep) {
            product *= (i * i - a);
        }
    } else {
        for (int i = kNegativeABeginRange; i <= kNegativeAEnd; i += kNegativeAStep) {
            product *= (i - kTwo);
        }
    }

    std::cout << product << '\n';
}

void CalculateTaylorSeries(double x) {
    const double epsilon = 1e-6;
    double y = std::cos(x) * (1 - x * x / 2.0) - std::sin(x) * (x / 2);
    int n = 1;
    double lastTerm = -1.5 * pow(x, 2);
    double s = 1.0 + lastTerm;

    while (std::abs(lastTerm) > epsilon) {
        double k = -(2 * pow(n, 2) + 4 * n + 3) / (8 * pow(n, 4) + 12 * pow(n, 3) + 8 * pow(n, 2) + 6 * pow(n, 1) + 2) * pow(x, 2);
        lastTerm *= k;
        s += lastTerm;
        ++n;
    }

    std::cout << std::setw(kDefaultWidth) << std::fixed << std::setprecision(kPrecisionX) << x << std::setw(kTask3tWidth)
              << std::setprecision(kPrecisionYS) << y << std::setw(kTask3tWidth) << std::setprecision(kPrecisionYS) << s << std::setw(kDefaultWidth)
              << n << std::endl;
}

void ThirdTask() {
    const double h = 0.2;
    const double maxH = 1.0;
    double x = 0.0;

    std::cout << std::setw(kDefaultWidth) << "x" << std::setw(kTask3tWidth) << "Y" << std::setw(kTask3tWidth) << "S" << std::setw(kDefaultWidth)
              << "n" << std::endl;

    while (x <= maxH) {
        CalculateTaylorSeries(x);
        x += h;
    }
}

double CalculateY(int n, int terms) {
    double sum = 0.0;
    int lastN = n - terms;
    for (int i = 1; i <= terms; i++) {
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

int main(int, char**) {
    char continueExecution = 'y';

    while (continueExecution == 'y') {
        std::cout << "Задача 1: Поиск суммы натуральных чисел на отрезке от 1 до n" << '\n';
        std::cout << "Задача 2: Вычисление произведения ряда чисел с заданным условием" << '\n';
        std::cout << "Задача 3: Вычисление значения суммы ряда Тейлора" << '\n';
        std::cout << "Задача 4: Вычисление Y по предоставленной формуле" << '\n';
        std::cout << "Для выполнения задачи 1 - нажмите '1', для задачи 2 - '2', для задачи 3 - '3', для задачи 4 - '4'" << '\n';

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
        std::cout << "Хотите продолжить работу (y - продолжить, n - завершить)? " << '\n';
        std::cin >> continueExecution;
    }

    return 0;
}
