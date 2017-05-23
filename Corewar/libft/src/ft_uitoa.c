/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 22:08:44 by tdefresn          #+#    #+#             */
/*   Updated: 2016/09/20 23:52:04 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_uitoa(uintmax_t n)
{
	char			*str;
	size_t			l;
	uintmax_t		n_copy;

	l = 1;
	n_copy = n;
	while (n_copy /= 10)
		l++;
	if (!(str = ft_strnew(l + 1)))
		return (NULL);
	str[l] = '\0';
	while (l-- > 0)
	{
		str[l] = HEX_TABLE(n % 10);
		n /= 10;
	}
	return (str);
}
