/**
 * @file quality_control_pipeline.cpp
 * @brief Implements the QualityControlPipeline class.
 */

#include "quality_control_pipeline.hpp"

QualityControlPipeline::QualityControlPipeline()
    : inspection_count(0)
{
}

void QualityControlPipeline::add_inspection(Inspection &inspection)
{
    if (inspection_count < MAX_INSPECTIONS)
    {
        p_inspections[inspection_count] = &inspection;
        inspection_count++;
    }
}

void QualityControlPipeline::inspect_product(Product &product)
{
    product.clear_results();

    for (int index = 0; index < inspection_count; index++)
    {
        Inspection *p_inspection = p_inspections[index];

        if (p_inspection != nullptr) // additional safety check
        {
            if (p_inspection->is_applicable(product))
            {
                bool passed = p_inspection->inspect(product);

                InspectionResult result;
                result.inspection_name = p_inspection->get_name();
                result.passed = passed;

                product.add_result(result);
            }
        }
    }
}