/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 18:07:36 by lalves            #+#    #+#             */
/*   Updated: 2016/11/15 18:08:45 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void	free_stack(t_stack *stack)
{
	ft_memdel((void**)&stack->a);
	if (stack->arg > 2)
		ft_strdel(&(stack->str));
	ft_memdel((void**)&stack);
}
