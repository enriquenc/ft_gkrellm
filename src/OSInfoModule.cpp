#include "OSInfoModule.hpp"

OSInfoModule::OSInfoModule()
{}

OSInfoModule::~OSInfoModule()
{}

std::map<std::string, std::string>	OSInfoModule::getData()
{
	std::map<std::string, std::string> arr;
	
	arr["version"] = getCmdOut("system_profiler SPSoftwareDataType | grep \"System Version\" | cut -c 23- | cut -c -13");
	return arr;
}
