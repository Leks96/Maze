#include "../headers/header.h"

/**
 * drawRectangle - draw a rectangle
 * @x: x co-ord
 * @y: y co-ord
 * @width: rectangle width
 * @height: rectangle height
 * @color: pixel color
 */
void drawRectangle(int x, int y, int width, int height, color_t color)
{
	int i, j;

	for (i = x; i < (x + width); i++)
		for (j = y; j < (y + height); j++)
			drawPixel(i, j, color);
}

/**
 * drawLine - draw a line
 * @x0: x init co-ord
 * @y0: y init co-ord
 * @x1: x end co-ord
 * @y1: y end co-ord
 * @color: pixel color
 */
void drawLine(int x0, int y0, int x1, int y1, color_t color)
{
	float xInc, currX, yInc, currY;
	int i, longLength, Xd, Yd;

	Xd = (x1 - x0);
	Yd = (y1 - y0);
	longLength = abs(Xd) > abs(Yd) ? abs(Xd) : abs(Yd);

	xInc = Xd / (float)longLength;
	yInc = Yd / (float)longLength;
	currX = x0;
	currY = y0;

	for (i = 0; i <= longLength; i++)
	{
		drawPixel(round(currX), round(currY), color);
		currX += xInc;
		currY += yInc;
	}
}
