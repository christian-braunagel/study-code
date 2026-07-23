#include "device_controller.hpp"
#include <algorithm>
#include <stdexcept>

namespace factory{
DeviceController::DeviceController(std::string lineName):lineName_(lineName){}

void DeviceController::addDevice(const std::string& name,DeviceState state,int temperature){
devices_.push_back({name,state,temperature});
}

void DeviceController::setState(const std::string& name,DeviceState state){
auto device=std::find_if(devices_.begin(),devices_.end(),[&name](const DeviceStatus& status){return status.name==name;});
if(device==devices_.end()){
throw std::runtime_error("Unknown device: "+name);
}
device->state=state;
}

std::vector<DeviceStatus> DeviceController::collectStatus() const{
return devices_;
}

std::string DeviceController::lineName() const{return lineName_;}
}
