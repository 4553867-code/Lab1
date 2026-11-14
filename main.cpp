#include "shared_types.h"
#include <chrono>
#include <iomanip>
#include <iostream>
#include <vector>

int main() {
    auto data = std::make_shared<const InputData>(
        InputData{ [](double x) { return x * x * x * x; }, 0.0, 1.0, 10, 0.2 }
    );

    const auto startA = std::chrono::steady_clock::now();
    auto resultA = calculateA(data);
    const auto endA = std::chrono::steady_clock::now();

    const auto startB = std::chrono::steady_clock::now();
    auto resultB = calculateB(data);
    const auto endB = std::chrono::steady_clock::now();

    const double timeA = std::chrono::duration<double, std::micro>(endA - startA).count();
    const double timeB = std::chrono::duration<double, std::micro>(endB - startB).count();

    auto [valueA, errorA, evaluationsA] = *resultA;
    auto [valueB, errorB, evaluationsB] = *resultB;

    const std::vector<double> errors{ errorA, errorB };

    std::cout << std::fixed << std::setprecision(10);
    std::cout << "Integral of x^4 on [0, 1], n=" << data->n << "\n";
    std::cout << "Exact: " << data->exact << "\n";
    std::cout << "Simpson: " << valueA << ", error: " << errors[0]
        << ", evaluations: " << evaluationsA << "\n";
    std::cout << "Trapezoidal method: " << valueB << ", error: " << errors[1]
        << ", evaluations: " << evaluationsB << "\n";
    std::cout << "More accurate: "
        << (errors[0] < errors[1] ? "Simpson" :
            errors[1] < errors[0] ? "Trapezoids" : "equal") << "\n";
    std::cout << std::setprecision(3);
    std::cout << "Simpson time (microseconds): " << timeA << "\n";
    std::cout << "Trapezoids time (microseconds): " << timeB << "\n";
    return 0;
}
