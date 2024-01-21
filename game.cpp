#include "game.h"
#include "renderer/camera.h"
#include "renderer/renderer.h"
#include <iostream>

Game::Game()
{

}


void Game::startGame() {
    //setup window
    setupWindow();
    //init parser, scene gen, cam, renderer
    Camera cam;
    Renderer renderer(&cam,nullptr);
    //set render ratio
    //declare last look vars
    if(m_running) {
        //input
        //render start draw
        //draw static and dynamic obs
        //draw screen
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }
    glfwTerminate();
}

void Game::setupWindow() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return;
    }

    // Set GLFW to use OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a GLFW windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(DSCREEN_WIDTH, DSCREEN_HEIGHT, "Quake Clone", nullptr, nullptr);
    m_window = window;

    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        const char* description;
        glfwGetError(&description);

        std::cout << description << std::endl;

        glfwTerminate();
        return;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);
    //    gladLoadGL(glfwGetProcAddress);
    glfwSwapInterval(1);

    //    float xscale, yscale;
    int realWidth,realHeight;
    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    glfwGetWindowContentScale(window, &m_monitorXScale,&m_monitorYScale);
    std::cout <<" window is" << realWidth <<","<<realHeight << std::endl;

    // Initialize GLEW
//    if (glewInit() != GLEW_OK) {
//        std::cerr << "Failed to initialize GLEW" << std::endl;
//        return;
//    }

//    glfwSetKeyCallback(window, Input::key_callback);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}


