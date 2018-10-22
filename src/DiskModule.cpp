#include "DiskModule.hpp"

DiskModule::DiskModule()
{}

DiskModule::~DiskModule()
{}

std::map<std::string, std::string>	DiskModule::getData()
{
	std::map<std::string, std::string> arr;

	arr["data read"] = getCmdOut("cat .top | grep Disks | cut -d ' ' -f 2 | cut -d '/' -f 2");
	arr["data written"] = getCmdOut("cat .top | grep Disks | cut -d ' ' -f 4 | cut -d '/' -f 2");
	arr["reads in"] = getCmdOut("cat .top | grep Disks | cut -d ' ' -f 2 | cut -d '/' -f 1");
	arr["writes out"] = getCmdOut("cat .top | grep Disks | cut -d ' ' -f 4 | cut -d '/' -f 1");
	return arr;
}
