#include "status_analyzer.hpp"

#include <iostream>

int main()
{
    StatusAnalyzer analyzer;
    const double average = analyzer.averageLoad({ 42, 57, 61, 48 });
    std::cout << "Average load: " << average << '\n';
    std::cout << "Status: " << analyzer.statusMessage(average) << '\n';
}
