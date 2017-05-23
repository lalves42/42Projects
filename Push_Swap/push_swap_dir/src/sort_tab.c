/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 00:46:59 by lalves            #+#    #+#             */
/*   Updated: 2016/11/22 00:47:23 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int		get_new_min(int *tab, int size, int prev)
{
	int i;
	int min;

	i = 0;
	while (i < size)
	{
		if (tab[i] > prev)
			min = tab[i];
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (tab[i] < min && tab[i] > prev)
			min = tab[i];
		i++;
	}
	return (min);
}

static int		get_min(int *tab, int size)
{
	int i;
	int min;

	i = 0;
	min = tab[i];
	while (i < size)
	{
		if (tab[i] < min)
			min = tab[i];
		i++;
	}
	return (min);
}

void			get_sort_tab(t_stack *stack, int size)
{
	int i;
	int min;

	stack->sort = (int*)malloc(sizeof(int) * size);
	if (!stack->sort)
		error_fn5("malloc", stack);
	i = 1;
	min = get_min(stack->a, size);
	stack->sort[0] = min;
	while (i < size)
	{
		stack->sort[i] = get_new_min(stack->a, size, stack->sort[i - 1]);
		i++;
	}
}
