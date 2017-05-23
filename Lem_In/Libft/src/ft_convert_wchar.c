/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_wchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:48:56 by lalves            #+#    #+#             */
/*   Updated: 2016/11/11 15:56:13 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		convert_cmaj(va_list *ap, t_flags *data, int *i)
{
	wint_t	c;
	int		ret;

	c = va_arg(*ap, wint_t);
	ret = 0;
	(*i)++;
	if (c < 0 || c > 1114111 || (c >= 55296 && c <= 57343))
		return (-1);
	if (data->width > (ret = ft_wcharlen(c)))
	{
		if (data->minus)
			ft_putwchar(c);
		while (data->width > ret)
		{
			data->zero ? ft_putchar('0') : ft_putchar(' ');
			ret++;
		}
		if (!data->minus)
			ft_putwchar(c);
		return (ret);
	}
	return (ft_putwchar(c));
}
