#ifndef ASSISTANCE_SYSTEM_HPP
#define ASSISTANCE_SYSTEM_HPP

#include <iostream>
#include <string>
#include <vector>

#include "bugHunt_vehicle.hpp"

class DistanceSensor
{
private:
    std::string position;
    bool active;

public:
    double measured_distance_m;

    DistanceSensor(const std::string &sensor_position,
                   double initial_distance_m);

    void set_distance(double distance_m);
    void activate();
    void deactivate();

    double get_distance() const;
    bool is_active() const;
    std::string get_position() const;

    bool operator<(const DistanceSensor &other) const;
    bool is_exactly_at_warning_distance(double warning_distance) const;

    void print_info() const;
};

class EmergencyBrakeSystem
{
private:
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
    std::vector<DistanceSensor *> sensors;
    double warning_distance_m;

public:
    ParkingAssistant(double warning_distance);

    void add_sensor(DistanceSensor *sensor);
    void print_warnings() const;
};

#endif