/**
 * @file inspection.hpp
 * @brief Declares the abstract Inspection base class.
 */

#ifndef INSPECTIONS_HPP
#define INSPECTIONS_HPP

#include "products.hpp"
#include "reportable.hpp"

#include <string>

/**
 * @brief Abstract base class for all quality inspections.
 *
 * Inspection defines common behavior and stores statistics used for reports.
 */
class Inspection : public Reportable
{
private:
    int performed_count;
    int passed_count;
    bool last_result_available;
    bool last_result;

protected:
    /**
     * @brief Updates inspection statistics after a performed inspection.
     *
     * @param[in] passed True if the inspection passed, otherwise false
     */
    void update_statistics(bool passed);

public:
    /**
     * @brief Creates an inspection with empty statistics.
     */
    Inspection() : performed_count(0),
                   passed_count(0),
                   last_result_available(false),
                   last_result(false) {
                   };

    /**
     * @brief Returns the inspection name.
     *
     * @return Inspection name
     */
    virtual std::string get_name() const = 0;

    /**
     * @brief Checks whether this inspection is applicable to the product.
     *
     * @param[in] product Product to check
     * @return True if applicable, otherwise false
     */
    virtual bool is_applicable(const Product &product) const = 0;

    /**
     * @brief Performs the inspection on a product.
     *
     * @param[in] product Product to inspect
     * @return True if the inspection passed, otherwise false
     */
    virtual bool inspect(const Product &product) = 0;

    /**
     * @brief Calculates the success rate of this inspection type.
     *
     * @return Success rate in percent
     */
    double get_success_rate() const;

    /**
     * @brief Generates an inspection report.
     *
     * @return Inspection report as string
     */
    std::string generate_report() const override;

    /**
     * @brief Virtual default destructor for polymorphic inspection usage.
     */
    virtual ~Inspection() = default;
};

/**
 * @brief Inspection that checks whether product weight is within limits.
 */
class WeightCheck : public Inspection
{
private:
    double minimum_weight;
    double maximum_weight;

public:
    /**
     * @brief Creates a weight check inspection.
     *
     * @param[in] min_weight Minimum allowed weight
     * @param[in] max_weight Maximum allowed weight
     */
    WeightCheck(double min_weight, double max_weight) : minimum_weight(min_weight),
                                                        maximum_weight(max_weight)
    {
    }

    /**
     * @brief Returns the inspection name.
     *
     * @return Inspection name
     */
    std::string get_name() const override
    {
        return "Weight Check";
    }

    /**
     * @brief Checks whether this inspection is applicable.
     *
     * @param[in] product Product to check
     * @return Always true because all products have a weight value
     */
    bool is_applicable(const Product &product) const override;

    /**
     * @brief Performs the weight check.
     *
     * @param[in] product Product to inspect
     * @return True if the product weight is within limits
     */
    bool inspect(const Product &product) override;
};

/**
 * @brief Inspection that checks whether visible defects exist.
 */
class VisualInspection : public Inspection
{
public:
    /**
     * @brief Returns the inspection name.
     *
     * @return Inspection name
     */
    std::string get_name() const override
    {
        return "Visual Inspection";
    }

    /**
     * @brief Checks whether this inspection is applicable.
     *
     * @param[in] product Product to check
     * @return Always true because all products have visual defect information
     */
    bool is_applicable(const Product &product) const override;

    /**
     * @brief Performs the visual inspection.
     *
     * @param[in] product Product to inspect
     * @return True if no visual defect exists
     */
    bool inspect(const Product &product) override;
};

/**
 * @brief Inspection that checks whether product temperature is within limits.
 */
class TemperatureTest : public Inspection
{
private:
    double minimum_temperature;
    double maximum_temperature;

public:
    /**
     * @brief Creates a temperature test inspection.
     *
     * @param[in] min_temperature Minimum allowed temperature
     * @param[in] max_temperature Maximum allowed temperature
     */
    TemperatureTest(double min_temperature, double max_temperature) : minimum_temperature(min_temperature),
                                                                      maximum_temperature(max_temperature)
    {
    }

    /**
     * @brief Returns the inspection name.
     *
     * @return Inspection name
     */
    std::string get_name() const override
    {
        return "Temperature Test";
    }

    /**
     * @brief Checks whether this inspection is applicable.
     *
     * @param[in] product Product to check
     * @return Always true because all products have a temperature value
     */
    bool is_applicable(const Product &product) const override;

    /**
     * @brief Performs the temperature test.
     *
     * @param[in] product Product to inspect
     * @return True if the product temperature is within limits
     */
    bool inspect(const Product &product) override;
};

#endif
