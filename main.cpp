#include "shared_types.h"
#include <cmath>
#include <iomanip>
#include <iostream>
int main() {
    // Integral of x^4 from 0 to 1 equals 1/5.
    auto data = std::make_shared<const InputData>(InputData{[](double x) { return x*x*x*x; }, 0.0, 1.0, 10, 0.2});
    auto resultA = calculateA(data);
    auto resultB = calculateB(data);
    auto [valueA, errorA, evaluationsA] = *resultA;
    auto [valueB, errorB, evaluationsB] = *resultB;
    std::cout << std::fixed << std::setprecision(10);
    std::cout << "Integral of x^4 on [0, 1], n=" << data->n << "\n";
    std::cout << "Exact: " << data->exact << "\n";
    std::cout << "Simpson: " << valueA << ", error: " << errorA << ", evaluations: " << evaluationsA << "\n";
    std::cout << "Trapezoids: " << valueB << ", error: " << errorB << ", evaluations: " << evaluationsB << "\n";
    std::cout << "More accurate: " << (errorA < errorB ? "Simpson" : errorB < errorA ? "Trapezoids" : "equal") << "\n";
}
