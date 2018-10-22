#ifndef NETWORKMODULE_HPP
# define NETWORKMODULE_HPP

#include "IMonitorModule.hpp"
#include <cstring>
#include <cstdio>

class NetworkModule : public IMonitorModule
{
		NetworkModule(NetworkModule const& other);
		NetworkModule & operator=(NetworkModule const& other);
	public:
		NetworkModule();
		~NetworkModule();

		std::map<std::string, std::string> getData();
};

#endif