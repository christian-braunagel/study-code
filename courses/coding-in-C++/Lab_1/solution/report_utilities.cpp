/*
 * File: report_utilities.cpp
 * Description: Contains the functions to read the user input,
 *              calculate the grade and print it all out.
 */

#include "report_utilities.hpp"
#include <iomanip>
#include <limits>

const int MAX_POINTS = 100;

const int GRADE_LIMIT_A = 90;
const int GRADE_LIMIT_B = 80;
const int GRADE_LIMIT_C = 70;
const int GRADE_LIMIT_D = 60;
const int GRADE_LIMIT_E = 50;

const double FACTOR_HOMEWORK = 0.4;
const double FACTOR_FINAL_EXAM = 0.35;
const double FACTOR_MIDTERM = 0.25;

// read in user input from terminal
void readScore(const std::string &text, std::uint_fast16_t &value)
{

    while (true)
    {
        std::cout << text;

        // check if it is a valid number
        if (!(std::cin >> value))
        {
            std::cout << "Error: Not a valid number. Try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        // check if it is larger than 100
        else if (value > MAX_POINTS)
        {
            std::cout << "Error: Not in the valid number range. Try again." << std::endl;
            continue;
        }
        break;
    }
}

// read in user name and all scores
void readStudentData(std::string &name, std::uint_fast16_t &homework, std::uint_fast16_t &midterm, std::uint_fast16_t &final_exam)
{

    std::cout << "Enter the student's name: ";

    // removes leading whitespaces so that getline() is not immeadiately cancelled
    std::cin >> std::ws;

    if (!(std::getline(std::cin, name)))
    {
        std::cout << "Error while reading input stream." << std::endl;
    }

    readScore("Enter the homework score (0-100): ", homework);
    readScore("Enter the midterm score (0-100): ", midterm);
    readScore("Enter the final exam score (0-100): ", final_exam);
}

// calculate the final grade and also return the grade as letter
void calculateGrade(
    std::uint_fast16_t homework, std::uint_fast16_t midterm,
    std::uint_fast16_t final_exam,
    double &final_grade, std::string &letter_grade)
{

    final_grade = FACTOR_HOMEWORK * homework + FACTOR_MIDTERM * midterm + FACTOR_FINAL_EXAM * final_exam;

    if (final_grade >= GRADE_LIMIT_A)
    {
        letter_grade = "A";
    }
    else if (final_grade >= GRADE_LIMIT_B)
    {
        letter_grade = "B";
    }
    else if (final_grade >= GRADE_LIMIT_C)
    {
        letter_grade = "C";
    }
    else if (final_grade >= GRADE_LIMIT_D)
    {
        letter_grade = "D";
    }
    else if (final_grade >= GRADE_LIMIT_E)
    {
        letter_grade = "E";
    }
    else
    {
        letter_grade = "F";
    }
}

// output report card
void printReport(
    const std::string &name, std::uint_fast16_t homework,
    std::uint_fast16_t midterm, std::uint_fast16_t final_exam,
    double final_grade, const std::string &letter_grade)
{

    std::string status;

    if (letter_grade == "A" || letter_grade == "B" || letter_grade == "C")
    {
        status = "Passed";
    }
    else if (letter_grade == "D" || letter_grade == "E")
    {
        status = "Conditional Pass";
    }
    else
    {
        status = "Fail";
    }

    std::cout << std::endl;
    std::cout << std::setfill('-') << std::setw(30) << "" << std::endl;
    std::cout << std::left << std::setfill(' ') << "Student Report" << std::endl;
    std::cout << std::setfill('-') << std::setw(30) << "" << std::endl;
    std::cout << std::left << std::setfill(' ') << "Name: " << name << std::endl
              << std::endl;
    std::cout << "Scores" << std::endl;
    std::cout << std::setfill('-') << std::setw(30) << "" << std::endl;
    std::cout << std::left << std::setfill(' ') << std::setw(20) << "Homework" << std::right << ": " << std::fixed << std::setprecision(2) << static_cast<double>(homework) << std::endl;
    std::cout << std::left << std::setfill(' ') << std::setw(20) << "Midterm" << std::right << ": " << std::fixed << std::setprecision(2) << static_cast<double>(midterm) << std::endl;
    std::cout << std::left << std::setfill(' ') << std::setw(20) << "Final Exam" << std::right << ": " << std::fixed << std::setprecision(2) << static_cast<double>(final_exam) << std::endl;
    std::cout << std::endl;
    std::cout << std::left << std::setfill(' ') << std::setw(20) << "Final Grade" << std::right << ": " << std::fixed << std::setprecision(2) << final_grade << std::endl;
    std::cout << std::left << std::setfill(' ') << std::setw(20) << "Letter Grade" << std::right << ": " << letter_grade << std::endl;
    std::cout << std::left << std::setfill(' ') << std::setw(20) << "Status" << std::right << ": " << status << std::endl;
    std::cout << std::setfill('-') << std::setw(30) << "" << std::endl;
}