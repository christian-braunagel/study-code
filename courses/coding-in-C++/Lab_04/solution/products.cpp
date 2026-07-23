/**
 * @file products.cpp
 * @brief Implements the abstract Product base class.
 */

#include "products.hpp"

#include <string>
#include <sstream>

Product::Product(int id, const std::string &product_name, double product_weight,
                 double product_temperature, bool visual_defect)
    : product_id(id),
      name(product_name),
      weight(product_weight),
      temperature(product_temperature),
      has_visual_defect(visual_defect),
      inspection_result_count(0)
{
}

void Product::clear_results()
{
    inspection_result_count = 0;
}

void Product::add_result(const InspectionResult &result)
{
    if (inspection_result_count < MAX_INSPECTION_RESULTS)
    {
        inspection_results[inspection_result_count] = result;
        inspection_result_count++;
    }
}

std::string Product::generate_report() const
{
    std::string report;
    bool all_passed = true;

    report += "Product: " + name + " (ID: " + std::to_string(product_id) + ")\n";
    report += "Type: " + get_product_type() + "\n";

    for (int index = 0; index < inspection_result_count; index++)
    {
        report += "- " + inspection_results[index].inspection_name + ": ";

        if (inspection_results[index].passed)
        {
            report += "PASS\n";
        }
        else
        {
            report += "FAIL\n";
            all_passed = false;
        }
    }

    report += "\nFinal Result: ";

    if (all_passed)
    {
        report += "ACCEPTED\n";
    }
    else
    {
        report += "REJECTED\n";
    }

    return report;
}
