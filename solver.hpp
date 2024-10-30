
namespace Solver {
void printResult(double x, int iterationsCount);

void RunIterationMethod();
void RunNewtonMethod();
void RunHalfCoefficientMethod();

enum class Solution {
    FirstSolution = 1,
    SecondSolution = 2,
    ThirdSolution = 3,
};

void start();
}  // namespace Solver
