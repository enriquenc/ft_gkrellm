#include "IMonitorDisplay.hpp"
#include "GraphicMod.hpp"
#include "TextMod.hpp"
#include "HostNameModule.hpp"

int main(int ac, char *av[])
{
	if (ac == 2 && std::strcmp(av[1], "SDL") == 0)
	{
		GraphicMod sdl;
		sdl.start();
	}
	else if (ac == 2 && std::strcmp(av[1], "NCURSES") == 0)
	{
		TextMod ncurses;
		ncurses.start();
	}
	else
		std::cout << "Usage: ./ft_gkrellm [SDL | NCURSES]" << std::endl;
	return 0;
}
