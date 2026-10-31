// just a simple test example
#include "status_analyzer.hpp"

#include <gtest/gtest.h>

TEST(OverloadingTests, Overlaod)
{
    StatusAnalyzer analyzer;
    EXPECT_TRUE(analyzer.isOverloaded(80));
}