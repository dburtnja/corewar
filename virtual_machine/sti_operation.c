//
// Created by Yevhen Yefimov on 6/1/17.
//

#include "vm.h"

void get_sti_func(t_car *car)
{
	car->op_tabble.nb_tours--;
}



void    do_sti_func(t_vm *main_struct, t_car *car)
{
	int map_p;

	map_p = car->pos + car->args[1].value + car->args[2].value;
	if (map_p > MEM_SIZE - 1 || map_p < 0)
		map_p = get_correct_ind(map_p);
	if (car->args[0].name == T_REG && car->args[0].value > 0 && car->args[0]
			.value <= REG_NUMBER && car->args_error)
	{
		main_struct->coord_for_put_int_on_map = map_p;
		put_int_on_map(main_struct, car->reg[car->args[0].value - 1],
					   main_struct->color + map_p, car->color);
	}
	else
	{
		car->op_tabble.opcode = 0;
		car->pos = car->pos + car->arg_size + 2;
		return ;
	}
	car->op_tabble.opcode = 0;
	car->pos = car->pos + car->arg_size + 2;
	fix_car_pos(car);
}