/**
 * @file vector2d.cpp
 * @brief Implementation of a 2D vector class with operator overloading.
 */
#include <iostream>
#include <cmath>

/**
 * @class Vector2D
 * @brief Represents a 2D vector with x and y coordinates.
 */
class Vector2D
{
private:
    double x;
    double y;

public:
    /**
     * @brief Default constructor.
     * Initializes vector to (0.0, 0.0).
     */
    Vector2D() : x(0.0), y(0.0) {}

    /**
     * @brief Parameterized constructor.
     * @param[in] x_value X coordinate
     * @param[in] y_value Y coordinate
     */
    Vector2D(double x, double y) : x(x), y(y) {}

    /**
     * @brief Returns the x-coordinate.
     * @return X value
     */
    double getX() const { return x; }

    /**
     * @brief Returns the y-coordinate.
     * @return Y value
     */
    double getY() const { return y; }

    /**
     * @brief Prints the vector to standard output.
     */
    void print() const
    {
        std::cout << '\n'
                  << "(" << this->getX() << ", " << this->getY() << ")" << std::endl;
    }

    /**
     * @brief Computes the magnitude of the vector.
     * @return Length of the vector
     */
    double getMagnitude() const
    {
        return sqrt((x * x) + (y * y));
    }

    /**
     * @brief Computes the magnitude rounded to given precision.
     * @param[in] precision Number of decimal places
     * @return Rounded length
     */
    double getMagnitude(int precision) const;

    /**
     * @brief Adds another vector to this vector.
     * @param[in] other Vector to add
     * @return Reference to modified vector
     */
    void operator+=(const Vector2D &vec)
    {
        this->x += vec.getX();
        this->y += vec.getY();
    }

    /**
     * @brief Compares two vectors for equality with tolerance.
     * @param[in] other Vector to compare
     * @return True if equal within tolerance
     */
    bool operator==(const Vector2D &vec) const;

    /**
     * @brief Compares two vectors for inequality.
     * @param[in] other Vector to compare
     * @return True if not equal
     */
    bool operator!=(const Vector2D &vec) const;
};

double Vector2D::getMagnitude(int precision) const
{
    double factor = std::pow(10.0, precision);
    double length = this->getMagnitude();
    return std::round(length * factor) / factor;
}

bool Vector2D::operator==(const Vector2D &vec) const
{
    const double EPSILON = 1e-9;
    return (std::fabs(x - vec.x) < EPSILON) &&
           (std::fabs(y - vec.y) < EPSILON);
}

bool Vector2D::operator!=(const Vector2D &vec) const
{
    const double EPSILON = 1e-9;
    return (std::fabs(x - vec.x) > EPSILON) ||
           (std::fabs(y - vec.y) > EPSILON);
}

/*********** Free Functions ************/

/**
 * @brief Adds two vectors.
 * @param[in] vec_left Left-hand side vector
 * @param[in] vec_right Right-hand side vector
 * @return Resulting vector
 */
Vector2D operator+(const Vector2D &vec_left, const Vector2D &vec_right)
{
    return Vector2D(vec_left.getX() + vec_right.getX(),
                    vec_left.getY() + vec_right.getY());
}

/**
 * @brief Multiplies scalar by vector.
 * @param[in] scalar Scalar value
 * @param[in] vec Vector
 * @return Resulting vector
 */
Vector2D operator*(int scalar, const Vector2D &vec)
{
    return Vector2D(scalar * vec.getX(), scalar * vec.getY());
}

/**
 * @brief Multiplies vector by scalar.
 * @param[in] vec Vector
 * @param[in] scalar Scalar value
 * @return Resulting vector
 */
Vector2D operator*(const Vector2D &vec, double scalar)
{
    return Vector2D(scalar * vec.getX(), scalar * vec.getY());
}

/**
 * @brief Outputs vector to stream.
 * @param[in,out] outstream Output stream
 * @param[in] vec Vector to print
 * @return Reference to stream
 */
std::ostream &operator<<(std::ostream &outstream, const Vector2D &vec)
{
    outstream << "(" << vec.getX() << ", " << vec.getY() << ")";
    return outstream;
}

int main()
{
    // Part 2
    Vector2D vec1(4, 5);
    Vector2D vec2(1, 9);

    std::cout << vec1.getMagnitude() << std::endl;
    std::cout << vec1.getMagnitude(3) << std::endl;

    // Part 3
    Vector2D vec3 = vec1 + vec2;
    vec3.print();
    vec1 += vec2;
    vec1 = vec1 * 5;
    std::cout << vec1 << std::endl;

    // Part 4
    Vector2D vec4(1, 9);

    std::cout << (vec4 == vec2) << std::endl;
    std::cout << (vec1 != vec2) << std::endl;

    return 0;
}
