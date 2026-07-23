/**
 * @file main.cpp
 * @brief Demonstrates a polymorphic quality control pipeline.
 * How to compile: g++ production_system_main.cpp quality_control_pipeline.cpp products.cpp inspections.cpp -o production_system
 */

#include "quality_control_pipeline.hpp"
#include "inspections.hpp"

#include <iostream>

/**
 * @brief Program entry point.
 *
 * Creates products and inspections, runs the quality control pipeline,
 * and prints reports for products and inspection types.
 *
 * @return 0 if the program terminates successfully
 */
int main()
{
    const int IDS[] = {1001, 1002, 2001, 2002};
    const double WEIGHTS[] = {420.0, 510.0, 310.0, 280.0};
    const double TEMPERATURES[] = {85.0, 120.0, 410.0, 390.0};
    const double VOLTAGES[] = {410.0, 390.0};

    constexpr double MIN_WEIGHT = 300.0;
    constexpr double MAX_WEIGHT = 500.0;

    constexpr double MIN_TEMPERATURE = 60.0;
    constexpr double MAX_TEMPERATURE = 100.0;

    CombustionEngine combustion_engine_1(IDS[0], WEIGHTS[0], TEMPERATURES[0], false);
    CombustionEngine combustion_engine_2(IDS[1], WEIGHTS[1], TEMPERATURES[1], true);

    ElectricEngine electric_engine_1(IDS[2], WEIGHTS[2], TEMPERATURES[2], VOLTAGES[0], false);
    ElectricEngine electric_engine_2(IDS[3], WEIGHTS[3], TEMPERATURES[3], VOLTAGES[1], false);

    Product *p_products[] = {
        &combustion_engine_1,
        &combustion_engine_2,
        &electric_engine_1,
        &electric_engine_2};

    WeightCheck weight_check(MIN_WEIGHT, MAX_WEIGHT);
    VisualInspection visual_inspection;
    TemperatureTest temperature_test(MIN_TEMPERATURE, MAX_TEMPERATURE);

    QualityControlPipeline pipeline;
    pipeline.add_inspection(weight_check);
    pipeline.add_inspection(visual_inspection);
    pipeline.add_inspection(temperature_test);

    for (Product *p_product : p_products)
    {
        if (p_product != nullptr)
        {
            pipeline.inspect_product(*p_product);
            std::cout << p_product->generate_report() << "\n";
        }
    }

    std::cout << "=== Inspection Reports ===\n";
    std::cout << weight_check.generate_report() << "\n";
    std::cout << visual_inspection.generate_report() << "\n";
    std::cout << temperature_test.generate_report() << "\n";

    return 0;
}
