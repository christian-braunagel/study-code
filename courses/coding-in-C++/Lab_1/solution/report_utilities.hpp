#ifndef REPORT_UTILITIES_HPP
#define REPORT_UTILITIES_HPP

#include <cstdint>
#include <iostream>

void printReport(
    const std::string &name, std::uint_fast16_t homework,
    std::uint_fast16_t midterm, std::uint_fast16_t final_exam,
    double final_grade, const std::string &letter_grade);

void calculateGrade(
    std::uint_fast16_t homework, std::uint_fast16_t midterm,
    std::uint_fast16_t final_exam,
    double &final_grade, std::string &letter_grade);

void readStudentData(std::string &name, std::uint_fast16_t &homework, std::uint_fast16_t &midterm, std::uint_fast16_t &final_exam);

void readScore(const std::string &text, std::uint_fast16_t &value);

#endif