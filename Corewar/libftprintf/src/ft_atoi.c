/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 21:37:29 by tdefresn          #+#    #+#             */
/*   Updated: 2016/10/16 04:08:05 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v'
			|| c == '\f' || c == '\r' || c == ' ');
}

int				ft_atoi(char const *str)
{
	int		sign;
	int		r;

	r = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (str[0] == '-')
	{
		sign = -1;
		str++;
	}
	else if (str[0] == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		r *= 10;
		r += (*str - '0');
		str++;
	}
	return (r * sign);
}
