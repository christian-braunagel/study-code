// How to compile: g++ -std=c++17 main.cpp vehicle.cpp assistance_system.cpp -o assistance_system

#include <iostream>
#include <memory>
#include <vector>

#include "vehicle.hpp"
#include "extended_assistance_system.hpp"

int main()
{
    const std::string VEHICLE_MODEL = "Vector X1";

    const std::string FRONT_SENSOR_POSITION = "front";
    const std::string REAR_SENSOR_POSITION = "rear";
    const std::string LEFT_SENSOR_POSITION = "left";
    const std::string RIGHT_SENSOR_POSITION = "right";

    constexpr double FRONT_SENSOR_INITIAL_DISTANCE_M = 25.0;
    constexpr double REAR_SENSOR_INITIAL_DISTANCE_M = 1.2;
    constexpr double LEFT_SENSOR_INITIAL_DISTANCE_M = 0.8;
    constexpr double RIGHT_SENSOR_INITIAL_DISTANCE_M = 3.0;

    constexpr double PARKING_WARNING_DISTANCE_M = 1.5;

    constexpr double EMERGENCY_BRAKE_CRITICAL_DISTANCE_M = 10.0;
    constexpr double CRUISE_CONTROL_TARGET_SPEED_KMH = 80.0;
    constexpr double CRUISE_CONTROL_MINIMUM_DISTANCE_M = 15.0;

    constexpr double LANE_KEEPING_MAX_OFFSET_M = 0.4;
    constexpr double LANE_KEEPING_CORRECTION_ANGLE_DEG = 5.0;

    constexpr double INITIAL_ACCELERATION_KMH = 50.0;
    constexpr double CLOSE_FRONT_VEHICLE_DISTANCE_M = 12.0;
    constexpr double CRITICAL_FRONT_VEHICLE_DISTANCE_M = 5.0;
    constexpr double TEST_LANE_OFFSET_M = 0.7;
    constexpr double MANUAL_BRAKING_AMOUNT_KMH = 100.0;

    Vehicle ego_vehicle(VEHICLE_MODEL);

    auto front_sensor = std::make_shared<DistanceSensor>(
        FRONT_SENSOR_POSITION,
        FRONT_SENSOR_INITIAL_DISTANCE_M);

    auto rear_sensor = std::make_shared<DistanceSensor>(
        REAR_SENSOR_POSITION,
        REAR_SENSOR_INITIAL_DISTANCE_M);

    auto left_sensor = std::make_shared<DistanceSensor>(
        LEFT_SENSOR_POSITION,
        LEFT_SENSOR_INITIAL_DISTANCE_M);

    auto right_sensor = std::make_shared<DistanceSensor>(
        RIGHT_SENSOR_POSITION,
        RIGHT_SENSOR_INITIAL_DISTANCE_M);

    ParkingAssistant parking_assistant(PARKING_WARNING_DISTANCE_M);

    parking_assistant.add_sensor(rear_sensor);
    parking_assistant.add_sensor(left_sensor);
    parking_assistant.add_sensor(right_sensor);

    std::vector<std::unique_ptr<AssistanceFeature>> assistance_features;

    assistance_features.push_back(
        std::make_unique<EmergencyBrakeSystem>(
            EMERGENCY_BRAKE_CRITICAL_DISTANCE_M,
            front_sensor));

    assistance_features.push_back(
        std::make_unique<AdaptiveCruiseControl>(
            CRUISE_CONTROL_TARGET_SPEED_KMH,
            CRUISE_CONTROL_MINIMUM_DISTANCE_M,
            front_sensor));

    assistance_features.push_back(
        std::make_unique<LaneKeepingAssist>(
            LANE_KEEPING_MAX_OFFSET_M,
            LANE_KEEPING_CORRECTION_ANGLE_DEG));

    std::cout << "Front sensor use_count: "
              << front_sensor.use_count()
              << '\n';

    std::cout << "Rear sensor use_count: "
              << rear_sensor.use_count()
              << "\n\n";

    std::cout << "--- Initial vehicle status ---\n";
    ego_vehicle.print_status();

    std::cout << "--- Accelerating vehicle ---\n";
    ego_vehicle.accelerate(INITIAL_ACCELERATION_KMH);
    ego_vehicle.print_status();

    std::cout << "--- Assistance feature test: close front vehicle ---\n";
    front_sensor->set_distance(CLOSE_FRONT_VEHICLE_DISTANCE_M);
    ego_vehicle.update_lane_offset(TEST_LANE_OFFSET_M);

    for (const auto &feature : assistance_features)
    {
        feature->print_name();
        feature->evaluate(ego_vehicle);
    }

    ego_vehicle.print_status();

    std::cout << "--- Emergency brake test: critical distance ---\n";
    front_sensor->set_distance(CRITICAL_FRONT_VEHICLE_DISTANCE_M);

    for (const auto &feature : assistance_features)
    {
        feature->print_name();
        feature->evaluate(ego_vehicle);
    }

    ego_vehicle.print_status();

    std::cout << "--- Parking assistant test ---\n";
    parking_assistant.print_warnings();

    std::cout << "--- Manual braking test ---\n";
    ego_vehicle.brake(MANUAL_BRAKING_AMOUNT_KMH);
    ego_vehicle.print_status();

    return 0;
}