#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <SDL.h>

#include "funkcje.h"

void set_points(int how_many_points_points) {
	if (how_many_points_points < 2) {
		cornerPoints[0].x = (width / 2) / scale;
		cornerPoints[0].y = (height / 2) / scale;
	}
	else if (how_many_points_points == 2) {
		cornerPoints[0].x = (width / 2) / scale;
		cornerPoints[0].y = 50 / scale;
		cornerPoints[1].x = (width / 2) / scale;
		cornerPoints[1].y = (height - 50) / scale;
	}
	else if (how_many_points_points == 3) {
		cornerPoints[0].x = (width / 2) / scale;
		cornerPoints[0].y = 50 / scale;
		cornerPoints[1].x = (50) / scale;
		cornerPoints[1].y = (height - 50) / scale;
		cornerPoints[2].x = (width - 50) / scale;
		cornerPoints[2].y = (height - 50) / scale;
	}
	else if (how_many_points_points == 4) {
		cornerPoints[0].x = 50 / scale;
		cornerPoints[0].y = 50 / scale;
		cornerPoints[1].x = 50 / scale;
		cornerPoints[1].y = (height - 50) / scale;
		cornerPoints[2].x = (width - 50) / scale;
		cornerPoints[2].y = 50 / scale;
		cornerPoints[3].x = (width - 50) / scale;
		cornerPoints[3].y = (height - 50) / scale;
	}
	else if (how_many_points_points == 5) {
		//wartosci staralem sie obliczyc na kartce bo nie mia³em pojêcia jak ustaliæ ich koordynaty.
		cornerPoints[0].x = (width / 2) / scale;
		cornerPoints[0].y = 50 / scale;

		cornerPoints[1].x = 137 / scale;
		cornerPoints[1].y = 241 / scale;

		cornerPoints[2].x = ((width / 2) - 162.5) / scale;
		cornerPoints[2].y = (height - 50) / scale;

		cornerPoints[3].x = ((width / 2) + 162.5) / scale;
		cornerPoints[3].y = (height - 50) / scale;

		cornerPoints[4].x = (width - 137) / scale;
		cornerPoints[4].y = 241 / scale;
	}
}

int get_random_point(int how_many_points_points, int last_selected) {
	int random_point = -1;
	if (how_many_points_points <= 3 || how_many_points_points >= 5) {
		random_point = rand() % how_many_points_points;
		return random_point;
	}
	else if (how_many_points == 4) {
		while (random_point == last_selected || random_point == -1) {
			random_point = rand() % how_many_points;
		}
		return random_point;
	}
}
void display_points(int how_many_points, int divide_distance_by) {
	int last_point = -1;
	int x = (width / 2) / scale;
	int y = (height / 2) / scale;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("sdl failed \n");
		return 1;
	}
	SDL_Window* window = SDL_CreateWindow("chaos", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
	SDL_Event event;
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
	SDL_RenderSetScale(renderer, scale, scale);
	SDL_RenderDrawPoints(renderer, cornerPoints, how_many_points);
	bool window_loop = true;
	while (window_loop) {
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				window_loop = false;
			}
		}
		// losowanie punktu do ktorego zmierzamy
		int which_point = get_random_point(how_many_points, last_point);
		SDL_RenderDrawPoint(renderer, x, y);
		SDL_RenderPresent(renderer);
		//znajdywanie nastepengo punktu
		x = x - (x - cornerPoints[which_point].x) / divide_distance_by;
		y = y - (y - cornerPoints[which_point].y) / divide_distance_by;
		last_point = which_point;
		Sleep(1000);
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}