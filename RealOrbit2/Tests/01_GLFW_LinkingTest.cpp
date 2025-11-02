
#include <iostream>
#include <cmath>

#include "rendering/MeshLibrary.h"

#include <glfw3.h>

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    float degRed = 0.0f;
    float degBlue = 60.0f;
    float degGreen = 120.0f;
    float degToRad = 3.1415926535 / 180;
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Set clear colour */
        glClearColor(sin(degRed * degToRad), sin(degGreen * degToRad), sin(degBlue * degToRad), 0.0f);
        degRed += 0.3;
        degRed = degRed > 180 ? 0 : degRed;
        degBlue += 0.7;
        degBlue = degBlue > 180 ? 0 : degBlue;
        degGreen += 1;
        degGreen = degGreen > 180 ? 0 : degGreen;

        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}




// int main()
// {
//     MeshLibrary ml;
// 
//     int a = ml.m_NameHandleLookup["FirstKey"] + ml.m_NameHandleLookup["SecondKey"];
//     int b = ml.m_NameHandleLookup["FirstKey"] + ml.m_NameHandleLookup["asd"];
// 
//     std::cout << ml.m_NameHandleLookup["FirstKey"] << "\n";
//     std::cout << ml.m_NameHandleLookup["SecondKey"] << "\n";
//     std::cout << ml.m_NameHandleLookup["ThirdKey"] << "\n";
//     std::cout << ml.m_NameHandleLookup["asd"] << "\n";
//     std::cout << ml.m_NameHandleLookup["eqw"] << "\n";
// 
//     ml.m_NameHandleLookup["SecondKey"] = 20;
//     std::cout << ml.m_NameHandleLookup["SecondKey"] << "\n";
// 
//     std::cout << "Hello World!\n";
// }
