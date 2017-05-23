/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 00:12:15 by lalves            #+#    #+#             */
/*   Updated: 2016/11/22 00:43:43 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void	print_num_cmd(t_stack *stack)
{
	ft_printf("\nNombre de coups : %i\n", stack->count);
}

void	print_last(t_stack *stack, int size)
{
	int idx;

	idx = 0;
	ft_printf("\t\033[31mA\033[0m\n\n");
	while (idx < size)
	{
		ft_printf("\t%i\n", stack->a[idx]);
		idx++;
	}
	ft_putchar('\n');
}

void	print_stacks(t_stack *stack, int size, int stack_size, char *cmd)
{
	int idx;

	idx = 0;
	ft_printf("\033[31m%s\033[0m", cmd);
	ft_printf("\t\033[31mA\033[0m\t\033[31mB\033[0m\n\n");
	while (idx < size && idx < (size - stack_size) && idx < stack_size)
	{
		ft_printf("\t%i\t%i\n", stack->a[idx], stack->b[idx]);
		idx++;
	}
	while (idx < (size - stack_size))
	{
		ft_printf("\t%i\t.\n", stack->a[idx]);
		idx++;
	}
	while (idx < stack_size)
	{
		ft_printf("\t.\t%i\n", stack->b[idx]);
		idx++;
	}
	ft_putchar('\n');
}

int		get_flag(char *str)
{
	if (ft_strlen(str) > 2 && str[0] == '-')
	{
		if (str[1] == 'v')
			return (1);
		if (str[1] == 'e')
			return (2);
		if (str[1] == 'c')
			return (3);
	}
	return (0);
}
