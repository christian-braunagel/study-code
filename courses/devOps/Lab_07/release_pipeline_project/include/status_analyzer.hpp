#ifndef STATUS_ANALYZER_HPP
#define STATUS_ANALYZER_HPP

#include <string>
#include <vector>

class StatusAnalyzer
{
  public:
    double averageLoad(const std::vector<int>& samples) const;
    std::string statusMessage(double averageLoad) const;
};

#endif
