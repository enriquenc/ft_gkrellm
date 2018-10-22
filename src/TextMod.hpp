#ifndef TEXTMOD_HPP
# define TEXTMOD_HPP

#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"
#include "HostNameModule.hpp"
#include "OSInfoModule.hpp"
#include "DateModule.hpp"
#include "CPUModule.hpp"
#include "RAMModule.hpp"
#include "DiskModule.hpp"
#include "NetworkModule.hpp"

#include <ncurses.h>
#include <iostream>
#include <vector>
#include <map>

# define W_HEIGHT		49
# define W_WIDTH		54
# define W_LINE_WIDTH	(W_WIDTH - 2)
# define TITLE_MARGIN	8
# define BORDER_COLOR	1
# define TITLE_COLOR	2
# define STAR_COLOR		3

class TextMod : public IMonitorDisplay
{
	std::vector<IMonitorModule *>								modules;
	std::map<std::string, std::map<std::string, std::string> >	data;
	std::vector<std::string>									labels;
	WINDOW														*window;

	void	showModuleData(std::map<std::string, std::map<std::string, std::string> >::iterator &module, int &row);
	public:
		TextMod();
		TextMod(TextMod const& other);
		TextMod & operator=(TextMod const& other);
		~TextMod();

		void	parseData();
		void	showData();
		void	start();
};

#endif