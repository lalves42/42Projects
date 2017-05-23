/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:52:56 by lalves            #+#    #+#             */
/*   Updated: 2016/12/22 19:29:56 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		apply_pb(int *tab, int *stack, int size, int *stack_size)
{
	int idx;

	idx = *stack_size;
	if ((size - *stack_size))
	{
		while (idx > 0)
		{
			stack[idx] = stack[idx - 1];
			idx--;
		}
		stack[0] = tab[0];
		(*stack_size)++;
		while (idx < (size - *stack_size))
		{
			tab[idx] = tab[idx + 1];
			idx++;
		}
	}
	return (0);
}

int		apply_pa(int *tab, int *stack, int size, int *stack_size)
{
	int idx;

	idx = size - *stack_size;
	if (*stack_size)
	{
		while (idx > 0)
		{
			tab[idx] = tab[idx - 1];
			idx--;
		}
		tab[0] = stack[0];
		(*stack_size)--;
		while (idx < *stack_size)
		{
			stack[idx] = stack[idx + 1];
			idx++;
		}
	}
	return (0);
}

int		apply_ss(int *tab, int *stack, int size, int *stack_size)
{
	apply_sa(tab, size, stack_size);
	apply_sb(stack, stack_size);
	return (0);
}

int		apply_sb(int *stack, int *stack_size)
{
	int tmp;

	tmp = stack[0];
	if (*stack_size > 1)
	{
		stack[0] = stack[1];
		stack[1] = tmp;
	}
	return (0);
}

int		apply_sa(int *tab, int size, int *stack_size)
{
	int tmp;

	tmp = tab[0];
	if ((size - *stack_size) > 1)
	{
		tab[0] = tab[1];
		tab[1] = tmp;
	}
	return (0);
}
