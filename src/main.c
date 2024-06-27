#include "../headers/header.h"

bool GameRunning = false;
int TouchLastFrame;
player_t player;

/**
 * setup_game - init player var and load wall textures
 *
 */

void setup_game(void)
{
	player.x = SCREEN_WIDTH / 2;
	player.y = SCREEN_HEIGHT / 2;
	player.width = 1;
	player.height = 1;
	player.walkDirection = 0;
	player.walkSpeed = 90;
	player.turningDirection = 0;
	player.turnSpeed = 45 * (PI / 180);
	player.rotationAngle = PI / 2;
	wallTexturesready();

	TouchLastFrame = SDL_GetTicks();
}

/**
 * update_game - update game delta time and touch last frame
 * the player movement and the ray casting
 *
 */
void update_game(void)
{
	float DeltaTime;
	int timeWait = FRAME_TIME_LENGTH - (SDL_GetTicks() - TouchLastFrame);

	if (timeWait > 0 && timeWait <= FRAME_TIME_LENGTH)
	{
		SDL_Delay(timeWait);
	}
	DeltaTime = (SDL_GetTicks() - TouchLastFrame) / 1000.0f;

	TouchLastFrame = SDL_GetTicks();

	movePlayer(DeltaTime);
	castAllRays();
}

/**
 * render - calls all function needed for on-screen rendering
 *
 */

void render_game(void)
{
	clearColorBuffer(0xFF000000);

	renderWall();

	renderMap();
	renderRays();
	renderPlayer();

	renderColorBuffer();
}

/**
 * Destroy - free wall textures and destroy window
 *
 */
void destroy_game(void)
{
	freeWallText();
	destroyWindow();
}

/**
 * main - main func
 * Return: 0
 */
int main(void)
{
	GameRunning = initWindow();

	setup_game();

	while (GameRunning)
	{
		handleInput();
		update_game();
		render_game();
	
	}
	destroy_game();
	return (0);
}
