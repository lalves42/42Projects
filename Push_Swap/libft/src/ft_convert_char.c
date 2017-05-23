/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:46:36 by lalves            #+#    #+#             */
/*   Updated: 2016/11/10 20:53:49 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		convert_c(va_list *ap, t_flags *data, int *i, unsigned char check)
{
	unsigned char	c;
	int				ret;

	c = (check == 'c') ? va_arg(*ap, int) : check;
	ret = 1;
	if (data->width > 1)
	{
		if (data->minus)
			ft_putchar(c);
		while (data->width > 1)
		{
			data->save ? ft_putchar('0') : ft_putchar(' ');
			(data->width)--;
			ret++;
		}
		if (!(data->minus))
			ft_putchar(c);
	}
	else
		ft_putchar(c);
	(*i)++;
	return (ret);
}
