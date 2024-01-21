#ifndef GAME_H
#define GAME_H

#include "glfw/glfw3.h"


class Game
{
public:
    Game();

    void startGame();
    int DSCREEN_WIDTH = 1280;
    int DSCREEN_HEIGHT = 720;
private:
    bool m_running = true;

    void setupWindow();

    float m_monitorXScale, m_monitorYScale;

    GLFWwindow* m_window;
};

#endif // GAME_H
