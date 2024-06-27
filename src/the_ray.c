#include "../headers/header.h"

ray_t rays[NUM_RAYS];

static bool horWallTouch, vertWallTouch;
static float horWallTouchX, horWallTouchY, vertWallTouchX, vertWallTouchY;
static int horWallCon, vertWallCon;

/**
 * horizontalIntersection - finds horizontal intersection with the wall
 * @rayAngle: current ray angle
 */
void horizontalIntersection(float rayAngle)
{
    float nextHorTouchX, nextHorTouchY, interceptX, interceptY, stepsX, stepsY;

    horWallTouch = false;
    horWallTouchX = horWallTouchY = horWallCon = 0;

    interceptY = floor(player.y / WALL) * WALL;
    interceptY += rayFacingDown(rayAngle) ? WALL : 0;

    interceptX = player.x + (interceptY - player.y) / tan(rayAngle);

    stepsY = WALL;
    stepsY *= rayFacingUp(rayAngle) ? -1 : 1;
    stepsX = WALL / tan(rayAngle);
    stepsX *= (rayFacingLeft(rayAngle) && stepsX > 0) ? -1 : 1;
    stepsX *= (rayFacingRight(rayAngle) && stepsX < 0) ? -1 : 1;
    nextHorTouchX = interceptX;
    nextHorTouchY = interceptY;

    while (isInMap(nextHorTouchX, nextHorTouchY))
    {
        float checkX = nextHorTouchX;
        float checkY = nextHorTouchY + (rayFacingUp(rayAngle) ? -1 : 0);

        if (DetectCollision(checkX, checkY))
        {
            horWallTouchX = nextHorTouchX;
            horWallTouchY = nextHorTouchY;
            horWallCon = getMapVal((int)floor(checkY / WALL), (int)floor(checkX / WALL));
            horWallTouch = true;
            break;
        }
        nextHorTouchX += stepsX;
        nextHorTouchY += stepsY;
    }
}

/**
 * verticalIntersection - finds the vertical intersection with the wall
 * @rayAngle: current ray angle
 */
void verticalIntersection(float rayAngle)
{
    float nextVerTouchX, nextVerTouchY, interceptX, interceptY, stepsX, stepsY;

    vertWallTouch = false;
    vertWallTouchX = vertWallTouchY = vertWallCon = 0;

    interceptX = floor(player.x / WALL) * WALL;
    interceptX += rayFacingRight(rayAngle) ? WALL : 0;
    interceptY = player.y + (interceptX - player.x) * tan(rayAngle);

    stepsX = WALL;
    stepsX *= rayFacingLeft(rayAngle) ? -1 : 1;
    stepsY = WALL * tan(rayAngle);
    stepsY *= (rayFacingUp(rayAngle) && stepsY > 0) ? -1 : 1;
    stepsY *= (rayFacingDown(rayAngle) && stepsY < 0) ? -1 : 1;
    nextVerTouchX = interceptX;
    nextVerTouchY = interceptY;

    while (isInMap(nextVerTouchX, nextVerTouchY))
    {
        float checkX = nextVerTouchX + (rayFacingLeft(rayAngle) ? -1 : 0);
        float checkY = nextVerTouchY;

        if (DetectCollision(checkX, checkY))
        {
            vertWallTouchX = nextVerTouchX;
            vertWallTouchY = nextVerTouchY;
            vertWallCon = getMapVal((int)floor(checkY / WALL), (int)floor(checkX / WALL));
            vertWallTouch = true;
            break;
        }
        nextVerTouchX += stepsX;
        nextVerTouchY += stepsY;
    }
}

/**
 * castRay - casts a single ray
 * @rayAngle: ray angle
 * @stripId: ray strip ID
 */
void castRay(float rayAngle, int stripId)
{
    float horTouchDist, vertTouchDist;

    rayAngle = remainder(rayAngle, TWO_PI);
    if (rayAngle < 0)
        rayAngle = TWO_PI + rayAngle;

    horizontalIntersection(rayAngle);
    verticalIntersection(rayAngle);

    horTouchDist = horWallTouch ? distanceBtwPoints(player.x, player.y, horWallTouchX, horWallTouchY) : FLT_MAX;
    vertTouchDist = vertWallTouch ? distanceBtwPoints(player.x, player.y, vertWallTouchX, vertWallTouchY) : FLT_MAX;

    if (vertTouchDist < horTouchDist)
    {
        rays[stripId].distance = vertTouchDist;
        rays[stripId].wallHitX = vertWallTouchX;
        rays[stripId].wallHitY = vertWallTouchY;
        rays[stripId].hitContent = vertWallCon;
        rays[stripId].hitVertical = true;
        rays[stripId].rayAngle = rayAngle;
    }
    else
    {
        rays[stripId].distance = horTouchDist;
        rays[stripId].wallHitX = horWallTouchX;
        rays[stripId].wallHitY = horWallTouchY;
        rays[stripId].hitContent = horWallCon;
        rays[stripId].hitVertical = false;
        rays[stripId].rayAngle = rayAngle;
    }
}

/**
 * castAllRays - casts all rays
 */
void castAllRays(void)
{
    int column;

    for (column = 0; column < NUM_RAYS; column++)
    {
        float rayAngle = player.rotationAngle + atan((column - NUM_RAYS / 2) / PROJECTION_PLANE);
        castRay(rayAngle, column);
    }
}

/**
 * renderRays - renders rays
 */
void renderRays(void)
{
    int k;

    for (k = 0; k < NUM_RAYS; k += 50)
    {
        drawLine(player.x * SMALLMAP_SCALE_FACTOR,
                 player.y * SMALLMAP_SCALE_FACTOR,
                 rays[k].wallHitX * SMALLMAP_SCALE_FACTOR,
                 rays[k].wallHitY * SMALLMAP_SCALE_FACTOR,
                 0xFF0000FF);
    }
}