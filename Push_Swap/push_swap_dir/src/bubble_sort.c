/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:34:06 by lalves            #+#    #+#             */
/*   Updated: 2016/11/16 16:34:48 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	clear_stack_b(t_stack *stack, int size, int *stack_size)
{
	while (*stack_size)
		apply_command(stack, size, stack_size, "pa");
}

static void	push_smallest(t_stack *stack, int size, int *stack_size, int idx)
{
	if (idx < (size - *stack_size - idx))
	{
		while (idx)
		{
			apply_command(stack, size, stack_size, "ra");
			idx--;
		}
	}
	else
	{
		idx = size - *stack_size - idx;
		while (idx)
		{
			apply_command(stack, size, stack_size, "rra");
			idx--;
		}
	}
	if (check_sort_tab(stack, size - *stack_size) == -1)
	{
		apply_command(stack, size, stack_size, "pb");
		find_smallest(stack, size, stack_size);
	}
}

void		find_smallest(t_stack *stack, int size, int *stack_size)
{
	int idx;
	int i;

	idx = 0;
	i = 0;
	if (stack->a[0] > stack->a[1] && (size - *stack_size) > 1)
		apply_command(stack, size, stack_size, "sa");
	while (i < (size - *stack_size))
	{
		if (stack->a[i] < stack->a[idx])
			idx = i;
		i++;
	}
	if (idx == 1)
	{
		apply_command(stack, size, stack_size, "sa");
		if (check_sort_tab(stack, size - *stack_size) == -1)
		{
			apply_command(stack, size, stack_size, "pb");
			find_smallest(stack, size, stack_size);
		}
	}
	else
		push_smallest(stack, size, stack_size, idx);
}

void		bubble_sort(t_stack *stack, int size)
{
	int stack_size;

	stack_size = 0;
	find_smallest(stack, size, &stack_size);
	if (stack_size)
		clear_stack_b(stack, size, &stack_size);
}
