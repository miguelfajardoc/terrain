#include <SDL2/SDL.h>

int main(void)
{
	SDL_Window *window;
	SDL_Renderer *renderer;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(stderr, "unable to initialize SDL: %s", SDL_GetError());
		return(1);
	}
	/*Create a new window instante*/
	window = SDL_CreateWindow("SDL2 \\o/", SDL_WINDOWPOS_CENTERED,
				  SDL_WINDOWPOS_CENTERED, 1260, 720, 0);
	if (window == NULL)
	{
		fprintf(stderr, "unable to initialize SDL: %s", SDL_GetError());
		SDL_Quit();
		return(1);
	}
	/*Create a new Redner instance linked to the window*/
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
				      SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL)
	{
		SDL_DestroyWindow(window);
		fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
		SDL_Quit();
		return(1);
	}
	return(0);
}
