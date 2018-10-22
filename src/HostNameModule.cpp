#include "HostNameModule.hpp"

HostNameModule::HostNameModule()
{}

HostNameModule::~HostNameModule()
{}

std::map<std::string, std::string>	HostNameModule::getData()
{
	std::map<std::string, std::string> arr;
	
	arr["name"] = getCmdOut("hostname");
	arr["user"] = getCmdOut("logname");
	return arr;
}
