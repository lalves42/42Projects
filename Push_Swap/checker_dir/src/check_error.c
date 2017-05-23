/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:53:41 by lalves            #+#    #+#             */
/*   Updated: 2016/11/22 00:39:05 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

int			apply_command(t_stack *stack, int size, int *stack_size, char *cmd)
{
	stack->count++;
	if (!ft_strcmp(cmd, "sa"))
		return (apply_sa(stack->a, size, stack_size));
	if (!ft_strcmp(cmd, "sb"))
		return (apply_sb(stack->b, stack_size));
	if (!ft_strcmp(cmd, "ss"))
		return (apply_ss(stack->a, stack->b, size, stack_size));
	if (!ft_strcmp(cmd, "pa"))
		return (apply_pa(stack->a, stack->b, size, stack_size));
	if (!ft_strcmp(cmd, "pb"))
		return (apply_pb(stack->a, stack->b, size, stack_size));
	if (!ft_strcmp(cmd, "ra"))
		return (apply_ra(stack->a, size, stack_size));
	if (!ft_strcmp(cmd, "rb"))
		return (apply_rb(stack->b, stack_size));
	if (!ft_strcmp(cmd, "rr"))
		return (apply_rr(stack->a, stack->b, size, stack_size));
	if (!ft_strcmp(cmd, "rra"))
		return (apply_rra(stack->a, size, stack_size));
	if (!ft_strcmp(cmd, "rrb"))
		return (apply_rrb(stack->b, stack_size));
	if (!ft_strcmp(cmd, "rrr"))
		return (apply_rrr(stack->a, stack->b, size, stack_size));
	return (-1);
}

void		check_double(t_stack *stack, int size)
{
	int i;
	int j;

	i = 1;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (stack->a[j] == stack->a[i])
				error_fn2(stack);
			j++;
		}
		i++;
	}
}

static void	check_min_max(char *str, int neg, t_stack *stack)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (str[i] > '2' || str[i + 1] > '1' || str[i + 2] > '4')
		error_fn2(stack);
	if (str[i + 3] > '7' || str[i + 4] > '4' || str[i + 5] > '8')
		error_fn2(stack);
	if (str[i + 6] > '3' || str[i + 7] > '6' || str[i + 8] > '4')
		error_fn2(stack);
	if ((str[i + 9] > '7' && !neg) || (str[i + 9] > '8'))
		error_fn2(stack);
}

void		check_int(char *str, t_stack *stack)
{
	int i;
	int neg;

	i = 0;
	neg = 0;
	if (str[i] == '-')
	{
		i++;
		neg++;
	}
	while (str[i] && str[i] != ' ')
		i++;
	if (i > 11 || (i > 10 && !neg))
		error_fn2(stack);
	if ((i == 11 && neg) || (i == 10 && !neg))
		check_min_max(str, neg, stack);
}

void		check_string(char *s, int ac, int flag)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (flag && s[2] == ' ')
		i = 3;
	if (!ft_strcmp(s, "") || !s)
		error_fn(s, ac);
	if (s[i] == ' ')
		error_fn(s, ac);
	while (s[i])
	{
		if ((s[i] != ' ' && s[i + 1] == '-') || (s[i] == ' ' && !s[i + 1]))
			error_fn(s, ac);
		if ((s[i] == ' ' || s[i] == '-') && s[i + 1] == ' ')
			error_fn(s, ac);
		if ((s[i] < '0' || s[i] > '9') && s[i] != ' ' && s[i] != '-')
			error_fn(s, ac);
		if (s[i] >= '0' && s[i] <= '9')
			count++;
		i++;
	}
	if (!count)
		error_fn(s, ac);
}
