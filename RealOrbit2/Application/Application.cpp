
#include "Application.h"
#include <iostream>
#include "Application.h"


#include "External/ImGUI/imgui.h"
#include "External/ImGUI/backends/imgui_impl_glfw.h"
#include "External/ImGUI/backends/imgui_impl_opengl3.h"


Application::Application()
{
	Initialize();
}

Application::~Application()
{
	Shutdown();
}


void Application::Initialize()
{
	ApplicationConfig::Init("D:/cpp_codes/40_RealOrbit2/testing/config.txt");
	GlfwInit();
    ImGuiInit();
}

void Application::Run()
{
    float degRed = 0.0f;
    float degBlue = 60.0f;
    float degGreen = 120.0f;
    float degToRad = 3.1415926535 / 180;
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(m_Window) && m_Running)
    {
        /* Set clear colour */
        /* Render here */
        glClearColor(sin(degRed * degToRad), 0.5, 0.5, 0.0f);
        degRed += 0.3f;
        degRed = degRed > 180 ? 0 : degRed;
        // glViewport(200, 0, 1280-200, 600);
        glClear(GL_COLOR_BUFFER_BIT);

        /* Poll for and process events */
        glfwPollEvents();


        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        
        RenderImGUI();
        
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(m_Window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(m_Window);
    }

}

void Application::Shutdown()
{

    // ImGui_ImplOpenGL3_Shutdown();

}



static void glfw_error_callback(int error, const char* description)
{
    std::cout << "GLFW Error %d: %s\n" << error << "\n" << description;
}

void Application::GlfwInit()
{
    // initializing glfw:
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit()) { throw std::runtime_error("GLFW initialization error!"); }

    // GL 3.0 + GLSL 130
    m_GlslVersion = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    // Create window with graphics context
    // m_Window = std::make_unique(glfwCreateWindow(ApplicationConfig::s_WindowWidth, ApplicationConfig::s_WindowHeight, "Dear ImGui GLFW+OpenGL3 example", nullptr, nullptr));
    m_Window = glfwCreateWindow(ApplicationConfig::s_WindowWidth, ApplicationConfig::s_WindowHeight, "Dear ImGui GLFW+OpenGL3 example", nullptr, nullptr);
    if (m_Window == nullptr) { throw std::runtime_error("GLFW window creation failed!"); }

    glfwMakeContextCurrent(m_Window);
    glfwSwapInterval(1); // Enable vsync
}

void Application::ImGuiInit()
{
    ImGui::CreateContext();
    // ImGui::SetCurrentContext();
    ImGui::StyleColorsDark();
    ImGuiIO& io = ImGui::GetIO();
    io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
    io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

    ImGui_ImplGlfw_InitForOpenGL(m_Window, true);
    ImGui_ImplOpenGL3_Init(m_GlslVersion);
}


void Application::RenderImGUI()
{
    ImGuiIO& io = ImGui::GetIO();
    io.DisplaySize = ImVec2(ApplicationConfig::s_WindowWidth, ApplicationConfig::s_WindowHeight);

    static int displayedNumber = 0;

    // ImGui::SetNextWindowPos(ImVec2(0, 0));
    // ImGui::SetNextWindowSize(ImVec2(200, 600));

    // ImGui::Begin("ImGui::Begin()", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
    ImGui::Begin("ImGui::Begin()");
    ImGui::Text("ImGui::Text() %d", displayedNumber);
    ImGui::Button("ImGui::Button()");
    ImGui::SliderInt("SliderInt()", &displayedNumber, -100, 100);

    ImGui::BeginChild("ImGui::BeginChild()");
    for (int n = 0; n < 3; n++)
        ImGui::Text("%04d: Child Text", n);
    ImGui::EndChild();

    ImGui::End();
}




