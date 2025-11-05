
#include "ApplicationConfig.h"
#include "Utils/StringUtils.h"
#include <fstream>
#include <string>




int ApplicationConfig::s_WindowWidth = 1200;
int ApplicationConfig::s_WindowHeight = 800;
int ApplicationConfig::s_LeftPanelWidth = 200;
int ApplicationConfig::s_BottomPanelHeight = 200;
std::unordered_map<std::string, std::string> ApplicationConfig::s_ConfigLookup;

ApplicationConfig::ApplicationConfig()
{
	// s_WindowWidth = 1200;
	// s_WindowHeight = 800;
	// s_LeftPanelWidth = 200;
	// s_BottomPanelHeight = 200;
}

ApplicationConfig::ApplicationConfig(std::string configPath)
{
	Init(configPath);
}



void ApplicationConfig::Init(std::string configPath)
{
	std::ifstream file(configPath);
	std::string line;

	while (std::getline(file, line))
	{
		auto splitted = Utils::SplitString(line, "\t");
		if (splitted.size() > 1) { s_ConfigLookup[splitted[0]] = splitted[1]; }
	}
	file.close();

	s_WindowWidth = (int)std::stod(s_ConfigLookup["WindowWidth"]);
	s_WindowHeight = (int)std::stod(s_ConfigLookup["WindowHeight"]);
	s_LeftPanelWidth = (int)std::stod(s_ConfigLookup["LeftPanelWidth"]);
	s_BottomPanelHeight = (int)std::stod(s_ConfigLookup["BottomPanelHeight"]);

}



