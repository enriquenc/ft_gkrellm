#include "IMonitorModule.hpp"

std::string IMonitorModule::getCmdOut(const char *cmd)
{
	std::string res;
	char	buffer[128];
	FILE	*cmdOut;

	cmdOut = popen(cmd, "r");
	while (!feof(cmdOut))
	{
		if (fgets(buffer, 128, cmdOut))
			res += buffer;
	}
	pclose(cmdOut);
	res.resize(res.size() - 1);
	return res;
}
