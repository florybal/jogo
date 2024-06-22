#include "gameObjects.h"

class Enemy : public gameObject
{
public:
    void load(int x, int y, int width, int height, std::string textureId );
    void draw(SDL_Renderer* pRender);
    void update();
    void clean();
};