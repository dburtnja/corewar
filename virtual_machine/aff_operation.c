//
// Created by Yevhen Yefimov on 6/1/17.
//
#include "vm.h"

void get_aff_func(char *map, t_car *car)
{
	car->op_tabble.nb_tours--;
}

void    do_aff_func(t_vm *main_struct, t_car *car)
{
	int		reg_n;
	char 	print;

	if (main_struct->map[car->pos + 1] == 40)
	{
		reg_n = get_int_from_byte_code(main_struct->map + car->pos + 1);
		print = (char) (reg_n % 256);
		if (main_struct->f_aff)
			ft_printf("AFF OPERATION = %c\n", print);
		car->op_tabble.opcode = 0;
		car->pos = car->pos + T_REG + 2;
		fix_car_pos(car);
	}
	else
	{
		car->args_error= get_args_nd_value(car, main_struct);
		if (car->arg_size == 1)
			car->pos = car->pos + 2 + car->arg_size;
		else
			car->pos = car->pos + 2;
		fix_car_pos(car);
	}
}
