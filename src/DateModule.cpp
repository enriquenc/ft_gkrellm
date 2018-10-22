#include "DateModule.hpp"

DateModule::DateModule()
{}

DateModule::~DateModule()
{}

std::map<std::string, std::string> DateModule::getData()
{
	std::map<std::string, std::string> arr;

	arr["time"] = getCmdOut("date | cut -c 12- | cut -c -8");
	return arr;
}
