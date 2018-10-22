#include "TextMod.hpp"

TextMod::TextMod()
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

	initscr();
	noecho();
	curs_set(0);
	start_color();
	init_color(COLOR_MAGENTA, 408, 408, 400);
	init_color(COLOR_WHITE, 1000, 1000, 1000);
	init_pair(1, COLOR_MAGENTA, COLOR_MAGENTA);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
}

TextMod::TextMod(TextMod const& other)
{
	*this = other;
}

TextMod & TextMod::operator=(TextMod const& other)
{
	this->modules = other.modules;
	this->data = other.data;
	this->labels = other.labels;
	return *this;
}

TextMod::~TextMod()
{
	endwin();
	std::vector<IMonitorModule*>::iterator cur = modules.begin();
	std::vector<IMonitorModule*>::iterator next;

	while (cur != modules.end())
	{
		next = (cur + 1);
		delete *cur;
		cur = next;
	}
}

void	TextMod::parseData()
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

void	TextMod::showModuleData(std::map<std::string, std::map<std::string, std::string> >::iterator &module, int &row)
{
	std::map<std::string, std::string>::iterator dataBegin = module->second.begin();
	std::map<std::string, std::string>::iterator dataEnd = module->second.end();

	wattron(window, COLOR_PAIR(TITLE_COLOR));
	mvwprintw(window, row, TITLE_MARGIN, "%s Module", module->first.c_str());
	wattroff(window, COLOR_PAIR(TITLE_COLOR));
	row++;

	wattron(window, COLOR_PAIR(STAR_COLOR));
	mvwhline(window, row, 1, '*', W_LINE_WIDTH);
	wattroff(window, COLOR_PAIR(STAR_COLOR));
	row++;

	while (dataBegin != dataEnd)
	{
		mvwprintw(window, row, 2, "%s -> %s", dataBegin->first.c_str(), dataBegin->second.c_str());
		row++;
		dataBegin++;
	}
}

void	TextMod::showData()
{
	std::map<std::string, std::map<std::string, std::string> >::iterator Dbegin = data.begin();
	int row = 0;

	window = newwin(W_HEIGHT, W_WIDTH, 0, 0);
	wattron(window, COLOR_PAIR(BORDER_COLOR));
	box(window, 0, 0);
	wattroff(window, COLOR_PAIR(BORDER_COLOR));
	refresh();

	while (Dbegin != data.end())
	{
		wattron(window, COLOR_PAIR(BORDER_COLOR));
		mvwhline(window, row, 1, ' ', W_LINE_WIDTH);
		wattroff(window, COLOR_PAIR(BORDER_COLOR));
		row++;
		showModuleData(Dbegin, row);
		row++;
		Dbegin++;
	}

	wrefresh(window);
	delwin(window);
}

void	TextMod::start()
{
	try {
		while (1)
		{
			parseData();
			showData();
		}
	} catch(...)
	{}
}
