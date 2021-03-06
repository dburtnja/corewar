/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 18:36:52 by dburtnja          #+#    #+#             */
/*   Updated: 2017/07/03 18:36:54 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	get_lld_func(t_car *car)
{
	car->op_tabble.nb_tours--;
}

void	do_lld_func(t_car *car)
{
	if (car->args[0].name == T_DIR && car->args[1].name == T_REG &&
		car->args[1].value > 0 && car->args[1].value <= REG_NUMBER &&
		car->args_error)
		car->reg[car->args[1].value - 1] = car->args[0].value;
	else if (car->args[0].name == T_IND && car->args[1].name == T_REG &&
		car->args[1].value > 0 && car->args[1].value <= REG_NUMBER &&
		car->args_error)
		car->reg[car->args[1].value - 1] = car->args[0].value;
	else
	{
		car->op_tabble.opcode = 0;
		if (car->args[0].name == 0 && car->args[1].name == 0)
			car->pos = car->pos + 2;
		else
			car->pos = car->pos + car->arg_size + 2;
		return ;
	}
	if (car->reg[car->args[1].value - 1] == 0 && car->carry == 0)
		car->carry = 1;
	else if (car->reg[car->args[1].value - 1] != 0 && car->carry == 1)
		car->carry = 0;
	car->op_tabble.opcode = 0;
	car->pos = car->pos + car->arg_size + 2;
	fix_car_pos(car);
}
