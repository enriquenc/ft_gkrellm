#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

#include <iostream>
#include <stdio.h>
#include <map>

class IMonitorModule
{
	public:
		virtual ~IMonitorModule(){}
		virtual std::map<std::string, std::string>	getData() = 0;
		std::string	getCmdOut(const char *cmd);
};

#endif