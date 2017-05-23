/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:55:38 by lalves            #+#    #+#             */
/*   Updated: 2016/12/22 20:02:48 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void		destack_b(t_stack *stack, int size, int *stack_size)
{
	int idx;

	while (*stack_size)
	{
		idx = 0;
		while (idx < *stack_size)
		{
			if (stack->b[idx] == stack->sort[size - *stack_size])
				break ;
			idx++;
		}
		if (idx < (*stack_size / 2))
		{
			while (stack->b[0] != stack->sort[size - *stack_size])
				apply_command(stack, size, stack_size, "rb");
		}
		else
		{
			while (stack->b[0] != stack->sort[size - *stack_size])
				apply_command(stack, size, stack_size, "rrb");
		}
		apply_command(stack, size, stack_size, "pa");
		apply_command(stack, size, stack_size, "ra");
	}
}

static int		check_higher(int *tab, int size, int *stack_size, int pivot)
{
	int i;

	i = 0;
	while (i < (size - *stack_size))
	{
		if (tab[i] > pivot)
			return (1);
		i++;
	}
	return (0);
}

static void		first_step(t_stack *stack, int size, int *stack_size, int pivot)
{
	while (check_higher(stack->a, size, stack_size, pivot) == 1)
	{
		if (stack->a[0] > pivot)
			apply_command(stack, size, stack_size, "pb");
		else
			apply_command(stack, size, stack_size, "ra");
	}
}

void			quick_sort(t_stack *stack, int size)
{
	int stack_size;
	int pivot;
	int i;

	stack_size = 0;
	i = 0;
	get_sort_tab(stack, size);
	while (check_sort_tab(stack, size) == -1)
	{
		if (size - stack_size == 2)
		{
			if (stack->a[0] > stack->a[1])
				apply_command(stack, size, &stack_size, "sa");
			break ;
		}
		i = size > 200 ? i + 40 : i + 17;
		if (i >= size)
			i = size - 1;
		pivot = stack->sort[size - i];
		first_step(stack, size, &stack_size, pivot);
	}
	destack_b(stack, size, &stack_size);
}
