#ifndef DATEMODULE_HPP
# define DATEMODULE_HPP

#include "IMonitorModule.hpp"
#include <cstring>
#include <cstdio>

class DateModule : public IMonitorModule
{
		DateModule(DateModule const& other);
		DateModule & operator=(DateModule const& other);
	public:
		DateModule();
		~DateModule();

		std::map<std::string, std::string> getData();
};

#endif