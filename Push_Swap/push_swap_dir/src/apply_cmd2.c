/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_cmd2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:53:13 by lalves            #+#    #+#             */
/*   Updated: 2016/12/22 19:30:33 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		apply_rr(int *tab, int *stack, int size, int *stack_size)
{
	apply_ra(tab, size, stack_size);
	apply_rb(stack, stack_size);
	return (0);
}

int		apply_rb(int *stack, int *stack_size)
{
	int idx;
	int tmp;

	idx = 0;
	tmp = stack[idx];
	if (*stack_size > 1)
	{
		while (idx < (*stack_size - 1))
		{
			stack[idx] = stack[idx + 1];
			idx++;
		}
		stack[idx] = tmp;
	}
	return (0);
}

int		apply_ra(int *tab, int size, int *stack_size)
{
	int idx;
	int tmp;

	idx = 0;
	tmp = tab[idx];
	if ((size - *stack_size) > 1)
	{
		while (idx < (size - *stack_size - 1))
		{
			tab[idx] = tab[idx + 1];
			idx++;
		}
		tab[idx] = tmp;
	}
	return (0);
}
