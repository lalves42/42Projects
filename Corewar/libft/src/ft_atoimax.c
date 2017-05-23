/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoimax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 20:40:01 by tdefresn          #+#    #+#             */
/*   Updated: 2016/05/26 20:41:13 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifdef DEBUG

intmax_t		ft_atoimax(char const *str)
{
	int			sign;
	intmax_t	r;

	if (!str)
	{
		ERROR_PARAM("ft_atoimax");
		return (0);
	}
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
	while (ft_isdigit(*str))
	{
		r *= 10;
		r += (*str++ - '0');
	}
	return (r * sign);
}

#else

intmax_t		ft_atoimax(char const *str)
{
	int			sign;
	intmax_t	r;

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
	while (ft_isdigit(*str))
	{
		r *= 10;
		r += (*str - '0');
		str++;
	}
	return (r * sign);
}
#endif
