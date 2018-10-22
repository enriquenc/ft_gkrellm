#ifndef OSINFOMODULE_HPP
# define OSINFOMODULE_HPP

#include "IMonitorModule.hpp"
#include <cstring>
#include <cstdio>

class OSInfoModule : public IMonitorModule
{
		OSInfoModule(OSInfoModule const& other);
		OSInfoModule & operator=(OSInfoModule const& other);
	public:
		OSInfoModule();
		~OSInfoModule();

		std::map<std::string, std::string> getData();
};

#endif