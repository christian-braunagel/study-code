#ifndef ASSISTANCE_SYSTEM_HPP
#define ASSISTANCE_SYSTEM_HPP

#include <cmath>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "vehicle.hpp"

class DistanceSensor
{
private:
    std::string position;
    double measured_distance_m;
    bool active;

public:
    DistanceSensor(const std::string &sensor_position,
                   double initial_distance_m);

    void set_distance(double distance_m);
    void activate();
    void deactivate();

    double get_distance() const;
    bool is_active() const;
    std::string get_position() const;

    bool operator<(const DistanceSensor &other) const;
    bool is_at_warning_distance(double warning_distance) const;

    void print_info() const;
};

class EmergencyBrakeSystem
{
private:
    static constexpr double EMERGENCY_BRAKE_FORCE_KMH = 30.0;

    double critical_distance_m;

public:
    EmergencyBrakeSystem(double critical_distance);

    void evaluate(Vehicle &vehicle, const DistanceSensor &front_sensor) const;
};

class LaneKeepingAssist
{
private:
    double max_allowed_offset_m;
    double correction_angle;

public:
    LaneKeepingAssist(double max_offset, double correction);

    void evaluate(Vehicle &vehicle) const;
};

class AdaptiveCruiseControl
{
private:
    static constexpr double SPEED_STEP_KMH = 5.0;

    double target_speed_kmh;
    double minimum_distance_m;

public:
    AdaptiveCruiseControl(double target_speed,
                          double minimum_distance);

    void evaluate(Vehicle &vehicle,
                  const DistanceSensor &front_sensor) const;
};

class ParkingAssistant
{
private:
    std::vector<std::shared_ptr<DistanceSensor>> sensors;
    double warning_distance_m;

public:
    ParkingAssistant(double warning_distance);

    void add_sensor(std::shared_ptr<DistanceSensor> sensor);
    void print_warnings() const;
};

#endif