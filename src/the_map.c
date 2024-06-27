#include "../headers/header.h"

static const int the_map[MAP_ROWS][MAP_COLS] = {
    {6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6},
    {6,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,6},
    {6,0,1,1,1,0,1,1,1,6,1,1,1,0,1,1,1,0,0,6},
    {6,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,6},
    {6,0,1,0,6,6,6,0,6,6,6,0,6,6,6,0,1,0,0,6},
    {6,0,1,0,6,0,6,0,6,0,6,0,6,0,6,0,1,0,0,6},
    {6,0,1,0,6,0,6,0,6,0,6,0,6,0,6,0,1,0,0,6},
    {6,0,1,0,6,0,0,0,0,0,0,0,0,0,6,0,1,0,0,6},
    {6,0,1,0,6,6,6,0,6,6,6,0,6,6,6,0,1,0,0,6},
    {6,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,6},
    {6,0,1,1,1,0,1,1,1,6,1,1,1,0,1,1,1,0,0,6},
    {6,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,6},
    {6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6}
};

/**
 * DetectCollision - checks if there is a collison
 * with the wall as the player advance
 * @x: next x co-ords
 * @y: next y co-ords
 * Return: true if collision is detected, otherwise
 * return false
 */

bool DetectCollision(float x, float y)
{
    int gridX, gridY;

    if (x < 0 || x >= MAP_COLS * WALL ||
                    y < 0 || y >= MAP_ROWS * WALL)
        return (true);

    gridX = floor(x / WALL);
    gridY = floor(y / WALL);

    return (the_map[gridY][gridX] != 0);
}

/**
 * isInMap - check if to continue inside the map
 * @x: next x co-ord
 * @y: next y co-ord
 * Return: true if it is inside the map, otherwise flase
 */

bool isInMap(float x, float y)
{
    return (x >= 0 && x <= MAP_COLS * WALL &&
                            y >= 0 && y <= MAP_ROWS * WALL);
}

/**
 * getMapVal - get the map position value
 * @row: map row to check
 * @col: map column to check
 * Return: The position val in the map
 */

int getMapVal(int row, int col)
{
    return (the_map[row][col]);
}

/**
 * renderMap: render the map
 */

void renderMap(void)
{
    int k, l, sqX, sqY;
    color_t sqColor;

    for (k = 0; k < MAP_ROWS; k++)
    {
        for (l = 0; l < MAP_COLS; l++)
        {
            sqX = l * WALL;
            sqY = k * WALL;
            sqColor = the_map[k][l] != 0 ? 0xFFFFFFFF : 0x00000000;

            drawRectangle (
                sqX * SMALLMAP_SCALE_FACTOR,
                sqY * SMALLMAP_SCALE_FACTOR,
                WALL * SMALLMAP_SCALE_FACTOR,
                WALL * SMALLMAP_SCALE_FACTOR,
                sqColor
            );
        }
    }
}