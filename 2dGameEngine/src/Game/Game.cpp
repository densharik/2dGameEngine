#include "Game.h"
#include "../ECS/ESC.h"
#include <SDL.h>
#include <SDL_image.h>
#include <glm/glm.hpp>
#include <spdlog/spdlog.h>
#include <iostream>


Game::Game() {
	isRunning = false;
	spdlog::info("Game constructor called!");
}

Game::~Game() {
	spdlog::info("Game destructor called!");
}

void Game::Initialize() {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) //���� ���������� SDL �� ��������� ��������
	{
		spdlog::error("Error initializing SDL");
		return;
	}
	SDL_DisplayMode displayMode; //���������� � ����������� � ���������� ������ ������������
	SDL_GetCurrentDisplayMode(0,&displayMode);//�������� ���������� ������ �� ��������� � displayMode

	windowWidth = displayMode.w; //���������� ������ ������
	windowHeight = displayMode.h; //���������� ������ ������
	window = SDL_CreateWindow
		(
			NULL, //�������� ����
			SDL_WINDOWPOS_CENTERED,// ������� �� X
			SDL_WINDOWPOS_CENTERED,// ������� �� Y
			800,//windowWidth,
			600,// windowHeight,
			SDL_WINDOW_BORDERLESS //���� ��� �����
		);//������� �������� ����

	if (!window)  //������ ���� ���� �� ����������������
	{
		spdlog::error("Error initializing Window");
		return;
	}

	renderer = SDL_CreateRenderer(window, -1, 0);//������ ����������� � ��������� ���� �� ������ �� ���������

	if (!renderer) //������ ���� ������ ��� ������ �� ��������
	{
		spdlog::error("Error initializing Rederer");
		return;
	}

	//SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);

	isRunning = true;
}//�������� ����, ������������� ������� ����

void Game::Run() {
	Setup();//��������� ��������� ����������
	while (isRunning) {
		ProcessInput();//���������� �����
		Update();//���������� �����
		Render();//������ �����
	}
}//������� ����

void Game::Setup() {
	/*
	TODO
	Entity tank = registr.CreateEntity();
	tank.AddComponent<TrasnformComponent>()
	tank.AddComponent<BoxColliderComponent>();
	tank.AddComponent<SpriteComponent>(./assets/images/tank.png)
	*/
}//��������� ��������� ����������

void Game::ProcessInput() {
	SDL_Event sdlEvent;
	while (SDL_PollEvent(&sdlEvent)) {
		switch (sdlEvent.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYDOWN:
			if (sdlEvent.key.keysym.sym == SDLK_ESCAPE) {
				isRunning = false;
			}
			break;
		}
	};
}//���������� �����

void Game::Update() {
	//while (!SDL_TICKS_PASSED(SDL_GetTicks(), millisecsPreviousFrame + MILLISECS_PER_FRAME));
	int timeToWait = MILLISECS_PER_FRAME - (SDL_GetTicks() - millisecsPreviousFrame);
	if (timeToWait > 0 && timeToWait <= MILLISECS_PER_FRAME) {
		SDL_Delay(timeToWait);
	}
	double deltaTime = (SDL_GetTicks() - millisecsPreviousFrame)/1000.0;
	millisecsPreviousFrame = SDL_GetTicks();

	/*
	TODO
	MovementSystem.Update();
	CollisionSystem.Update();
	DamageSystem.Update();
	*/
}//���������� �����

void Game::Render() {
	SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255); 
	SDL_RenderClear(renderer);

	/*
	TODO 
	Render
	*/

	SDL_RenderPresent(renderer);
}//������ �����

void Game::Destroy() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}