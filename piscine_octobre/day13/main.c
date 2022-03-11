/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** task
*/

#include <SFML/Graphics.h>


int main()
{
    sfEvent event;
    sfVideoMode mode = {800, 600, 32};
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
    }
}
