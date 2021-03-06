#pragma once
#include <vector>
#include <memory>
#include "Entity.h"

class EntityManager {
public:
	void draw();
	void update(float dt);
	void refresh();

	void addEntity(Entity* entity);
	void eraseEntity(Entity* entity);
	Entity* closeEntity(Entity* entity);

private:
	std::vector<std::unique_ptr<Entity>> entities;
};

