/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_cmd3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:53:22 by lalves            #+#    #+#             */
/*   Updated: 2016/12/22 19:28:29 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

int		apply_rrr(int *tab, int *stack, int size, int *stack_size)
{
	apply_rra(tab, size, stack_size);
	apply_rrb(stack, stack_size);
	return (0);
}

int		apply_rrb(int *stack, int *stack_size)
{
	int idx;
	int tmp;

	idx = *stack_size - 1;
	tmp = stack[idx];
	if (*stack_size > 1)
	{
		while (idx > 0)
		{
			stack[idx] = stack[idx - 1];
			idx--;
		}
		stack[idx] = tmp;
	}
	return (0);
}

int		apply_rra(int *tab, int size, int *stack_size)
{
	int idx;
	int tmp;

	idx = size - *stack_size - 1;
	tmp = tab[idx];
	if ((size - *stack_size) > 1)
	{
		while (idx > 0)
		{
			tab[idx] = tab[idx - 1];
			idx--;
		}
		tab[idx] = tmp;
	}
	return (0);
}
