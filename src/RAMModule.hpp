#ifndef RAMMODULE_HPP
# define RAMMODULE_HPP

#include "IMonitorModule.hpp"
#include <cstring>
#include <cstdio>

class RAMModule : public IMonitorModule
{
		RAMModule(RAMModule const& other);
		RAMModule & operator=(RAMModule const& other);
	public:
		RAMModule();
		~RAMModule();

		std::map<std::string, std::string> getData();
};

#endif