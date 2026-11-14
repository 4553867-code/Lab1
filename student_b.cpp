#include "shared_types.h"
#include <cmath>
#include <stdexcept>
std::unique_ptr<Result> calculateB(std::shared_ptr<const InputData> data) {
    if (!data || data->n <= 0) throw std::invalid_argument("Trapezoids require positive n");
    const double h = (data->b - data->a) / data->n;
    double sum = (data->f(data->a) + data->f(data->b)) / 2.0;
    for (int i = 1; i < data->n; ++i) sum += data->f(data->a + i * h);
    double value = sum * h;
    return std::make_unique<Result>(Result{value, std::abs(value - data->exact), data->n + 1});
}
