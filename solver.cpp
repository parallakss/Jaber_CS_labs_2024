#include "solver.hpp"
#include <cmath>
#include <iostream>

namespace {
const int kmaxIterationsCount = 1e8 - 1;

[[nodiscard]] double CalculateIterationMethodX(double coefficient, double x) {
    return coefficient * std::cos(x);
}

[[nodiscard]] double f(double x, double coefficient) {
    return x - coefficient * std::cos(x);
}

[[nodiscard]] double derivativef(double x, double coefficient) {
    return 1 + coefficient * std::sin(x);
}
}  // namespace

namespace Solver {
struct MethodResult {
    bool flag;
    double x;
    int iterationsCount;
};

void printResult(double x, int iterationsCount) {
    std::cout << '\n' << "Приближённое значение корня уравнения: " << x << '\n';
    std::cout << "Количество итераций: " << iterationsCount << '\n';
}

[[nodiscard]] MethodResult CalculateIterationMethod(double epsilon, double coefficient) {
    double x = 0.0;
    int iterationsCount = 0;

    while (fabs(coefficient * std::cos(x) - x) >= epsilon && iterationsCount < kmaxIterationsCount) {
        x = CalculateIterationMethodX(coefficient, x);
        ++iterationsCount;
    }

    MethodResult result = {true, x, iterationsCount};

    if (iterationsCount >= kmaxIterationsCount) {
        [[maybe_unused]] MethodResult result = {false, x, iterationsCount};
    }

    return result;
}

[[nodiscard]] MethodResult CalculateNewtonMethod(double initialApproximation, double epsilon, double coefficient) {
    double x = initialApproximation;
    int iterationsCount = 0;

    while (x >= epsilon && iterationsCount < kmaxIterationsCount) {
        double fX = f(x, coefficient);
        double derivativeFX = derivativef(x, coefficient);
        x -= fX / derivativeFX;
        ++iterationsCount;
    }

    MethodResult result = {true, x, iterationsCount};

    if (iterationsCount >= kmaxIterationsCount) {
        [[maybe_unused]] MethodResult result = {false, x, iterationsCount};
    }

    return result;
}

[[nodiscard]] MethodResult CalculateHalfingMethod(double epsilon, double coefficient, double LBoarder, double RBoarder) {
    int iterationsCount = 0;

    double root = 1.0;
    while (std::abs((RBoarder + coefficient * std::cos(RBoarder)) - (LBoarder + coefficient * std::cos(LBoarder))) > epsilon &&
           iterationsCount < kmaxIterationsCount) {
        root = (LBoarder + RBoarder) / 2;
        if ((root - coefficient * std::cos(root)) <= 0) {
            LBoarder = root;
        } else {
            RBoarder = root;
        }
    }

    MethodResult result = {true, root, iterationsCount};

    if (iterationsCount >= kmaxIterationsCount) {
        [[maybe_unused]] MethodResult result = {false, root, iterationsCount};
    }

    return result;
}

void RunIterationMethod() {
    double epsilon{};
    double coefficient{};

    std::cout << "Введите погрешность нахождения корня: ";
    std::cin >> epsilon;
    std::cout << "Введите коэффициент уравнения при cos(x): ";
    std::cin >> coefficient;

    MethodResult IterationMethodResult = CalculateIterationMethod(epsilon, coefficient);

    if (IterationMethodResult.flag == false) {
        std::cout << '\n' << "Введите другой коэффициент при cos(x) или другую погрешность" << '\n';
    } else {
        printResult(IterationMethodResult.x, IterationMethodResult.iterationsCount);
    }
}

void RunNewtonMethod() {
    double epsilon = {};
    double coefficient = {};
    double initialApproximation = {};

    std::cout << "Введите начальное приближение для поиска корня уравнения: ";
    std::cin >> initialApproximation;
    std::cout << "Введите погрешность для нахождения корня: ";
    std::cin >> epsilon;
    std::cout << "Введите коэффициент уравнения при cos(x): ";
    std::cin >> coefficient;

    MethodResult NewtonsMethodResult = CalculateNewtonMethod(initialApproximation, epsilon, coefficient);

    if (NewtonsMethodResult.flag == false) {
        std::cout << '\n' << "Введите другой коэффициент перед cos(x) или другое начальное приближение: " << '\n';
    } else {
        printResult(NewtonsMethodResult.x, NewtonsMethodResult.iterationsCount);
    }
}

void RunHalfCoefficientMethod() {
    double leftRangeLimit{};
    double rightRangeLimit{};
    double epsilon{};
    double coefficient{};

    std::cout << "Введите начало диапазона: ";
    std::cin >> leftRangeLimit;
    std::cout << "Введите конец диапазона: ";
    std::cin >> rightRangeLimit;
    std::cout << "Введите погрешность нахождения корня: ";
    std::cin >> epsilon;
    std::cout << "Введите коэффициент уравнения при cos(x): ";
    std::cin >> coefficient;

    MethodResult HalfCoefficientMethodResult = CalculateHalfingMethod(epsilon, coefficient, leftRangeLimit, rightRangeLimit);

    if (HalfCoefficientMethodResult.flag == false) {
        std::cout << '\n' << "Введите другой диапазон, погрешность или коэффициент при cos(x)" << '\n';
    } else {
        printResult(HalfCoefficientMethodResult.x, HalfCoefficientMethodResult.iterationsCount);
    }
}

void inputProcessing(Solution method) {
    switch (method) {
        case Solution::FirstSolution:
            RunIterationMethod();
            break;
        case Solution::SecondSolution:
            RunNewtonMethod();
            break;
        case Solution::ThirdSolution:
            RunHalfCoefficientMethod();
            break;
        default:
            std::cout << "Введён несуществующий номер задачи" << '\n';
            break;
    }
}

void start() {
    char continueExecution = 'y';

    while (continueExecution == 'y') {
        std::cout << "1 - Решение уравнения методом итерации" << '\n';
        std::cout << "2 - Решение уравнения методом Ньютона" << '\n';
        std::cout << "3 - Решение уравнения методом половинного деления" << '\n' << '\n';
        std::cout << "Введите номер задачи: ";

        int option{};
        std::cin >> option;

        inputProcessing(static_cast<Solution>(option));

        std::cout << "Хотите продолжить работу (y - продолжить, n - закончить): " << '\n';
        std::cin >> continueExecution;
    }
}
}  // namespace Solver
