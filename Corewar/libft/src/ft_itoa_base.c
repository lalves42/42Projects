/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 00:57:09 by tdefresn          #+#    #+#             */
/*   Updated: 2016/10/03 08:28:50 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*to_base(uintmax_t value, size_t base)
{
	char		*str;
	size_t		l;
	uintmax_t	value_copy;

	l = 1;
	value_copy = value;
	while (value_copy /= base)
		l++;
	str = ft_strnew(sizeof(char) * l);
	str[l] = '\0';
	while (l > 0)
	{
		l--;
		str[l] = HEX_TABLE(value % base);
		value /= base;
	}
	return (str);
}

char			*ft_itoa_base(intmax_t value, int base)
{
	char	*str;

	str = NULL;
	if (value == 0)
		str = ft_strdup("0");
	else if (base < 2 || base > 16)
		str = NULL;
	else if (base == 10)
		str = ft_imaxtoa(value);
	else
		str = to_base((uintmax_t)value, base);
	return (str);
}
