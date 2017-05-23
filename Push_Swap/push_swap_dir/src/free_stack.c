/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 18:07:36 by lalves            #+#    #+#             */
/*   Updated: 2016/11/21 17:41:36 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	free_stack(t_stack *stack)
{
	ft_memdel((void**)&stack->a);
	if (stack->sort)
		ft_memdel((void**)&stack->sort);
	if (stack->arg > 2)
		ft_strdel(&(stack->str));
	ft_memdel((void**)&stack);
}
