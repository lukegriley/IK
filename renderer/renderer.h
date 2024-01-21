#include "camera.h"
#include "SceneData.h"

#ifndef RENDERER_H
#define RENDERER_H


class Renderer
{
public:
    Renderer(Camera *cam,SceneData *data);
    void initializeGL();
    void resizeGL(int w, int h);
    inline void setRatio(float x, float y) {
        ratio_x = x;
        ratio_y = y;
        resizeGL(DSCREEN_WIDTH * ratio_x, DSCREEN_HEIGHT * ratio_y);
    }
private:
    Camera *m_cam;
    SceneData *m_scenedata;
    float ratio_x;
    float ratio_y;
};

#endif // RENDERER_H
