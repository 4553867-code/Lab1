#pragma once
#include <functional>
#include <memory>
#include <string>
struct InputData { std::function<double(double)> f; double a; double b; int n; double exact; };
struct Result { double value; double error; int evaluations; };
std::unique_ptr<Result> calculateA(std::shared_ptr<const InputData> data);
std::unique_ptr<Result> calculateB(std::shared_ptr<const InputData> data);
