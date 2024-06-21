#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include "include.h"
#include <map>

class textureManager
{
public:

	bool load(std::string fileName, std::string id, SDL_Renderer* _renderer);
	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* _renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* _renderer, SDL_RendererFlip flip);

	static textureManager* Instance()
	{
		if(s_pInstane == 0)
		{
			s_pInstane = new textureManager();
			return s_pInstane;
		}
		return s_pInstane;
	}
	
	std::map<std::string, SDL_Texture*> _textureMap;
	
	static textureManager* s_pInstane;
	textureManager(){}
	~textureManager(){}
};

typedef textureManager _textureManager;

#endif
