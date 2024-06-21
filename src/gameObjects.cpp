#include "gameObjects.h"

void gameObject::load(int x, int y, int width, int height, std::string TextureID)
{
    m_x = x;
    m_y = y;
    m_width = width;
    m_height = height;
    m_textureID = TextureID;

    m_currentFrame = 1;
    m_currentRow = 1;
}

void gameObject::draw(SDL_Renderer *m_render)
{
    _textureManager::Instance()->drawFrame(m_textureID, m_x, m_y, m_width, m_height, m_currentRow, m_currentFrame, m_render, SDL_FLIP_NONE);
}

void gameObject::update()
{
    m_currentFrame = int((( SDL_GetTicks() / 100) % 6 ));
}
void gameObject::clean()
{

}
