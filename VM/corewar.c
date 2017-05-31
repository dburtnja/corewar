//
// Created by Denys Burtnjak on 5/24/17.
//

#include "op.h"

void    show_map(char *map)
{
    int i;

    i = 0;
    while (i < MEM_SIZE * 2)
    {
        if (i % 128 == 0 && i != 0)
            write (1, "\n", 1);
        if (i % 2 == 0 && i % 128 != 0 && i != 0)
            write (1, " ", 1);
        write (1, &map[i], 1);
        i++;
    }
}

int get_flags(int argc, char **argv, char *map)
{
    return (argc - 1);
}

void    get_bots(int argc, char **argv, char *map, int n_bots)
{
    int     i;
    int     j;
    char    *bot;
    int     fd;
    int     n;

    n = 0;
    j = 1;
    while (j <= argc)
    {
        i = 0;
        if (argv[j] != NULL)
        {
            fd = open(argv[j], O_RDONLY);
            bot = put_bot_on_map(fd);
            while (bot[i] != '\0')
            {
                map[i + (MEM_SIZE * 2 / n_bots) * n] = bot[i];
                i++;
            }
            n++;
            close (fd);
            //ft_strdel(&bot);
        }
        j++;
    }
}

int main(int argc, char **argv)
{
	char	*map;
    int     n_bots;

	map = (char *)malloc(sizeof(char) * MEM_SIZE * 2);
	ft_bzero(map, MEM_SIZE * 2);
    n_bots = get_flags(argc, argv, map);
    get_bots(argc, argv, map, n_bots);

    //show_map(map);

    put_car(map, n_bots);
	return (0);
}