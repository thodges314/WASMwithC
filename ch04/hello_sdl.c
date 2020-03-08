#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <emscripten.h>
#include <stdio.h>

#define MESSAGE "HELLO SDL!"
#define FONT_SIZE 16
#define FONT_FILE "font/Roboto-Black.ttf"

int main()
{
	SDL_Window *window;
	SDL_Renderer *renderer;

	SDL_Rect dest = {.x = 160, .y = 100, .w = 0, .h = 0};

	TTF_Font *font;
	SDL_Texture *texture;

	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();

	SDL_CreateWindowAndRenderer(320, 200, 0, &window, &renderer);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // I'll do it in red
	SDL_RenderClear(renderer);

	font = TTF_OpenFont(FONT_FILE, FONT_SIZE);
	SDL_Color font_color = {0, 255, 0, 255}; // I'll use green
	SDL_Surface *temp_surface = TTF_RenderText_Blended(font, MESSAGE, font_color);

	texture = SDL_CreateTextureFromSurface(renderer, temp_surface);
	SDL_FreeSurface(temp_surface);

	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

	dest.x -= dest.w / 2;
	dest.y -= dest.h / 2;

	SDL_RenderCopy(renderer, texture, NULL, &dest);
	SDL_RenderPresent(renderer);

	return EXIT_SUCCESS;
}

// emcc hello_sdl.c --emrun --preload-file font -s USE_SDL=2 -s USE_SDL_TTF=2 -o hello_sdl.html
// emrun --browser firefox hello_sdl.html

// or leave off emrun and run http-server in the directory with the file