#pragma once
#include <SDL.h>
#include "../ECS/EntityManager.h"
#include <vector>

class BoxCollider2D;

constexpr int SCREEN_WIDTH = 640;
constexpr int SCREEN_HEIGHT = 480;
constexpr SDL_Color DARK = { 30,30,30,255 };

class Core
{
public:
	Core();
	~Core();

	void init();
	void quit();
	void clean();

	void events();
	void update(float dt);
	void render();

	//Singleton
	inline static Core& get() {
		if (s_instance == nullptr) {
			s_instance = new Core();
		}
		return *s_instance;
	}

	inline bool isRunning() {
		return running;
	}

	inline SDL_Rect* getCamera() {
		return camera;
	}

	inline SDL_Event* getEvent() {
		return event;
	}

	inline std::vector<BoxCollider2D*> getColliders() {
		return colliders;
	}

	inline void addCollider(BoxCollider2D* col) {
		colliders.push_back(col);
	}

	inline SDL_Renderer* getRenderer(){
		return renderer;
	}

private:
	EntityManager* manager;
	SDL_Event* event;

	bool running;
	SDL_Window* window;
	SDL_Color clearColor;
	SDL_Renderer* renderer;

	SDL_Rect* camera;

	std::vector<BoxCollider2D*> colliders;

	static Core* s_instance;
};

