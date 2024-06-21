//
// Created by soonluck8 on 6/23/23.
//
#include "game.h"

game::game()
{

}

game::~game()
{

}

void game::run()
{
    init();

    while(running())
    {
        processEvent();
        update();
        render();

        SDL_Delay(10);
    }
    clean();

}

void game::render()
{
    SDL_RenderClear(_render);

    //_textureManager::Instance()->draw("player", 50, 50, 16,16, _render);
    //_textureManager::Instance()->drawFrame("player", 150, 150, 16, 16, 1, m_currentFrame, _render, SDL_FLIP_NONE);
    
    //m_go.draw(_render);
    //m_player.draw(_render);

    for(std::vector<gameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw(_render);
    }
    
    SDL_SetRenderDrawColor(_render, 96, 128, 150, 100);
    SDL_RenderPresent(_render);
}


void game::clean()
{
    SDL_DestroyRenderer(_render);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void game::update()
{
            std::cout<<"penis";

    //m_currentFrame = int((( SDL_GetTicks() / 100) % 6 ));
    for(std::vector<gameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
        std::cout<<"penis";
    }
    
    //m_go->update();
    //m_player->update();
}

bool game::init()
{
    isRuning = true;

    /*
    SDL_RENDERER_SOFTWARE      -> Use software rendering
    SDL_RENDERER_ACCELERATED   -> Use hardware acceleration
    SDL_RENDERER_PRESENTVSYNC  -> Synchronize renderer update with screen's refresh rate
    SDL_RENDERER_TARGETTEXTURE -> Supports render to texture
    */

    int rendererFlags = SDL_RENDERER_TARGETTEXTURE;
    int windowFlags   = 0;

    _window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                               screen_Width, screen_Height, windowFlags);

    if (SDL_Init(SDL_INIT_VIDEO)< 0)
    {
        std::cout<<"nao foi possivel inicializar o SDL: \n"
                 << SDL_GetError();        
        return false;
    }

    if(!_window)
    {
        std::cout<<"nao foi possivel criar a janela: \n"
                 << screen_Width, SDL_GetError();
        return false;
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

    _render = SDL_CreateRenderer(_window, -1, rendererFlags);

    if(!_render)
    {
        std::cout<<"nao foi possivel criar renderer : \n" 
                << SDL_GetError();
        return false;
    }

    if(!_textureManager::Instance()->load("../resources/player.png", "player", _render)) 
    {
        return false;
    }

    m_player = new Player();
    //m_enemy1 = new Enemy();
    //m_enemy2 = new Enemy();
    //m_enemy3 = new Enemy();

    
    m_go->load(200, 200, 16, 16, "player");
    m_player->load(300, 300, 16, 16, "player");

    m_gameObjects.push_back(m_player);
    m_gameObjects.push_back(m_go);
    //m_gameObjects.push_back(m_enemy1);
    //m_gameObjects.push_back(m_enemy2);
    //m_gameObjects.push_back(m_enemy3);

    return true;
}

void game::processEvent()
{
    SDL_Event event;

    while(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                isRuning = false;
                break;

            default:
                break;
        }
    }
}
