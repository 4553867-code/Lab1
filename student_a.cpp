// Variant 1 - Simpson's numerical integration method
// Student A implementation
#include "shared_types.h"
#include <cmath>
#include <stdexcept>
std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data) {
    if (!data || data->n <= 0 || data->n % 2 != 0) throw std::invalid_argument("Simpson requires positive even n");
    const double h = (data->b - data->a) / data->n;
    double sum = data->f(data->a) + data->f(data->b);
    for (int i = 1; i < data->n; ++i) sum += (i % 2 ? 4.0 : 2.0) * data->f(data->a + i * h);
    double value = sum * h / 3.0;
    return std::make_unique<Result>(Result{value, std::abs(value - data->exact), data->n + 1});
}
