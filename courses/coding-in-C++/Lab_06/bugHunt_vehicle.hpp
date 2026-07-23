#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Vehicle
{
private:
    std::string model;
    double speed_kmh;
    double steering_angle;
    double lane_offset_m;
    bool brake_light_on;

public:
    Vehicle(const std::string &vehicle_model);

    void accelerate(double amount_kmh);
    void brake(double amount_kmh);
    void steer(double angle);
    void update_lane_offset(double offset);

    double get_speed() const;
    double get_steering_angle() const;
    double get_lane_offset() const;

    std::string &get_model();

    bool is_brake_light_on() const;

    void print_status() const;
};

#endif