#include <cmath>
#include <iomanip>
#include <iostream>

namespace {
const int kBeginSequenceTask1 = 5;
const int kStepSequenceTask1 = 5;

const int kBeginSequenceNegativeTask2 = 3;
const int kEndSequenceNegativeTask2 = 9;
const int kStepSequenceNegativeTask2 = 3;

const int kBeginSequencePositiveTask2 = 2;
const int kEndSequencePositiveTask2 = 8;
const int kStepSequencePositiveTask2 = 2;

const int kMimPositiveNumberTask2 = 0;

const int kPrintPrecisionX = 1;
const int kPrintPrecisionFuction = 6;
const double kEps = 1e-6;
const double kStepOfTask3 = 0.2;
const int kColumnWidth = 15;

const double kEndSequenceTask3 = 1.0;

const int kBeginingSequenceTask4 = 1;

const int kCheckpoint1Task4 = 3;
const int kCheckpoint2Task4 = 5;
const int kCheckpoint3Task4 = 10;
}  // namespace

void cinIntInteger(int& inputNumber) {
    std::cin >> inputNumber;
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Некорректные данные. Введите число повторно:\n";
        std::cin >> inputNumber;
    }
}

void cinIntNatural(int& inputNumber) {
    std::cin >> inputNumber;
    while (std::cin.fail() || inputNumber < 1) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Некорректные данные. ";
        if (inputNumber < 1) {
            std::cout << "Число должно быть натуральным! ";
        }
        std::cout << "Введите число повторно:\n";
        std::cin >> inputNumber;
    }
}

void cinDouble(double& inputNumber) {
    std::cin >> inputNumber;
    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Некорректные данные. Введите число повторно:\n";
        std::cin >> inputNumber;
    }
}

void TaskOne() {
    int n = 0;
    int m = 0;
    std::cout << "Введите числа n и m:\n";
    cinIntNatural(n);
    cinIntNatural(m);
    if (m >= n) {
        std::cout << "m должно быть меньше n\n";
        return;
    }
    int summary = 0;
    for (int i = kBeginSequenceTask1; i < n; i += kStepSequenceTask1) {
        if (i % m != 0) {
            summary += i;
        }
    }
    std::cout << "Ответ: " << summary << '\n';
}

void TaskTwo() {
    double a = 0.;
    double multiply = 1;
    std::cout << "Введите число a:\n";
    cinDouble(a);
    std::cout << "Ответ: ";
    if (a < kMimPositiveNumberTask2) {
        for (int i = kBeginSequenceNegativeTask2; i <= kEndSequenceNegativeTask2; i += kStepSequenceNegativeTask2) {
            multiply *= (i - 2);
        }
        std::cout << multiply;
    } else {
        for (int i = kBeginSequencePositiveTask2; i <= kEndSequencePositiveTask2; i += kStepSequencePositiveTask2) {
            multiply *= pow(i, 2);
        }
        multiply -= a;
        std::cout << multiply;
    }
    std::cout << '\n';
}

struct CalculationResult {
    double Y;
    double S;
    int N;
    void CalculateTaylorSeriesOfS(double x, double eps = kEps) {
        double lastTerm = -1.5 * pow(x, 2);
        N = 1;
        S = 1 + lastTerm;
        while (std::abs(lastTerm) > eps) {
            lastTerm *= -(2 * pow(N, 2) + 4 * N + 3) / (8 * pow(N, 4) + 12 * pow(N, 3) + 8 * pow(N, 2) + 6 * pow(N, 1) + 2) * pow(x, 2);
            S += lastTerm;
            ++N;
        }
    }
    void CalculateTaylorSeriesOfY(double x) { Y = (1 - pow(x, 2) / 2) * std::cos(x) - x / 2 * std::sin(x); }
};

void TaskThree() {
    std::cout << std::setw(kColumnWidth) << "x" << std::setw(kColumnWidth) << "Y(x)" << std::setw(kColumnWidth) << "S(x)" << std::setw(kColumnWidth)
              << "N" << '\n';
    double x = 0;
    while (x <= kEndSequenceTask3) {
        CalculationResult taylorResult;
        taylorResult.CalculateTaylorSeriesOfS(x);
        taylorResult.CalculateTaylorSeriesOfY(x);
        std::cout << std::setw(kColumnWidth) << std::setprecision(kPrintPrecisionX) << x << std::setw(kColumnWidth)
                  << std::setprecision(kPrintPrecisionFuction) << taylorResult.Y << std::setw(kColumnWidth) << taylorResult.S
                  << std::setw(kColumnWidth) << taylorResult.N << '\n';
        x += kStepOfTask3;
    }
}

void TaskFour() {
    int n = 0;
    std::cout << "Введите число n:\n";
    cinIntNatural(n);
    double y = 0;
    for (int i = kBeginingSequenceTask4; i <= n; i++) {
        y = sqrt(y + 2 * i);
        if ((i == kCheckpoint1Task4 && n != kCheckpoint1Task4) || (i == kCheckpoint2Task4 && n != kCheckpoint2Task4) ||
            (i == kCheckpoint3Task4 && n != kCheckpoint3Task4)) {
            std::cout << "n = " << i << "\t Ответ = " << y << '\n';
        }
    }
    std::cout << "Итоговый ответ = " << y << '\n';
}

void PrintMenu() {
    std::cout << "------------------MENU------------------\n";
    std::cout << "|             1 - Задача 1             |\n";
    std::cout << "|             2 - Задача 2             |\n";
    std::cout << "|             3 - Задача 3             |\n";
    std::cout << "|             4 - Задача 4             |\n";
    std::cout << "----------------------------------------\n";
}

int main(int, char**) {
    std::cout << std::fixed << std::setprecision(kPrintPrecisionFuction);
    std::cout << "Введите задачу, которую хотите решить. Вводе должно быть число. \n";
    char continueExecution = 'y';
    while (continueExecution == 'y') {
        PrintMenu();
        int numberTask = 0;
        cinIntNatural(numberTask);
        switch (numberTask) {
            case 1:
                TaskOne();
                break;
            case 2:
                TaskTwo();
                break;
            case 3:
                TaskThree();
                break;
            case 4:
                TaskFour();
                break;
            default:
                std::cout << "Такой задачи пока что нет.\n";
                break;
        }
        std::cout << "Продолжить работу? (y/n)\n";
        std::cin >> continueExecution;
    }
    std::cout << "Мяу\n";
}
