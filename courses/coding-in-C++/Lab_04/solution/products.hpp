/**
 * @file product.hpp
 * @brief Declares the abstract Product base class.
 */

#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include "reportable.hpp"

#include <string>

/**
 * @brief Maximum number of inspection results that can be stored per product.
 */
const int MAX_INSPECTION_RESULTS = 10;

/**
 * @brief Stores the result of one inspection performed on one product.
 */
struct InspectionResult
{
    std::string inspection_name;
    bool passed;
};

/**
 * @brief Abstract base class for all products in the production plant.
 */
class Product : public Reportable
{
private:
    int product_id;
    std::string name;
    double weight;
    double temperature;
    bool has_visual_defect;

    InspectionResult inspection_results[MAX_INSPECTION_RESULTS];
    int inspection_result_count;

public:
    /**
     * @brief Creates a product with common measurable values.
     *
     * @param[in] id Unique product ID
     * @param[in] product_name Human-readable product name
     * @param[in] product_weight Product weight
     * @param[in] product_temperature Product temperature
     * @param[in] visual_defect True if a visual defect exists
     */
    Product(int id, const std::string &product_name, double product_weight,
            double product_temperature, bool visual_defect);

    /**
     * @brief Returns the unique product ID.
     *
     * @return Product ID
     */
    int get_product_id() const
    {
        return product_id;
    }

    /**
     * @brief Returns the product name.
     *
     * @return Product name
     */
    std::string get_name() const
    {
        return name;
    }

    /**
     * @brief Returns the measured product weight.
     *
     * @return Product weight
     */
    double get_weight() const
    {
        return weight;
    }

    /**
     * @brief Returns the measured product temperature.
     *
     * @return Product temperature
     */
    double get_temperature() const
    {
        return temperature;
    }

    /**
     * @brief Returns whether a visual defect was detected.
     *
     * @return True if a visual defect exists, otherwise false
     */
    bool get_has_visual_defect() const
    {
        return has_visual_defect;
    }

    /**
     * @brief Returns whether the product provides a voltage value.
     *
     * @return True if voltage is available, otherwise false
     */
    virtual bool has_voltage_value() const
    {
        return false;
    }

    /**
     * @brief Returns the measured voltage.
     *
     * Products without voltage support return 0.0.
     *
     * @return Voltage value
     */
    virtual double get_voltage() const
    {
        return 0.0;
    }

    /**
     * @brief Returns the concrete product type.
     *
     * @return Product type as string
     */
    virtual std::string get_product_type() const = 0;

    /**
     * @brief Returns the number of stored inspection results.
     *
     * @return Number of stored inspection results
     */
    int get_inspection_result_count() const;

    /**
     * @brief Returns one stored inspection result.
     *
     * If the index is invalid, an empty failed result is returned.
     *
     * @param[in] index Index of the requested inspection result
     * @return Inspection result at the given index
     */
    InspectionResult get_inspection_result(int index) const;

    /**
     * @brief Removes all previous inspection results.
     */
    void clear_results();

    /**
     * @brief Stores one inspection result.
     *
     * The result is only stored if the internal result array still has space.
     *
     * @param[in] result Inspection result to store
     */
    void add_result(const InspectionResult &result);

    /**
     * @brief Generates a report for the product.
     *
     * @return Product report as string
     */
    std::string generate_report() const override;

    /**
     * @brief Virtual destructor for polymorphic product usage.
     */
    virtual ~Product() {}
};

/**
 * @brief Concrete product representing a combustion engine.
 */
class CombustionEngine : public Product
{
public:
    /**
     * @brief Creates a combustion engine product.
     *
     * @param[in] id Unique product ID
     * @param[in] weight Engine weight
     * @param[in] temperature Engine temperature
     * @param[in] visual_defect True if a visual defect exists
     */
    CombustionEngine(int id, double weight, double temperature, bool visual_defect) : Product(id, "Combustion Motor", weight, temperature, visual_defect) {}

    /**
     * @brief Returns the product type.
     *
     * @return Product type as string
     */
    std::string get_product_type() const override
    {
        return "Combustion Engine";
    }
};

/**
 * @brief Concrete product representing an electric engine.
 */
class ElectricEngine : public Product
{
private:
    double voltage;

public:
    /**
     * @brief Creates an electric engine product.
     *
     * @param[in] id Unique product ID
     * @param[in] weight Engine weight
     * @param[in] temperature Engine temperature
     * @param[in] engine_voltage Engine voltage
     * @param[in] visual_defect True if a visual defect exists
     */
    ElectricEngine(int id, double weight, double temperature,
                   double engine_voltage, bool visual_defect)
        : Product(id, "Electric Motor", weight, temperature, visual_defect),
          voltage(engine_voltage)
    {
    }

    /**
     * @brief Returns whether this product provides a voltage value.
     *
     * @return Always true for electric engines
     */
    bool has_voltage_value() const override
    {
        return true;
    }

    /**
     * @brief Returns the measured voltage.
     *
     * @return Voltage value
     */
    double get_voltage() const override
    {
        return voltage;
    }

    /**
     * @brief Returns the product type.
     *
     * @return Product type as string
     */
    std::string get_product_type() const override
    {
        return "Electric Engine";
    }
};

#endif