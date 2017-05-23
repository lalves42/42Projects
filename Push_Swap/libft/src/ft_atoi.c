/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:51:57 by lalves            #+#    #+#             */
/*   Updated: 2016/10/16 20:34:50 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_atoi(const char *str)
{
	int	convert;
	int	nb;
	int i;

	i = 0;
	convert = 1;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\f')
		i++;
	if (ft_isdigit(str[i]) == 0 && ft_isdigit(str[i + 1]) == 0)
		return (0);
	if (str[i] == '-')
	{
		convert = -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	return (nb * convert);
}
