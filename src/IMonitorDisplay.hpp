#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

#include <string>

class IMonitorDisplay
{
	public:
		virtual ~IMonitorDisplay(){}
		virtual void	parseData() = 0;
		virtual void	showData() = 0;
		virtual void	start() = 0;
};

#endif