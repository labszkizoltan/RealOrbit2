
#ifndef APPLICATION_H
#define APPLICATION_H

#include<unordered_map>
#include <glfw3.h>
#include <memory>

#include "ApplicationConfig.h"

class Application
{
public:
	Application();
	~Application();

	void Initialize();
	void Run();
	void Shutdown();

private:
	void GlfwInit();
	void ImGuiInit();
	void RenderImGUI();

	

public:
	// std::unique_ptr<GLFWwindow> m_Window;
	GLFWwindow* m_Window;
	bool m_Running = true;
	const char* m_GlslVersion;
	
	ApplicationConfig m_Config;

};






#endif // APPLICATION_H
