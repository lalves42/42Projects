/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 07:41:50 by lalves            #+#    #+#             */
/*   Updated: 2017/02/21 07:43:53 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	before_space(char *str, int i)
{
	int count;

	count = 0;
	while (i >= 0)
	{
		if (!ft_isspace(str[i]))
			break ;
		else
			count++;
		i--;
	}
	return (count);
}

int	after_space(char *str, int i)
{
	int count;

	count = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			break ;
		else
			count++;
		i++;
	}
	return (count);
}
