#include "status_analyzer.hpp"

#include <stdexcept>

double StatusAnalyzer::averageLoad(const std::vector<int>& samples) const
{
    if (samples.empty())
    {
        throw std::invalid_argument("samples must not be empty");
    }

    double total = 0.0;
    for (int sample : samples)
    {
        total += sample;
    }
    return total / samples.size();
}

std::string StatusAnalyzer::statusMessage(double averageLoad) const
{
    if (averageLoad >= 80.0)
    {
        return "OVERLOADED";
    }
    return "OK";
}
