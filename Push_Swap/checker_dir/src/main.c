/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:53:31 by lalves            #+#    #+#             */
/*   Updated: 2016/12/22 20:22:05 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

static int		check_sort_tab(t_stack *stack, int size)
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

static void		read_command(t_stack *stack, int size)
{
	char	*line;
	int		stack_size;
	int		ret;

	init_stack_b(stack, size);
	stack_size = 0;
	if (stack->flag == 1)
		print_stacks(stack, size, stack_size, "");
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (!ft_strcmp(line, ""))
			break ;
		if (apply_command(stack, size, &stack_size, line) == -1)
			error_fn4(stack, line);
		if (stack->flag == 1)
			print_stacks(stack, size, stack_size, line);
		ft_strdel(&line);
	}
	if (ret == -1)
		error_fn5("read", stack);
	ft_memdel((void**)&stack->b);
	if (check_sort_tab(stack, size) == -1 || stack_size)
		ft_putendl("KO");
	else
		ft_putendl("OK");
}

static void		init_struct(t_stack **stack, char *tmp, int ac, int f)
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
	(*stack)->flag = f;
	(*stack)->count = 0;
	(*stack)->a = NULL;
	(*stack)->b = NULL;
}

int				main(int ac, char **av)
{
	t_stack	*stack;
	char	*tmp;
	int		size;
	int		f;

	f = 0;
	if (ac < 2)
		return (0);
	if (ac == 2)
		tmp = av[1];
	if (ac > 2)
		tmp = get_string(ac, av);
	f = get_flag(tmp);
	check_string(tmp, ac, f);
	init_struct(&stack, tmp, ac, f);
	if (f)
		tmp = &tmp[3];
	size = get_tab(tmp, stack, f);
	read_command(stack, size);
	if (f == 2)
		print_last(stack, size);
	if (f == 3)
		print_num_cmd(stack);
	free_stack(stack);
	return (0);
}
