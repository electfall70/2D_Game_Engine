#pragma once
#include "SDL.h"
#include "Components.h"

class SpriteComponent : public Component {
private:
	PositionComponent *position;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;

public:
	SpriteComponent() = default;
	SpriteComponent(const char* path)
	{
		texture = TextureHandler::loadFromFile(path);
	}
	void init() override
	{
		position = &entity->getComponent<PositionComponent>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = srcRect.h = 32;
		destRect.w = destRect.h = 64;

	}
	void update() override
	{
		destRect.x = position->x();
		destRect.y = position->y();
	}
	void draw() override
	{
		TextureHandler::draw(texture, srcRect, destRect);
	}
};