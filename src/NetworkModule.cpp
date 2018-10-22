#include "NetworkModule.hpp"

NetworkModule::NetworkModule()
{}

NetworkModule::~NetworkModule()
{}

std::map<std::string, std::string>	NetworkModule::getData()
{
	std::map<std::string, std::string> arr;

	arr["packets in"] = getCmdOut("cat .top | grep Networks | cut -d ' ' -f 3 | cut -d '/' -f 1");
	arr["packets out"] = getCmdOut("cat .top | grep Networks | cut -d ' ' -f 5 | cut -d '/' -f 1");
	arr["data received"] = getCmdOut("cat .top | grep Networks | cut -d ' ' -f 3 | cut -d '/' -f 2");
	arr["data sent"] = getCmdOut("cat .top | grep Networks | cut -d ' ' -f 5 | cut -d '/' -f 2");
	return arr;
}
