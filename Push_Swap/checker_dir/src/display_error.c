/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:53:48 by lalves            #+#    #+#             */
/*   Updated: 2016/11/14 23:27:33 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void	error_fn5(char *reason, t_stack *stack)
{
	ft_memdel((void**)&stack->a);
	if (stack->b)
		ft_memdel((void**)&stack->b);
	if (stack->arg > 2)
		ft_strdel(&(stack->str));
	ft_memdel((void**)&stack);
	ft_error(reason);
}

void	error_fn4(t_stack *stack, char *line)
{
	ft_strdel(&line);
	ft_memdel((void**)&stack->a);
	ft_memdel((void**)&stack->b);
	if (stack->arg > 2)
		ft_strdel(&(stack->str));
	ft_memdel((void**)&stack);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

void	error_fn3(char *reason, t_stack *stack)
{
	if (stack->a)
		ft_memdel((void**)&stack->a);
	if (stack->arg > 2)
		ft_strdel(&(stack->str));
	ft_memdel((void**)&stack);
	ft_error(reason);
}

void	error_fn2(t_stack *stack)
{
	if (stack->a)
		ft_memdel((void**)&stack->a);
	if (stack->arg > 2)
		ft_strdel(&(stack->str));
	ft_memdel((void**)&stack);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

void	error_fn(char *str, int ac)
{
	if (ac > 2)
		ft_strdel(&str);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}
