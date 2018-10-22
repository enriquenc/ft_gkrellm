#include "RAMModule.hpp"

RAMModule::RAMModule()
{}

RAMModule::~RAMModule()
{}

std::map<std::string, std::string>	RAMModule::getData()
{
	std::map<std::string, std::string> arr;
	
	arr["used"] = getCmdOut("cat .top | grep \"PhysMem\" | cut -d ' ' -f 2");
	arr["unused"] = getCmdOut("cat .top | grep \"PhysMem\" | cut -d ' ' -f 6");
	arr["total"] = std::to_string(std::stoi(arr["used"]) + std::stoi(arr["unused"])) + "M";
	return arr;
}
