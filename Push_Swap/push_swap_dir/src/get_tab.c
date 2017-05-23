/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:54:05 by lalves            #+#    #+#             */
/*   Updated: 2016/11/15 20:11:46 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void		go_to_next(char **str)
{
	if (**str == '-')
		(*str)++;
	while (**str >= '0' && **str <= '9')
		(*str)++;
	if (**str)
		(*str)++;
}

static void		fill_tab(t_stack *stack, char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		check_int(str, stack);
		stack->a[i] = ft_atoi(str);
		i++;
		go_to_next(&str);
	}
}

static void		init_stack_a(t_stack *stack, int size)
{
	int i;

	i = 0;
	stack->a = (int*)malloc(sizeof(int) * size);
	if (!(stack->a))
		error_fn3("malloc", stack);
	while (i < size)
	{
		stack->a[i] = 0;
		i++;
	}
}

static int		count_int(char *str)
{
	int count;

	count = 1;
	while (*str)
	{
		if (*str == ' ')
			count++;
		str++;
	}
	return (count);
}

int				get_tab(char *str, t_stack *stack)
{
	int size;

	size = count_int(str);
	init_stack_a(stack, size);
	fill_tab(stack, str);
	if (size > 1)
		check_double(stack, size);
	return (size);
}
