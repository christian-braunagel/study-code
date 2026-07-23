/**
 * @file quality_control_pipeline.hpp
 * @brief Declares the QualityControlPipeline class.
 */

#ifndef QUALITY_CONTROL_PIPELINE_HPP
#define QUALITY_CONTROL_PIPELINE_HPP

#include "inspections.hpp"
#include "products.hpp"

/**
 * @brief Maximum number of inspections that can be stored in the pipeline.
 */
constexpr int MAX_INSPECTIONS = 10;

/**
 * @brief Executes a configurable sequence of inspections on products.
 */
class QualityControlPipeline
{
private:
    Inspection *p_inspections[MAX_INSPECTIONS];
    int inspection_count;

public:
    /**
     * @brief Creates an empty inspection pipeline.
     */
    QualityControlPipeline();

    /**
     * @brief Adds an inspection to the pipeline.
     *
     * The pipeline does not own the inspection object.
     * The inspection is only added if there is still space available.
     *
     * @param[in] inspection Inspection to add
     */
    void add_inspection(Inspection &inspection);

    /**
     * @brief Performs all applicable inspections on a product.
     *
     * Existing product results are cleared before the inspections are run.
     *
     * @param[in,out] product Product to inspect
     */
    void inspect_product(Product &product);
};

#endif