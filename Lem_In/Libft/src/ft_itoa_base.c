/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 23:48:55 by lalves            #+#    #+#             */
/*   Updated: 2016/11/09 16:49:40 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		get_size(uintmax_t nb, int base)
{
	int i;

	i = 0;
	while (nb > 0)
	{
		nb = nb / base;
		i++;
	}
	return (i);
}

char			*ft_itoa_base(uintmax_t nb, int base)
{
	char		*str;
	int			size;
	uintmax_t	tmp;

	if (nb == 0)
		return (ft_strdup("0"));
	size = get_size(nb, base);
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	str[size] = '\0';
	size--;
	while (nb > 0)
	{
		tmp = nb % base;
		if (tmp > 9)
			str[size] = 'a' + tmp - 10;
		else
			str[size] = '0' + tmp;
		nb = nb / base;
		size--;
	}
	return (str);
}
