/**
 * @file inspection.cpp
 * @brief Implements the abstract Inspection base class.
 */

#include "inspections.hpp"

#include <iomanip>
#include <sstream>

void Inspection::update_statistics(bool passed)
{
    performed_count++;

    if (passed)
    {
        passed_count++;
    }

    last_result = passed;
    last_result_available = true;
}

double Inspection::get_success_rate() const
{
    if (performed_count == 0)
    {
        return 0.0;
    }

    return static_cast<double>(passed_count) /
           static_cast<double>(performed_count) * 100.0;
}

std::string Inspection::generate_report() const
{
    std::ostringstream report;

    report << "Inspection: " << get_name() << "\n";

    if (last_result_available)
    {
        report << "Last Result: " << (last_result ? "PASS" : "FAIL") << "\n";
    }
    else
    {
        report << "Last Result: NOT PERFORMED\n";
    }

    report << "Success Rate: " << std::fixed << std::setprecision(2)
           << get_success_rate() << "%\n";

    return report.str();
}

/*********** Weight Check ***********/

bool WeightCheck::is_applicable(const Product &product) const
{
    return true;
}

bool WeightCheck::inspect(const Product &product)
{
    const double product_weight = product.get_weight();
    const bool passed = (product_weight >= minimum_weight) &&
                        (product_weight <= maximum_weight);

    update_statistics(passed);
    return passed;
}

/*********** Visual Inspection ***********/

bool VisualInspection::is_applicable(const Product &product) const
{
    return true;
}

bool VisualInspection::inspect(const Product &product)
{
    const bool passed = !product.get_has_visual_defect();

    update_statistics(passed);
    return passed;
}

/*********** Temperature Test ***********/

bool TemperatureTest::is_applicable(const Product &product) const
{
    return true;
}

bool TemperatureTest::inspect(const Product &product)
{
    const double product_temperature = product.get_temperature();
    const bool passed = (product_temperature >= minimum_temperature) &&
                        (product_temperature <= maximum_temperature);

    update_statistics(passed);
    return passed;
}
