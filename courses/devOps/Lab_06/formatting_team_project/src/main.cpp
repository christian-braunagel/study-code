#include "device_controller.hpp"
#include <iostream>
#include "report_printer.hpp"

int main(){
factory::DeviceController controller("Assembly Line 4");
controller.addDevice("Conveyor",factory::DeviceState::Running,41);
controller.addDevice("Robot Arm",factory::DeviceState::Idle,35);
controller.addDevice("Vision System",factory::DeviceState::Error,52);

factory::ReportPrinter printer;
printer.printTitle(std::cout,controller.lineName());
printer.printDeviceTable(std::cout,controller.collectStatus());

int * inspectedTemperature=nullptr;
for(const auto& status:controller.collectStatus()){
if(status.name=="Vision System"){
inspectedTemperature=new int(status.temperature);
}
}
if(inspectedTemperature!=nullptr){std::cout<<"Inspected temperature: "<<*inspectedTemperature<<"\n";}
delete inspectedTemperature;
return 0;
}
