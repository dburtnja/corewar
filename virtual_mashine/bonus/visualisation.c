//
// Created by denys on 13.06.17.
//

#include "../vm.h"
#include "visualisation.h"
#include <time.h>

int 	i = 0;


void	get_input(t_vm *main_struct)
{
	char	buf[2];

	if (ft_kbhit() && fgets(buf, 2, stdin))
	{
		if (buf[0] == '+' && main_struct->time > 10)
			main_struct->time -= 10;
		if (buf[0] == '-' && main_struct->time < 9990)
			main_struct->time += 10;
	}
}

void	visualisation(t_vm *main_struct)
{
	long	time;

	//210 * 100000 50/c
	//    1/c
	time = 10000 * main_struct->time;
	get_input(main_struct);
	ft_putstr(CLEARE);
	ft_putstr(TO_BEGIN);
	printf("CYCLE = %10d PERIOD = %10d\n", main_struct->cycle, main_struct
		->round);
	//ft_putnbr(main_struct->time);
	if (main_struct->cycle % 50 == 0)
		i++;
//	ft_putnbr(i);
	//print_memory((unsigned char*)main_struct->map, MEM_SIZE);
	nanosleep((const struct timespec[]){{0, time}}, NULL);
}