/*
** main
** File description:
** main
*/

#include "../my.h"

int main(int argc, char **argv)
{
    creator_t *button = init_button();
    if (argc != 1)
	    return 1;
    init_window(button);
    return 0;
}
