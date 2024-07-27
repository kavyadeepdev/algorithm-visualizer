#include "../include/StateVariables.hpp"
#include "../include/menus/MainMenu.hpp"
#include "../include/menus/PathfindingMenu.hpp"
#include "../include/menus/SortingMenu.hpp"
#include "../include/utils/View.hpp"
#include "../include/visualizers/PathfindingVisualizer.hpp"
#include "../include/visualizers/SortingVisualizer.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <iostream>
#include <random>
#include <string>
#include <vector>

const int window_height = 360;
const int window_width = 500;

int main() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "Error: " << SDL_GetError();
	} else {
		// init window and renderer
		SDL_Window *window = nullptr;
		SDL_Renderer *renderer = nullptr;
		SDL_CreateWindowAndRenderer(window_width, window_height, 0, &window,
									&renderer);

		// initialize background
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderPresent(renderer);

		// generate array
		std::vector<int> arr;
		std::random_device rd;
		std::uniform_int_distribution d(1, 359);
		for (int i = 0; i < 100; ++i) {
			arr.emplace_back(d(rd));
		}

		// event loop
		SDL_Event event;

		while (is_running) {
			while (SDL_PollEvent(&event) == 1) {
				// check for SDL_QUIT event
				if (event.type == SDL_QUIT) {
					is_running = false;
				} else if (event.type == SDL_MOUSEBUTTONDOWN) {
					const int mouse_x = event.button.x;
					const int mouse_y = event.button.y;
					if (mouse_y >= 200 && mouse_y <= 230) {
						if (mouse_x >= 40 && mouse_x <= 160) {
							// current_view = "sorting-visualizer";
							if (current_view == "main-menu") {
								current_view = "sorting-menu";
								SDL_RenderClear(renderer);
							} else {
								current_view = "main-menu";
								SDL_RenderClear(renderer);
							}
						}
					}
				}
			}
			// scene render logic
			switch (View::ResolveView(current_view)) {
			case View::MainMenu:
				Menu::MainMenu(window_width, window_height, renderer);
				break;
			case View::SortingMenu:
				Menu::SortingMenu(window_width, window_height, renderer);
				break;
			// case View::PathfindingMenu:
			// 	Menu::PathfindingMenu(renderer);
			// 	break;
			case View::SortingVisualizer:
				Visualizer::SortingVisualizer(renderer, arr);
				break;
			// case View::PathfindingVisualizer:
			// 	Visualizer::PathfindingVisualizer(renderer, matrix);
			// 	break;
			default:
				std::cout << "Error: invalid view" << std::endl;
				is_running = false;
			}
		}
		SDL_Quit();
	}
}
