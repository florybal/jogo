#include "enemy.h"

void Enemy::update()
{
    m_x += 1;
    m_y += 1;
    m_currentFrame = int((( SDL_GetTicks() / 100) % 6 ));
 
}
