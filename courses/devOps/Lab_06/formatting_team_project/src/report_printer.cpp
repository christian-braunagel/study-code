#include "report_printer.hpp"
#include <iomanip>

namespace factory{
void ReportPrinter::printTitle(std::ostream& output,const std::string& title) const{
output<<"\n"<<title<<"\n";
output<<"====================\n";
}

void ReportPrinter::printDeviceTable(std::ostream& output,const std::vector<DeviceStatus>& devices) const{
for(const DeviceStatus& device:devices){
output<<std::left<<std::setw(18)<<device.name<<std::setw(10)<<stateToText(device.state)<<"temperature: "<<device.temperature<<" C\n";
}
}

std::string ReportPrinter::stateToText(DeviceState state) const{
switch(state){
case DeviceState::Offline:return "offline";
case DeviceState::Idle:return "idle";
case DeviceState::Running:return "running";
case DeviceState::Error:return "error";
}
return "unknown";
}
}
