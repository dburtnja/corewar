//
// Created by Yevhen Yefimov on 5/27/17.
//

#include "vm.h"

void	fix_car_pos(t_car *car)
{
	int count;

	if (car->pos == MEM_SIZE)
		car->pos = 0;
	else
	{
		if (car->pos > MEM_SIZE - 1)
		{
			count = car->pos / MEM_SIZE;
			car->pos = car->pos % (count * (MEM_SIZE));
		}
		else if (car->pos < 0)
		{
			count = (car->pos / (-MEM_SIZE + 1)) + 1;
			car->pos = car->pos + count * (MEM_SIZE);
		}
	}
}


void    move_single_car(t_vm *main_struct, t_car *car)
{
	if (!car)
		return ;
    if (car->op_tabble.nb_tours == 0)
    {
        if (!car->op_tabble.command)
		{
			get_op_code(main_struct, car);
			if (!car->op_tabble.command)
			{
				car->pos++;
				fix_car_pos(car);

			}
			if (main_struct->map[car->pos] > 0 && main_struct->map[car->pos]
												  < 16)
				get_op_code(main_struct, car);

		}
        else if (car->op_tabble.command)
        {
            do_op_code(main_struct, car);
			fix_car_pos(car);
			//if (main_struct->map[car->pos] != 0)
            	get_op_code(main_struct, car);
			fix_car_pos(car);
        }
    }
    else
        car->op_tabble.nb_tours--;
}

void    move_all_car(t_vm *main_struct)
{
    t_player	**player;
    t_car		*car;
	int			i;

	i = main_struct->players_nbr;
	player = main_struct->players;
    while (i)
    {
        car = player[i - 1]->car;
        while (car)
        {
            move_single_car(main_struct, car);
			if (car->pos > MEM_SIZE - 1 || car->pos < -MEM_SIZE+1 || car->pos
					< 0)
				fix_car_pos(car);
            car = car->next;
        }
        i--;
    }
}