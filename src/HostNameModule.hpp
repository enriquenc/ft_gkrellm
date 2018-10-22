#ifndef HOSTNAMEMODULE_HPP
# define HOSTNAMEMODULE_HPP

#include "IMonitorModule.hpp"
#include <cstring>
#include <cstdio>

class HostNameModule : public IMonitorModule
{
		HostNameModule(HostNameModule const& other);
		HostNameModule & operator=(HostNameModule const& other);
	public:
		HostNameModule();
		~HostNameModule();

		std::map<std::string, std::string>	getData();
};

#endif