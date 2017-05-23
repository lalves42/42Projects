/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:53:31 by lalves            #+#    #+#             */
/*   Updated: 2016/12/22 19:32:11 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int				check_sort_tab(t_stack *stack, int size)
{
	int i;

	i = 0;
	while (i <= size - 2)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (-1);
		i++;
	}
	return (0);
}

static void		init_stack_b(t_stack *stack, int size)
{
	int i;

	i = 0;
	stack->b = (int*)malloc(sizeof(int) * size);
	if (!stack->b)
		error_fn5("malloc", stack);
	while (i < size)
	{
		stack->b[i] = 0;
		i++;
	}
}

static void		init_struct(t_stack **stack, char *tmp, int ac)
{
	*stack = (t_stack*)malloc(sizeof(t_stack));
	if (!(*stack))
	{
		if (ac > 2)
			ft_strdel(&tmp);
		ft_error("malloc");
	}
	(*stack)->str = tmp;
	(*stack)->arg = ac;
	(*stack)->a = NULL;
	(*stack)->b = NULL;
	(*stack)->sort = NULL;
}

int				main(int argc, char **argv)
{
	t_stack	*stack;
	char	*tmp;
	int		size;

	if (argc < 2)
		error_fn(argv[0], 0);
	if (argc == 2)
		tmp = argv[1];
	if (argc > 2)
		tmp = get_string(argc, argv);
	check_string(tmp, argc);
	init_struct(&stack, tmp, argc);
	size = get_tab(tmp, stack);
	init_stack_b(stack, size);
	if ((size == 1 || check_sort_tab(stack, size) == 0))
		ft_putstr("");
	else
		size > 80 ? quick_sort(stack, size) : bubble_sort(stack, size);
	free_stack(stack);
	return (0);
}
