/**
 * @file reportable.hpp
 * @brief Declares the Reportable interface.
 */

#ifndef REPORTABLE_HPP
#define REPORTABLE_HPP

#include <string>

/**
 * @brief Interface for classes that can generate textual reports.
 */
class Reportable
{
public:
    /**
     * @brief Generates a textual report.
     *
     * @return Report as string
     */
    virtual std::string generate_report() const = 0;

    /**
     * @brief Virtual default destructor for polymorphic interface usage.
     */
    virtual ~Reportable() {};
};

#endif
