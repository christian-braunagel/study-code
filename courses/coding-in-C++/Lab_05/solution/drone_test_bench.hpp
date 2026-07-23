#ifndef DRONE_TEST_BENCH_HPP
#define DRONE_TEST_BENCH_HPP

#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <numeric> // std::accumulate

template <typename T>
void swap(T &firstValue, T &secondValue)
{
    std::cout << "Input" << '\n';
    std::cout << "First value: " << firstValue << '\n';
    std::cout << "Second value: " << secondValue << '\n';

    T tmp = firstValue;
    firstValue = secondValue;
    secondValue = tmp;

    std::cout << "Output" << '\n';
    std::cout << "First value: " << firstValue << '\n';
    std::cout << "Second value: " << secondValue << '\n';
}

// Question Task 1: Why a template is better here than writing three separate functions?
// Answer: There are multiple reasons why templates should be chosen over three separate functions:
// 1. Less effort for the programmer when writing the code
// 2. Less error-prone and better to maintain because there is only one implementation
// 3. Only instantiated when used so it can potentially reduce the binary size of the exe
// 4. Templates are perfect for reusability since each type can be used as long as the operations are defined.

/* Commented out below is the solution of the printFrame before task5 is implemented
/* template <typename T>
/* void printFrame(T frame, int size)
/* {
/*    std::cout << "[";
/*    for (int i = 0; i < size - 1; i++)
/*    {
/*        std::cout << frame[i] << ", ";
/*    }
/*    std::cout << frame[size - 1] << "]" << '\n';
/*}
*/

template <int N, typename T>
void printFrame(T (&frame)[N])
{
    std::cout << "[";
    for (int i = 0; i < N - 1; i++)
    {
        std::cout << frame[i] << ", ";
    }
    std::cout << frame[N - 1] << "]" << '\n';
}

/* Commented out below is the solution of the min-template before task5 is implemented */
/* template <typename T>
T min(T frame[], int size)
{

    T minValue = frame[0];
    for (int i = 1; i < size; i++)
    {
        if (frame[i] < minValue)
        {
            minValue = frame[i];
        }
    }
    return minValue;
} */

template <typename T, int N>
T min(T (&frame)[N])
{

    T minValue = frame[0];
    for (int i = 1; i < N; i++)
    {
        if (frame[i] < minValue)
        {
            minValue = frame[i];
        }
    }
    return minValue;
}

template <typename T, typename U>
void composeTags(std::string label1, T value1, std::string label2, U value2)
{

    std::cout << label1 << ": " << value1 << " | " << label2 << ": " << value2 << '\n';
}

/* Questions of Task 5:
/* 1. Why is the size no longer needed as a parameter?
/* Answer: Because the size is handed over via non-type template parameter.
/* The compiler knows the size at compile time, so it does not need to be passed at runtime.
/* 2. What advantage does this have compared to the previous version?
/* Answer: The function becomes safer and easier to use:
/* - The size cannot be passed incorrectly anymore
/* - There is no risk of mismatching array and size
/* - The compiler enforces correctness at compile time
/* - The function interface is simpler (fewer parameters)
*/

template <typename T>
void printVector(const std::vector<T> &data)
{
    std::cout << "[";

    for (auto element : data)
    {
        std::cout << element;
        if (element != data.back())
        {
            std::cout << ", ";
        }
    }

    std::cout << "]" << '\n';
}

template <typename T>
T computeSum(const std::vector<T> &data)
{
    return std::accumulate(data.begin(), data.end(), T());
}

template <typename T>
T computeMax(const std::vector<T> &data)
{
    return *std::max_element(data.begin(), data.end());
}

template <typename T>
double computeAverage(const std::vector<T> &data)
{
    T sum = computeSum(data);
    return static_cast<double>(sum) / data.size();
}

template <typename T>
void printMetricsReport(const std::vector<T> &data)
{
    std::cout << "Data: ";
    printVector(data);
    std::cout << '\n';

    std::cout << "Sum: " << computeSum(data) << '\n';
    std::cout << "Max: " << computeMax(data) << '\n';
    std::cout << "Average: " << computeAverage(data) << '\n';
}

template <typename T, int N>
std::vector<T> convertToVector(T (&frame)[N])
{
    std::vector<T> result;

    for (int i = 0; i < N; i++)
    {
        result.push_back(frame[i]);
    }

    return result;
}

template <>
double computeAverage<bool>(const std::vector<bool> &data)
{
    int trueCount = 0;

    for (std::size_t i = 0; i < data.size(); i++)
    {
        if (data[i] == true)
        {
            trueCount = trueCount + 1;
        }
    }

    // Anteil der true-Werte
    return static_cast<double>(trueCount) / data.size();
}

#endif