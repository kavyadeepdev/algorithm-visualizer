#include "../../include/StateVariables.hpp"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <iostream>
#include <string>
#include <vector>

namespace Visualizer {

//
// function declaration
//
void renderVisualizer(SDL_Renderer *renderer, std::vector<int> arr,
					  int reference, int current);
void renderFrame(SDL_Renderer *renderer, std::vector<int> arr, int reference,
				 int current);
void bubbleSort(std::vector<int> arr, SDL_Renderer *renderer);
void selectionSort(std::vector<int> arr, SDL_Renderer *renderer);
void insertionSort(std::vector<int> arr, SDL_Renderer *renderer);
void mergeSort(std::vector<int> arr, SDL_Renderer *renderer);
void quickSort(std::vector<int> arr, SDL_Renderer *renderer);

//
// visualizer
//
void SortingVisualizer(SDL_Renderer *renderer, std::vector<int> arr) {
	// std::string algo = "bubble-sort";
	std::string algo = "insertion-sort";
	if (!is_array_sorted) {
		if (algo == "bubble-sort") {
			bubbleSort(arr, renderer);
		} else if (algo == "selection-sort") {
			selectionSort(arr, renderer);
		} else if (algo == "insertion-sort") {
			insertionSort(arr, renderer);
		} else if (algo == "merge-sort") {
			mergeSort(arr, renderer);
		} else if (algo == "quick-sort") {
			quickSort(arr, renderer);
		} else {
			std::cout << "Error: invalid sorting algorithm" << std::endl;
		}
		is_array_sorted = true;
	} else {
		// current_view = "main-menu";
		return;
	}
}

//
// functions definitions
//

// render functions
void renderVisualizer(SDL_Renderer *renderer, std::vector<int> arr,
					  int reference, int current) {
	int i = 0;
	for (int val : arr) {
		if (i == reference)
			SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
		else if (i == current)
			SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		else
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		// SDL_RenderDrawLine(renderer, i, 359, i, 359 - val);
		// SDL_Rect rect(i, 359, i + 5, 359 - val); // the rectangle
		SDL_Rect rect;
		rect.x = i;
		rect.y = 359;
		rect.w = 5;
		rect.h = -val;
		SDL_RenderFillRect(renderer, &rect);
		i += 5;
	}
}

void renderFrame(SDL_Renderer *renderer, std::vector<int> arr, int reference,
				 int current) {
	// pre
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	// render
	renderVisualizer(renderer, arr, reference, current);
	SDL_RenderPresent(renderer);
	SDL_Delay(2);
	// post
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

// sorting algorithms
void bubbleSort(std::vector<int> arr, SDL_Renderer *renderer) {
	for (int i = 0; i < arr.size() - 1; ++i) {
		for (int j = i + 1; j < arr.size(); ++j) {
			if (arr[i] > arr[j]) {
				std::swap(arr[i], arr[j]);
			}
			renderFrame(renderer, arr, i, j);
		}
	}
}

void selectionSort(std::vector<int> arr, SDL_Renderer *renderer) {
	for (int i = 0; i < arr.size() - 1; ++i) {
		int min = i;
		for (int j = i + 1; j < arr.size(); ++j) {
			if (arr[j] < arr[min]) {
				min = j;
			}
			renderFrame(renderer, arr, i, j);
		}
		std::swap(arr[i], arr[min]);
	}
}
void insertionSort(std::vector<int> arr, SDL_Renderer *renderer) {
	for (int i = 1; i < arr.size(); i++) {
		int key = arr[i];
		int j = i - 1;

		// Compare key with each element on the left of it until an element
		// smaller than it is found. For descending order, change key<array[j]
		// to key>array[j].
		while (key < arr[j] && j >= 0) {
			arr[j + 1] = arr[j];
			--j;
			renderFrame(renderer, arr, i, j);
		}
		arr[j + 1] = key;
	}
}
void mergeSort(std::vector<int> arr, SDL_Renderer *renderer) {}
void quickSort(std::vector<int> arr, SDL_Renderer *renderer) {}

} // namespace Visualizer
