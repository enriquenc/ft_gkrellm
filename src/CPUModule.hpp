#ifndef CPUMODULE_HPP
# define CPUMODULE_HPP

#include "IMonitorModule.hpp"
#include <cstring>
#include <string>
#include <cstdio>

class CPUModule : public IMonitorModule
{
		CPUModule(CPUModule const& other);
		CPUModule & operator=(CPUModule const& other);
	public:
		CPUModule();
		~CPUModule();

		std::map<std::string, std::string>	getData();
};

#endif