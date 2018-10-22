#ifndef GRAPHICMOD_HPP
# define GRAPHICMOD_HPP

#include "IMonitorDisplay.hpp"
#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"
#include "HostNameModule.hpp"
#include "OSInfoModule.hpp"
#include "DateModule.hpp"
#include "CPUModule.hpp"
#include "RAMModule.hpp"
#include "DiskModule.hpp"
#include "NetworkModule.hpp"

#include <iostream>
#include <SDL.h>
#include "SDL_image.h"
#include <iostream>
#include <vector>
#include <map>

# include "SDL_mixer.h"
# include "SDL_ttf.h"


class GraphicMod : public IMonitorDisplay
{
private:
	std::vector<IMonitorModule *>								modules;
	std::map<std::string, std::map<std::string, std::string> >	data;
	std::vector<std::string>									labels;

	SDL_Window *window;
    SDL_Surface *screen;
    SDL_Surface *background;

	SDL_Surface *anim[17];
	SDL_Surface *cat[11];

	SDL_Surface *date;

	TTF_Font *ttf;

	GraphicMod(GraphicMod const& other);
	GraphicMod & operator=(GraphicMod const& other);
public:
	GraphicMod();
	
	~GraphicMod();

	void	parseData();
	void	showData();
	void 	start(void);  
	void 	renderString(float x, float y, const char *string);
	void	print_face();
	void	print_cat();
};

#endif
