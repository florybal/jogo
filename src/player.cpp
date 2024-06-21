#include "player.h"

void Player::load(int x, int y, int width, int height, std::string textureID)
{
    gameObject::load(x, y, width, height, textureID);
}

void Player::draw(SDL_Renderer *m_render)
{
    gameObject::draw(m_render);
}

void Player::update()
{
    m_x -= 1;
}

void Player::clean()
{

}