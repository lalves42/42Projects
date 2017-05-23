/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 23:48:55 by lalves            #+#    #+#             */
/*   Updated: 2016/11/09 21:36:36 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

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

static int		get_base(char c)
{
	if (c == 'x' || c == 'X')
		return (16);
	if (c == 'o' || c == 'O')
		return (8);
	if (c == 'u' || c == 'U')
		return (10);
	if (c == 'b' || c == 'B')
		return (2);
	return (10);
}

char			*ft_itoa_0(void)
{
	char *str;

	str = (char*)malloc(sizeof(char) * 2);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char			*ft_itoa_base_printf(uintmax_t nb, char c)
{
	char		*str;
	int			size;
	int			base;
	uintmax_t	tmp;

	if (nb == 0)
		return (ft_itoa_0());
	base = get_base(c);
	size = get_size(nb, base);
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	str[size] = '\0';
	size--;
	while (nb > 0)
	{
		tmp = nb % (uintmax_t)base;
		if (tmp > 9)
			str[size] = 'a' + tmp - 10;
		else
			str[size] = '0' + tmp;
		nb = nb / (uintmax_t)base;
		size--;
	}
	return (str);
}
