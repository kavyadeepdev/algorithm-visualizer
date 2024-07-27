#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>
namespace Menu {
void MainMenu(const int window_width, const int window_height,
			  SDL_Renderer *renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderPresent(renderer);

	TTF_Init();
	TTF_Font *font = TTF_OpenFont(
		"/home/kavyadeep/code/algorithm-visualizer/public/fonts/OpenSans.ttf",
		200);
	SDL_Color color = {255, 255, 255, 255};

	// Title
	SDL_Surface *title_surface =
		TTF_RenderText_Solid(font, "Algorithm Visualizer", color);

	SDL_Texture *title_texture =
		SDL_CreateTextureFromSurface(renderer, title_surface);
	int title_xcenter = window_width / 2;
	int title_ycenter = window_height / 2;

	SDL_Rect title_rect; // create a rect
	title_rect.w = 300;	 // controls the width of the rect
	title_rect.h = 100;	 // controls the height of the rect
	title_rect.x = title_xcenter - (title_rect.w / 2);
	title_rect.y = title_ycenter - (title_rect.h / 2) - 40;

	SDL_RenderCopy(renderer, title_texture, NULL, &title_rect);

	// 1. Sorting Option
	SDL_Surface *sort_option_surface =
		TTF_RenderText_Solid(font, "1. Sorting Visualizer", color);

	SDL_Texture *sort_option_texture =
		SDL_CreateTextureFromSurface(renderer, sort_option_surface);
	int sort_option_xcenter = window_width / 2;
	int sort_option_ycenter = window_height / 2;

	SDL_Rect sort_option_rect; // create a rect
	sort_option_rect.w = 120;  // controls the width of the rect
	sort_option_rect.h = 30;   // controls the height of the rect
	sort_option_rect.x = 40;
	sort_option_rect.y = 200;
	// sort_option_rect.x = sort_option_xcenter - (sort_option_rect.w / 2);
	// sort_option_rect.y = sort_option_ycenter - (sort_option_rect.h / 2);

	SDL_RenderCopy(renderer, sort_option_texture, NULL, &sort_option_rect);

	// 2. Pathfinding Option
	SDL_Surface *path_option_surface =
		TTF_RenderText_Solid(font, "2. Pathfinding Visualizer", color);

	SDL_Texture *path_option_texture =
		SDL_CreateTextureFromSurface(renderer, path_option_surface);
	int path_option_xcenter = window_width / 2;
	int path_option_ycenter = window_height / 2;

	SDL_Rect path_option_rect; // create a rect
	path_option_rect.w = 160;  // controls the width of the rect
	path_option_rect.h = 30;   // controls the height of the rect
	path_option_rect.x = 300;
	path_option_rect.y = 200;
	// path_option_rect.x = path_option_xcenter - (path_option_rect.w / 2);
	// path_option_rect.y = path_option_ycenter - (path_option_rect.h / 2);

	SDL_RenderCopy(renderer, path_option_texture, NULL, &path_option_rect);


	// free surface and texture
	SDL_FreeSurface(title_surface);
	SDL_DestroyTexture(title_texture);

	SDL_FreeSurface(sort_option_surface);
	SDL_DestroyTexture(sort_option_texture);

	SDL_FreeSurface(path_option_surface);
	SDL_DestroyTexture(path_option_texture);
	TTF_Quit();
}
} // namespace Menu
