#ifndef DISKMODULE_HPP
# define DISKMODULE_HPP

#include "IMonitorModule.hpp"
#include <cstring>
#include <cstdio>

class DiskModule : public IMonitorModule
{
		DiskModule(DiskModule const& other);
		DiskModule & operator=(DiskModule const& other);
	public:
		DiskModule();
		~DiskModule();

		std::map<std::string, std::string> getData();
};

#endif