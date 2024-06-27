#include "../headers/header.h"

/**
 * distanceBtwPoints - calculates the distance between two points
 * @x1: x-coordinate of the first point
 * @y1: y-coordinate of the first point
 * @x2: x-coordinate of the second point
 * @y2: y-coordinate of the second point
 * Returns: the Euclidean distance between the points
 */
float distanceBtwPoints(float x1, float y1, float x2, float y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

/**
 * rayFacingDown - checks if the ray angle is facing downwards
 * @angle: current angle of the ray
 * Returns: true if the ray is facing down, false otherwise
 */
bool rayFacingDown(float angle)
{
    return (angle > 0 && angle < PI);
}

/**
 * rayFacingUp - checks if the ray angle is facing upwards
 * @angle: current angle of the ray
 * Returns: true if the ray is facing up, false otherwise
 */
bool rayFacingUp(float angle)
{
    return !rayFacingDown(angle);
}

/**
 * rayFacingRight - checks if the ray angle is facing right
 * @angle: current angle of the ray
 * Returns: true if the ray is facing right, false otherwise
 */
bool rayFacingRight(float angle)
{
    return (angle < 0.5 * PI || angle > 1.5 * PI);
}

/**
 * rayFacingLeft - checks if the ray angle is facing left
 * @angle: current angle of the ray
 * Returns: true if the ray is facing left, false otherwise
 */
bool rayFacingLeft(float angle)
{
    return !rayFacingRight(angle);
}