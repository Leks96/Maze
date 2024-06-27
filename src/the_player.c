#include "../headers/header.h"

/**
 * movePlayer - set the next position for the player
 * @DTime: time elapsed since the last frame.
 */

void movePlayer(float DTime)
{
    float step, nPlayerX, nPlayerY;

    player.rotationAngle += player.turningDirection * player.turnSpeed * DTime;
    step = player.walkDirection * player.walkSpeed * DTime;

    nPlayerX = player.x + cos(player.rotationAngle) * step;
    nPlayerY = player.y + sin(player.rotationAngle) * step;

    if (!DetectCollision(nPlayerX, nPlayerY))
    {
        player.x = nPlayerX;
        player.y = nPlayerY;
    }
}

/**
 * renderPlayer - render the player
 */

void renderPlayer(void)
{
    drawRectangle(
        player.x * SMALLMAP_SCALE_FACTOR,
        player.y * SMALLMAP_SCALE_FACTOR,
        player.width * SMALLMAP_SCALE_FACTOR,
        player.height * SMALLMAP_SCALE_FACTOR,
        0xFFFFFFFF
    );
}