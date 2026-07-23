#include <string>
#include <iostream>

class User
{
    // Only protected member can be inherited by the derived classes
    // and at the same time not be used outside of the class.
    // If we would use private, the attributes would not be visible/accessable in the derived classes.
protected:
    std::string name;
    int id;

public:
    /**
     * @brief Constructs a User object.
     *
     * Initializes the user's name and id.
     *
     * @param name Name of the user.
     * @param id Unique user id.
     */
    User(std::string name, int id) : name(name), id(id)
    {
        std::cout << "Constructor of User" << std::endl;
    };
    /**
     * @brief Prints the basic user information.
     *
     * Outputs the user's id and name.
     */
    void printInfo();
};

void User::printInfo()
{
    std::cout << "ID: " << this->id << '\n';
    std::cout << "Name: " << this->name << '\n';
}

class Student : public User
{
private:
    int matNr;

public:
    /**
     * @brief Constructs a Student object.
     *
     * Initializes the inherited User attributes and the student's matriculation number.
     *
     * @param name Name of the student.
     * @param id Unique user id.
     * @param matNr Matriculation number of the student.
     */
    Student(std::string name, int id, int matNr) : User(name, id), matNr(matNr)
    {
        std::cout << "Constructor of Student" << std::endl;
    };
    /**
     * @brief Prints student-specific role information.
     *
     * Outputs the role, inherited user information, and matriculation number.
     */
    void printRole()
    {
        std::cout << "Rolle: " << "Student" << '\n';
        std::cout << "ID: " << this->id << '\n';
        std::cout << "Name: " << this->name << '\n';
        std::cout << "Matrikelnr: " << this->matNr << '\n';
    }
};

class Instructor : public User
{
private:
    const double DEFAULT_SALARY = 3000;
    double salary;

public:
    /**
     * @brief Constructs an Instructor object.
     *
     * Initializes the inherited User attributes and the instructor salary.
     * If the given salary is negative, the default salary is used.
     *
     * @param name Name of the instructor.
     * @param id Unique user id.
     * @param salary Salary of the instructor.
     */
    Instructor(std::string name, int id, double salary) : User(name, id), salary(DEFAULT_SALARY)
    {
        std::cout << "Constructor of Instructor" << std::endl;
        if (salary >= 0)
        {
            this->salary = salary;
        }
    };
    /**
     * @brief Prints instructor-specific role information.
     *
     * Outputs the role, inherited user information, and salary.
     */
    void printRole()
    {
        std::cout << "Rolle: " << "Lehrer" << '\n';
        std::cout << "ID: " << this->id << '\n';
        std::cout << "Name: " << this->name << '\n';
        std::cout << "Gehalt: " << this->salary << '\n';
    }
};

int main()
{

    Student student1("Kai Rosenkranz", 1, 123456);
    Instructor instructor1("Nobuo Uematsu", 99, 10000);

    student1.printInfo();
    student1.printRole();

    instructor1.printInfo();
    instructor1.printRole();

    return 0;
}

// 1. If the access specifier is deleted, C++ uses a default:
//    class → private inheritance, struct → public inheritance.
//    With private inheritance, public members of the base class become private
//    in the derived class and are no longer accessible from outside.

// 2. The base class constructor must be called to properly initialize
//    inherited attributes. Otherwise, the base part of the object
//    would be uninitialized or incorrectly initialized.