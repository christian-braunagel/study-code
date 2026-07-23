#include <iostream>
#include <vector>
#include <algorithm>

#include "drone_test_bench.hpp"

int main()
{
    const int COUNT_VALUE = 8;
    // Section I
    std::cout << '\n'
              << "-------------Section I-------------" << '\n';
    const int SIZE = 5;
    char testFrame[SIZE] = {'1', '2', '3', '4', '5'};

    if (SIZE <= 0)
    {
        std::cout << "Error: SIZE is zero or negative." << std::endl;
        return 1;
    }
    printFrame(testFrame);
    std::cout << min(testFrame) << std::endl;
    composeTags("Channel", "motor_temp", "Priority", 4);

    // Section II
    // Task 6
    std::cout << '\n'
              << "-------------Task 6-------------" << '\n';

    std::vector<int> recordedData = {42, 17, 42, 5, 99, 17, 63, 12};

    printVector(recordedData);

    std::sort(recordedData.begin(), recordedData.end());

    printVector(recordedData);

    std::vector<int>::iterator searchedValue;
    searchedValue = std::find(recordedData.begin(), recordedData.end(), 63);

    if (searchedValue == recordedData.end())
    {
        std::cout << "No value found" << std::endl;
    }
    else
    {
        std::cout << "Value exists" << std::endl;
    }

    // Task 7
    std::cout << '\n'
              << "-------------Task 7-------------" << '\n';

    std::vector<int> recordedData2 = {7, -1, 13, -1, 21, 21, 8, -1, 8};
    printVector(recordedData2);

    std::replace(recordedData2.begin(), recordedData2.end(), -1, 0);
    printVector(recordedData2);

    int valueCount = std::count(recordedData2.begin(), recordedData2.end(), COUNT_VALUE);
    std::cout << "The value " << COUNT_VALUE << " occurs " << valueCount << " times.\n";

    std::reverse(recordedData2.begin(), recordedData2.end());
    printVector(recordedData2);

    // Task 8
    std::cout << '\n'
              << "-------------Task 8-------------" << '\n';

    std::vector<int>::iterator iter;

    for (iter = recordedData2.begin(); iter != recordedData2.end(); ++iter)
    {
        std::cout << *iter << '\n';
    }

    // What does *it do?
    // Similar to the dereferencing of pointer, this operators allows
    // to read/access the element the iterator is pointing to.

    // What does ++iter do?
    // The ++ operator moves the iterator to the next element of the container.
    // It is usually used a prefix operator because it is more efficient.
    // In case of postfix operator, a temporary iterator would be created
    // storing the previous element until the end of the loop iteration

    // Section III
    // Task 9a
    std::cout << '\n'
              << "-------------Task 9-------------" << '\n';
    std::vector<int> intData = {4, 7, 2, 9};
    std::vector<double> doubleData = {2.5, 3.0, 4.5, 1.0};

    std::cout << "Integer dataset\n";
    printMetricsReport(intData);
    std::cout << '\n';

    std::cout << "Double dataset\n";
    printMetricsReport(doubleData);

    // Task 9b
    // Fixed-size sensor frames
    int temperatureFrame[5] = {22, 24, 23, 25, 21};
    std::vector<int> temperatureData = convertToVector(temperatureFrame);

    std::cout << "Temperature Frame Analysis\n";
    printMetricsReport(temperatureData);
    std::cout << '\n';

    // Task 9c

    std::vector<bool> motorStatus = {true, true, false, true, false};

    double avg = computeAverage(motorStatus);

    bool majority = (avg > 0.5);

    std::cout << "Motor was active for most of the test run: "
              << std::boolalpha << majority << '\n';

    return 0;
}