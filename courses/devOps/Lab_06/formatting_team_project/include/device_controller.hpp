#ifndef DEVICE_CONTROLLER_HPP
#define DEVICE_CONTROLLER_HPP

#include <string>
#include <vector>

namespace factory{
enum class DeviceState{Offline,Idle,Running,Error};

struct DeviceStatus{std::string name;DeviceState state;int temperature;};

class DeviceController{
public:
DeviceController(std::string lineName);
void addDevice(const std::string& name,DeviceState state,int temperature);
void setState(const std::string& name,DeviceState state);
std::vector<DeviceStatus> collectStatus() const;
std::string lineName() const;
private:
std::string lineName_;
std::vector<DeviceStatus> devices_;
};
}

#endif
