#ifndef _PLAYER_CLASS_
#define _PLAYER_CLASS_

#include "gameObjects.h"

class Player : public gameObject
{
    public:
        void load(int x, int y, int width, int heght, std::string textureID);
        void draw(SDL_Renderer *m_render);
        void update();
        void clean();
};

#endif