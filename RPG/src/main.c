/*
** EPITECH PROJECT, 2021
** main
** File description:
** my_defender
*/

#include "my_rpg.h"

void print_rules_ext(void)
{
    my_putstr("In the game there are enemies and you have to kill it");
    my_putstr(" before there arrive at the end of the route.\n");
    my_putstr("To kill it you can put turret in the emplacement");
    my_putstr(" if you have the money.\n");
    my_putstr("If you kill it the enemy become more strong.\n");
    my_putstr("After you kill enemy there give you money.\n");
    my_putstr("You can upgrade your turret, ");
    my_putstr("for that you have to click on the turret");
    my_putstr(" and select the circule.\n");
    my_putstr("You can also remove the turret and change it.\n");
    my_putstr("\nGood luck.\n\n");
    return;
}

void print_rules(void)
{
    my_putstr("\nRules :\n\n");
    my_putstr("To play at this game you have to now this : \n\n");
    my_putstr("To launch the game you can to this command.\n");
    my_putstr("./my_defender\n\n");
    my_putstr("You can do this command for print rules :\n\n");
    my_putstr("./my_defender -h\n\n");
    my_putstr("In the menu you have three buttons : \n");
    my_putstr("Play, to launch the game but you can't ");
    my_putstr("play if you have not select a map.\n");
    my_putstr("Map to select your map, but desert don't fonction.\n");
    my_putstr("Quit to quit the game.\n");
    print_rules_ext();
    return;
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        print_rules();
    else {
        initialization();
    }
    return 0;
}
