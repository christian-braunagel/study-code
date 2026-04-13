#ifndef REPORT_UTILITIES_HPP
#define REPORT_UTILITIES_HPP

#include <cstdint>
#include <iostream>

/**
 * @brief Prints the report card
 *
 * @param[in] name          String containing student name
 * @param[in] homework      homework grade
 * @param[in] midterm       midterm grade
 * @param[in] final_exam    grade of final exam
 * @param[in] final_grade   the final grade
 * @param[in] letter_grade  string containing grade as letter
 */
void printReport(
    const std::string &name, std::uint_fast16_t homework,
    std::uint_fast16_t midterm, std::uint_fast16_t final_exam,
    double final_grade, const std::string &letter_grade);

/**
 * @brief Calculates the final grade
 *
 * @param[in] homework      homework grade
 * @param[in] midterm       midterm grade
 * @param[in] final_exam    grade of final exam
 * @param[out] final_grade  the final grade
 * @param[out] letter_grade string containing grade as letter
 */
void calculateGrade(
    std::uint_fast16_t homework, std::uint_fast16_t midterm,
    std::uint_fast16_t final_exam,
    double &final_grade, std::string &letter_grade);

/**
 * @brief Read in all student data. Calls readScore from within.
 *
 * @param[out] name          String containing student name
 * @param[out] homework      homework grade
 * @param[out] midterm       midterm grade
 * @param[out] final_exam    grade of final exam
 */
void readStudentData(std::string &name, std::uint_fast16_t &homework, std::uint_fast16_t &midterm, std::uint_fast16_t &final_exam);

/**
 * @brief Read in one number via std::cin and validate it.
 *
 * @param[in] text        String containing the text to output
 * @param[out] value      Input value of the user
 */
void readScore(const std::string &text, std::uint_fast16_t &value);

#endif