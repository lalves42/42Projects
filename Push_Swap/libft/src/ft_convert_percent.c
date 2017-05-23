/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:46:59 by lalves            #+#    #+#             */
/*   Updated: 2016/11/10 20:53:21 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		convert_percent(t_flags *data, int *i)
{
	int ret;

	ret = 1;
	if (data->width > 1)
	{
		if (data->minus)
			ft_putchar('%');
		while (data->width > 1)
		{
			data->save ? ft_putchar('0') : ft_putchar(' ');
			(data->width)--;
			ret++;
		}
		if (!(data->minus))
			ft_putchar('%');
	}
	else
		ft_putchar('%');
	(*i)++;
	return (ret);
}
