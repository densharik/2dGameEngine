#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <glm/glm.hpp>


const int FPS = 1000;
const int MILLISECS_PER_FRAME = 1000 / FPS;

class Game {
	private:
		bool isRunning;
		unsigned int millisecsPreviousFrame = 0;
		SDL_Window* window;
		SDL_Renderer* renderer;
	public:
		Game();
		~Game();
		void Initialize();
		void Run();
		void Setup();
		void ProcessInput();
		void Update();
		void Render();
		void Destroy();

		unsigned int windowWidth;
		unsigned int windowHeight;
};


#endif 