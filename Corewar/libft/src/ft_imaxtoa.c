/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imaxtoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 21:46:45 by tdefresn          #+#    #+#             */
/*   Updated: 2016/09/20 23:53:22 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_imaxtoa(intmax_t n)
{
	char			*str;
	size_t			sign;
	size_t			l;
	intmax_t		n_copy;

	sign = (n < 0);
	l = sign + 1;
	n_copy = n;
	while (n_copy /= 10)
		l++;
	if (!(str = ft_strnew(l)))
		return (NULL);
	str[l] = '\0';
	if (sign != 0)
		str[0] = '-';
	while (l-- > sign)
	{
		str[l] = (sign > 0) ? HEX_TABLE(-(n % 10)) : HEX_TABLE(n % 10);
		n /= 10;
	}
	return (str);
}
