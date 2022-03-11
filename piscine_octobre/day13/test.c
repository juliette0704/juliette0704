/*
** EPITECH PROJECT, 2021
** test.c
** File description:
** task
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include "struct.h"
#include <SFML/Graphics.h>
#include <stddef.h>


sfRenderWindow *createMyWindow(unsigned int width, unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;
    
    video_mode.width = width;
    video_mode.height = height;
    video.mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "my window", sfDefaultStyle, NULL);
    return (window);
    /*sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window;
    window = sfRenderWindow_create(mode, "My awesome window", sfResize | sfClose, NULL);
    if(!window)
        return 0;
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_display(window);
    }*/
}

int main()
{
    sfRenderWindow *window;
    t_framebuffer *fb;
    sfTexture *texture;
    sfSprite *sprite;

    window = createMyWindow(800,800);
    fb = framebuffer_create(800, 800);
    texture = sfTexture_create(800, 800);
    sprite = sfSprite_create();
    while (sfRenderWindow_isOpen(window)) {
        framebuffer_drawsquare(fb, 200, &sfRed);
        sfTexture_updateFromePixels(texture, fb->pixels, 800, 800, 0, 0);
        sfRenderWindow_display(window);
        sfSprite_setTexture(sprite, texture, sfFalse);
        sfRenderWindow_drawSprite(window, sprite, NULL);

    }
    sfRenderWindow_destroy(window);
    framebuffer_destroy(fb);
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
    return 0;
}
