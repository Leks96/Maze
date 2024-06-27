#ifndef HEADER_H
#define HEADER_H

#include <SDL2/SDL.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "upng.h"

/* Constants */

#define PI 3.14159265
#define TWO_PI (2 * PI)

#define WALL 64

#define SMALLMAP_SCALE_FACTOR 0.25

#define SCREEN_WIDTH (MAP_COLS * WALL)
#define SCREEN_HEIGHT (MAP_ROWS * WALL)

#define FOV_ANGLE (PI / 3)
#define NUM_RAYS SCREEN_WIDTH

#define PROJECTION_PLANE ((SCREEN_WIDTH / 2) / tan(FOV_ANGLE / 2))

#define FRAME_PER_SEC 30
#define FRAME_TIME_LENGTH (1000 / FRAME_PER_SEC)

#define MAP_ROWS 13
#define MAP_COLS 20

#define NUM_TEXT 8

typedef uint32_t color_t;

/* Process Input */
void handleInput(void);
extern bool GameRunning;

/* Draw Function Variables */

bool initWindow(void);
void destroyWindow(void);
void clearColorBuffer(color_t color);
void render_game(void);
void renderColorBuffer(void);
void drawPixel(int x, int y, color_t color);
void drawRectangle(int x, int y, int width, int height, color_t color);
void drawLine(int x0, int y0, int x1, int y1, color_t color);

/* Map Fuunction Variables */
bool DetectCollision(float x, float y);
bool isInMap(float x, float y);
void renderMap(void);
int getMapVal(int row, int col);

/* Player Function Struct Variable */

/**
 * struct player_s - struct for texts
 * @x: x co-ords
 * @y: y co-ords
 * @width: player width
 * @height: player height
 * @turningDirection: Turning Direction
 * @walkDirection: Walking Direction
 * @rotationAngle: player's angle of rotation
 * @walkSpeed: walking speed
 * @turnSpeed: turniing Speed
 */

typedef struct player_s
{
	float x;
	float y;
	float width;
	float height;
	int turningDirection;
	int walkDirection;
	float rotationAngle;
	float walkSpeed;
	float turnSpeed;
} player_t;

extern player_t player;

void movePlayer(float DTime);
void renderPlayer(void);

/* Ray Function Variable */

/**
 * struct ray_s - struct for the rays
 * @rayAngle: ray angle
 * @wallHitX: wall hit x co-ords
 * @wallHitY: wall hit y co-ords
 * @distance: distance to the wall
 * @hitVertical: verify vertical hit
 * @hitContent: verify content hit
 */

typedef struct ray_s
{
	float rayAngle;
	float wallHitX;
	float wallHitY;
	float distance;
	bool hitVertical;
	int hitContent;
} ray_t;

extern ray_t rays[NUM_RAYS];

float distanceBtwPoints(float x1, float y1, float x2, float y2);
bool rayFacingUp(float angle);
bool rayFacingDown(float angle);
bool rayFacingLeft(float angle);
bool rayFacingRight(float angle);
void castAllRays(void);
void castRay(float rayAngle, int stripId);
void renderRays(void);
void horizontalIntersection(float rayAngle);
void verticalIntersection(float rayAngle);

/* Textures Function Variables */

/**
 * struct texture_s - struct for the textures
 * @width: texture width
 * @height: texture height
 * @texture_buffer: pointer to texture buffer
 * @upngTexture: pointer to upng buffer
 *
 */

typedef struct texture_s
{
	int width;
	int height;
	color_t *texture_buffer;
	upng_t *upngTexture;
} texture_t;

extern texture_t wallTextures[NUM_TEXT];

void wallTexturesready(void);
void freeWallText(void);

/* Walls functions struct variabble */

void renderWall(void);

#endif /* HEADRE_H */
