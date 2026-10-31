#include "status_analyzer.hpp"

#include <gtest/gtest.h>
#include <stdexcept>

TEST(StatusAnalyzerTest, CalculatesAverageLoad)
{
    StatusAnalyzer analyzer;
    EXPECT_DOUBLE_EQ(analyzer.averageLoad({ 40, 60, 80 }), 60.0);
}

TEST(StatusAnalyzerTest, ClassifiesLoadAtBoundary)
{
    StatusAnalyzer analyzer;
    EXPECT_EQ(analyzer.statusMessage(79.0), "OK");
    EXPECT_EQ(analyzer.statusMessage(80.0), "OVERLOADED");
}

TEST(StatusAnalyzerTest, RejectsEmptySamples)
{
    StatusAnalyzer analyzer;
    EXPECT_THROW(analyzer.averageLoad({}), std::invalid_argument);
}
