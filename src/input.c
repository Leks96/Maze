#include "../headers/header.h"

/**
 * SDL_KEYDOWN_FUNC - process input when a key is down
 * @event: union that contains structures for the different event types
 */
void SDL_KEYDOWN_FUNC(SDL_Event event)
{
    if (event.key.keysym.sym == SDLK_ESCAPE)
        GameRunning = false;
    if (event.key.keysym.sym == SDLK_UP)
        player.walkDirection = +1;
    if (event.key.keysym.sym == SDLK_DOWN)
        player.walkDirection = -1;
    if (event.key.keysym.sym == SDLK_RIGHT)
        player.turningDirection = +1;
    if (event.key.keysym.sym == SDLK_LEFT)
        player.turningDirection = -1;
    if (event.key.keysym.sym == SDLK_w)
        player.walkDirection = +1;
    if (event.key.keysym.sym == SDLK_s)
        player.walkDirection = -1;
    if (event.key.keysym.sym == SDLK_a)
        player.turningDirection = -1;
    if (event.key.keysym.sym == SDLK_d)
        player.turningDirection = +1;
}

/**
 * SDL_KEYUP_FUNC - process input when a key is up
 * @event: union that contains structures for the different event types
 */
void SDL_KEYUP_FUNC(SDL_Event event)
{
    if (event.key.keysym.sym == SDLK_ESCAPE)
        GameRunning = false;
    if (event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_w || event.key.keysym.sym == SDLK_s)
        player.walkDirection = 0;
    if (event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_a || event.key.keysym.sym == SDLK_d)
        player.turningDirection = 0;
}

/**
 * handleInput - process input from the keyboard
 */
void handleInput(void)
{
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            GameRunning = false;
        } else if (event.type == SDL_KEYDOWN) {
            SDL_KEYDOWN_FUNC(event);
        } else if (event.type == SDL_KEYUP) {
            SDL_KEYUP_FUNC(event);
        }
    }
}