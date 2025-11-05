
#ifndef APPLICATION_CONFIG_H
#define APPLICATION_CONFIG_H

#include<unordered_map>
#include <glfw3.h>
#include <memory>


class ApplicationConfig
{
public:
	ApplicationConfig();
	ApplicationConfig(std::string configPath);
	~ApplicationConfig() = default;

	static void Init(std::string configPath);

public:
	static int s_WindowWidth;
	static int s_WindowHeight;
	static int s_LeftPanelWidth;
	static int s_BottomPanelHeight;
	static std::unordered_map<std::string, std::string> s_ConfigLookup;

};






#endif // APPLICATION_CONFIG_H
