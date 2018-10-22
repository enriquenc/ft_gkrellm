#include "CPUModule.hpp"

CPUModule::CPUModule()
{}

CPUModule::~CPUModule()
{}

std::map<std::string, std::string>	CPUModule::getData()
{
	std::map<std::string, std::string> arr;

	arr["model"] = getCmdOut("sysctl -a | grep machdep.cpu.brand_string | cut -c 27-");
	arr["cores"] = getCmdOut("sysctl -a | grep machdep.cpu.core_count | cut -d ' ' -f 2");

	arr["user"] = getCmdOut("cat .top | grep CPU | cut -d ' ' -f 3");
	arr["sys"] = getCmdOut("cat .top | grep CPU | cut -d ' ' -f 5");
	arr["idle"] = getCmdOut("cat .top | grep CPU | cut -d ' ' -f 7");
	return arr;
}
