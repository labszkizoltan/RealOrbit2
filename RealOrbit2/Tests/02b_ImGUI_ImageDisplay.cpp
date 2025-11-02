

/*

Image display example:
https://github.com/ocornut/imgui/wiki/Image-Loading-and-Displaying-Examples#example-for-opengl-users

Another earlier example I used:
D:\cpp_codes\37_RealOrbit\Real_Orbit\Source\Game_v1\Layers\01b_ImGuiTestMenuLayer.cpp

*/


#include <glfw3.h>
#include <iostream>

#include "External/ImGUI/imgui.h"
#include "External/ImGUI/backends/imgui_impl_glfw.h"
#include "External/ImGUI/backends/imgui_impl_opengl3.h"

static void glfw_error_callback(int error, const char* description)
{
    std::cout << "GLFW Error %d: %s\n" << error << "\n" << description;
}

void RenderImGUI(GLFWwindow* window, int mainWindowWidth, int mainWindowHeight)
{
    ImGuiIO& io = ImGui::GetIO();
    io.DisplaySize = ImVec2(mainWindowWidth, mainWindowHeight);

    // ImGui_ImplOpenGL3_NewFrame();
    // ImGui_ImplGlfw_NewFrame();
    // ImGui::NewFrame();

    static int displayedNumber = 0;

    // ImGui::SetNextWindowPos(ImVec2(100, 200));
    // ImGui::SetNextWindowSize(ImVec2(500, 500));

    ImGui::Begin("ImGui::Begin()");
    ImGui::Text("ImGui::Text() %d", displayedNumber);
    ImGui::Button("ImGui::Button()");
    ImGui::SliderInt("SliderInt()", &displayedNumber, -100, 100);

    ImGui::BeginChild("ImGui::BeginChild()");
    for (int n = 0; n < 3; n++)
        ImGui::Text("%04d: Child Text", n);
    ImGui::EndChild();

    ImGui::End();

    // ImGui::Render();
    // int display_w, display_h;
    // glfwGetFramebufferSize(window, &display_w, &display_h);
    // glViewport(0, 0, display_w, display_h);
    // glClear(GL_COLOR_BUFFER_BIT);
    // ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void RenderImGUI_2(GLFWwindow* window)
{
    ImGuiIO& io = ImGui::GetIO();
    io.DisplaySize = ImVec2(1280, 800);

    // ImGui_ImplOpenGL3_NewFrame();
    // ImGui_ImplGlfw_NewFrame();
    // ImGui::NewFrame();

    static int counter = 0;
    ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.
    ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
    if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
        counter++;
    ImGui::SameLine();
    ImGui::Text("counter = %d", counter);
    ImGui::End();

    // ImGui::Render();
    // int display_w, display_h;
    // glfwGetFramebufferSize(window, &display_w, &display_h);
    // glViewport(0, 0, display_w, display_h);
    // glClear(GL_COLOR_BUFFER_BIT);
    // ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

int main()
{
    // initializing glfw:
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit()) { return 1; }

    // GL 3.0 + GLSL 130
    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    
    // Create window with graphics context
    float main_scale = ImGui_ImplGlfw_GetContentScaleForMonitor(glfwGetPrimaryMonitor()); // Valid on GLFW 3.3+ only
    GLFWwindow* window = glfwCreateWindow((int)(1280 * main_scale), (int)(800 * main_scale), "Dear ImGui GLFW+OpenGL3 example", nullptr, nullptr);
    if (window == nullptr)
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    std::cout << "checkpoint 1\n";
    ImGui::CreateContext();
    // ImGui::SetCurrentContext();
    ImGui::StyleColorsDark();
    ImGuiIO& io = ImGui::GetIO();
    io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
    io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);


    float degRed = 0.0f;
    float degBlue = 60.0f;
    float degGreen = 120.0f;
    float degToRad = 3.1415926535 / 180;
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Set clear colour */
        /* Render here */
        glClearColor(sin(degRed * degToRad), 0.5, 0.5, 0.0f);
        degRed += 0.3;
        degRed = degRed > 180 ? 0 : degRed;
        glClear(GL_COLOR_BUFFER_BIT);
    
        /* Swap front and back buffers */
        // glfwSwapBuffers(window);
    
        /* Poll for and process events */
        glfwPollEvents();


        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        RenderImGUI(window, (int)(1280 * main_scale), (int)(800 * main_scale));
        RenderImGUI_2(window);

        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }


    ImGui_ImplOpenGL3_Shutdown();

    return 0;
}




