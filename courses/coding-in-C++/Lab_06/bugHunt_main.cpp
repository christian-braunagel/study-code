#include <iostream>

#include "bugHunt_vehicle.hpp"
#include "bugHunt_assistance_system.hpp"

int main()
{
    Vehicle ego_vehicle("Vector X1");

    DistanceSensor front_sensor("front", 25.0);
    DistanceSensor rear_sensor("rear", 1.2);
    DistanceSensor left_sensor("left", 0.8);
    DistanceSensor right_sensor("right", 3.0);

    EmergencyBrakeSystem emergency_brake(10.0);
    LaneKeepingAssist lane_assist(0.4, 5.0);
    AdaptiveCruiseControl cruise_control(80.0, 15.0);
    ParkingAssistant parking_assistant(1.5);

    parking_assistant.add_sensor(&rear_sensor);
    parking_assistant.add_sensor(&left_sensor);
    parking_assistant.add_sensor(&right_sensor);

    std::cout << "--- Initial vehicle status ---\n";
    ego_vehicle.print_status();

    std::cout << "--- Accelerating vehicle ---\n";
    ego_vehicle.accelerate(50.0);
    ego_vehicle.print_status();

    std::cout << "--- Adaptive cruise control test ---\n";
    front_sensor.set_distance(12.0);
    cruise_control.evaluate(ego_vehicle, front_sensor);
    ego_vehicle.print_status();

    std::cout << "--- Emergency brake system test ---\n";
    front_sensor.set_distance(25.0);
    emergency_brake.evaluate(ego_vehicle, front_sensor);
    ego_vehicle.print_status();

    std::cout << "--- Lane keeping assist test ---\n";
    ego_vehicle.update_lane_offset(0.7);
    lane_assist.evaluate(ego_vehicle);
    ego_vehicle.print_status();

    std::cout << "--- Parking assistant test ---\n";
    parking_assistant.print_warnings();

    std::cout << "--- Manual braking test ---\n";
    ego_vehicle.brake(100.0);
    ego_vehicle.print_status();

    return 0;
}