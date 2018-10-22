#include "GraphicMod.hpp"


GraphicMod::GraphicMod()
{
	labels.push_back("Host");
	labels.push_back("OS");
	labels.push_back("Date");
	labels.push_back("CPU");
	labels.push_back("RAM");
	labels.push_back("Disk");
	labels.push_back("Network");

	modules.push_back(new HostNameModule());
	modules.push_back(new OSInfoModule());
	modules.push_back(new DateModule());
	modules.push_back(new CPUModule());
	modules.push_back(new RAMModule());
	modules.push_back(new DiskModule());
	modules.push_back(new NetworkModule());

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << IMG_GetError() << std::endl;
		exit(-1);
	}
    window = SDL_CreateWindow("Rush_01", 300, 400, 1280, 700, SDL_WINDOW_ALLOW_HIGHDPI);
    screen = SDL_GetWindowSurface(window);
	if (!window || !screen)
	{
		std::cout << IMG_GetError() << std::endl;
		exit(-1);
	}
    if (!(background = IMG_Load("./img/back.jpg")))
	{
		std::cout << IMG_GetError() << std::endl;
		exit(-1);
	}
	std::string p = "./img/anim/";
	std::string c = "./img/cat/";

	for(int i = 0; i < 11; i++)
	{
		if (!(cat[i] = IMG_Load((c + std::to_string(i) + ".tiff").c_str())))
		{
			std::cout << IMG_GetError() << std::endl;
			exit(-1);
		}
	}
	for(int i = 1; i <= 17; i++)
	{
		if (!(anim[i - 1] = IMG_Load((p + std::to_string(i) + ".tiff").c_str())))
		{
			std::cout << IMG_GetError() << std::endl;
			exit(-1);
		}
	}
	if(TTF_Init() < 0)
	{
		std::cout << IMG_GetError() << std::endl;
		exit(-1);
	}
	if(!(ttf = TTF_OpenFont("fonts/RobotoCondensed-Light.ttf", 20)))
	{
		std::cout << IMG_GetError() << std::endl;
		exit(-1);
	}
	
}

void GraphicMod::renderString(float x, float y, const char *to_print)
{
	SDL_Surface *text;

	text = TTF_RenderText_Solid(ttf, to_print, (SDL_Color){255, 255, 255, 255});
	SDL_Rect pos;
	pos = (SDL_Rect){x, y, 0, 0};
	SDL_BlitSurface(text, NULL, screen, &pos);
	SDL_FreeSurface(text);
}


GraphicMod::~GraphicMod()
{
	TTF_CloseFont(ttf);
	TTF_Quit();
	
    
	for (int i = 0; i < 17; i++)
		delete anim[i];
	for (int i = 0; i < 11; i++)
		delete cat[i];
	delete background;
	SDL_DestroyWindow(window);
	SDL_Quit();
	// modules can leak
}

void	GraphicMod::parseData()
{
	system("top | head -n 10 > .top");

	std::vector<IMonitorModule *>::iterator Mbegin = modules.begin();
	std::vector<std::string>::iterator Lbegin = labels.begin();

	while (Mbegin != modules.end())
	{
		data[*Lbegin] = (*Mbegin)->getData();
		Mbegin++;
		Lbegin++;
	}
}

void	GraphicMod::showData()
{}

void GraphicMod::print_cat()
{
	static int i = 0;
	
	SDL_Rect pic = {0, 400, anim[i]->w / 5, anim[i]->h / 5};	
    SDL_BlitScaled(cat[i], NULL, screen, &pic);
	i++;
	if (i == 11)
		i = 0;
}

void GraphicMod::print_face()
{
	static int i = 0;
	
	SDL_Rect pic = {1000, 10, anim[i]->w / 4, anim[i]->h / 4};	
    SDL_BlitScaled(anim[i], NULL, screen, &pic);
	i++;
	if (i == 17)
		i = 0;
}

void GraphicMod::start(void)
{
	SDL_Event e;
	try{
		while (1)
		{
			
			while(SDL_PollEvent(&e))
			{
				if (e.window.event == SDL_WINDOWEVENT_CLOSE || (e.type == SDL_KEYDOWN &&
					e.key.keysym.scancode == SDL_SCANCODE_ESCAPE))
					return ;
			}
			parseData();
			SDL_Rect pic = {0, 0, background->w / 2, background->h / 2};	
			SDL_BlitScaled(background, NULL, screen, &pic);
			print_face();
			print_cat();
			print_cat();
			print_cat();
			renderString(1200, 5, data["Date"]["time"].c_str());
			renderString(950, 5, data["Host"]["name"].c_str());
			renderString(1100, 5, data["Host"]["user"].c_str());
			renderString(10, 0, data["OS"]["version"].c_str());
			renderString(10, 20, data["CPU"]["model"].c_str());
			renderString(10, 42,("Cores: " + data["CPU"]["cores"]).c_str());
			renderString(10, 66, "CPU     STATUS:");
			renderString(10, 88, ("CPU user: " + data["CPU"]["user"]).c_str());
			renderString(10, 110, ("CPU system: " + data["CPU"]["sys"]).c_str());
			renderString(10, 132, ("CPU idle: " + data["CPU"]["idle"]).c_str());
			renderString(10, 154, ("RAM used: " + data["RAM"]["used"]).c_str());
			renderString(10, 176,("RAN unused: " + data["RAM"]["unused"]).c_str());
			renderString(10, 198, ("RAM total: " + data["RAM"]["total"]).c_str());
			renderString(10, 220, ("Disk data read: " + data["Disk"]["data read"]).c_str());
			renderString(10, 242, ("Disk data written: " + data["Disk"]["data written"]).c_str());
			renderString(10, 264, ("Disk reads in: " + data["Disk"]["reads in"]).c_str());
			renderString(10, 286, ("Disk writes out: " + data["Disk"]["writes out"]).c_str());
			renderString(10, 308, ("Network packets in: " + data["Network"]["packets in"]).c_str());
			renderString(10, 330, ("Network packets out: " + data["Network"]["packets out"]).c_str());
			renderString(10, 352, ("Network data received: " + data["Network"]["data received"]).c_str());
			renderString(10, 374, ("Network data sent: " + data["Network"]["data sent"]).c_str());
			
			SDL_UpdateWindowSurface(window);
		}
	}
	catch(std::exception & e){}
}
