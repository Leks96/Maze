#include "../headers/header.h"

static const char *textureFile[NUM_TEXT] = {
    "./images/redbrick.png",
    "./images/wood.png",
    "./images/purplestone.png",
    "./images/mossy.png",
    "./images/greystone.png",
    "./images/greenlight.png",
    "./images/colorstone.png",
    "./images/bluestone.png",
};

texture_t wallTextures[NUM_TEXT];

/**
 * wallTexturesready - Load wall textures into their place.
 */
void wallTexturesready(void)
{
    int k;

    for (k = 0; k < NUM_TEXT; k++)
    {
        upng_t *upng;

        upng = upng_new_from_file(textureFile[k]);

        if (upng != NULL)
        {
            upng_decode(upng);

            if (upng_get_error(upng) == UPNG_EOK)
            {
                wallTextures[k].upngTexture = upng;
                wallTextures[k].width = upng_get_width(upng);
                wallTextures[k].height = upng_get_height(upng);
                wallTextures[k].texture_buffer = (color_t *)upng_get_buffer(upng);
            }
            else {
                printf("Error decoding texture %d\n", k);
                upng_free(upng);
            }
        }
        else {
            printf("Error loading texture %d\n", k);
        }
    }
}

/**
 * freeWallTextures - Free wall textures.
 */
void freeWallText(void)
{
    int k;

    for (k = 0; k < NUM_TEXT; k++)
    {
        if (wallTextures[k].upngTexture != NULL)
            upng_free(wallTextures[k].upngTexture);
    }
}