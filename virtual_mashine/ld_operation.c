//
// Created by Yevhen Yefimov on 6/1/17.
//

#include "vm.h"

void get_ld_func(t_car *car)
{
    size_t buf;

    //car->data = ft_memdup(7, map, (*pos) + 1);
    car->c_for_op = 4;
    car->pos = car->pos + 7;
    ft_printf ("-> read LD intruction, data = %s\n");
}

void    do_ld_func(t_vm *main_struct, t_car *car)
{
    car->op_type = 0;
    ft_printf("LOAD HAX!!!!\n");
    car->data = NULL;
}
