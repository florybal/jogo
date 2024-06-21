#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

#include "include.h"
#include "textureManager.h"

class gameObject
{
public:
    void load(int x, int y, int width, int height, std::string TextureID);
    void draw(SDL_Renderer *m_render);
    void update();
    void clean();

protected:
    std::string m_textureID;

    int m_currentFrame;
    int m_currentRow;

    int m_x;
    int m_y;

    int m_width;
    int m_height;
};

#endif