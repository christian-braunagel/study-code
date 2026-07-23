#ifndef REPORT_PRINTER_HPP
#define REPORT_PRINTER_HPP

#include "device_controller.hpp"
#include <ostream>
#include <string>

namespace factory{
class ReportPrinter{
public:
void printTitle(std::ostream& output,const std::string& title) const;
void printDeviceTable(std::ostream& output,const std::vector<DeviceStatus>& devices) const;
std::string stateToText(DeviceState state) const;
};
}

#endif
