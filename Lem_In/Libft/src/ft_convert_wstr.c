/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_wstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:49:08 by lalves            #+#    #+#             */
/*   Updated: 2016/11/11 17:38:08 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int		convert_null(void)
{
	ft_putstr("(null)");
	return (6);
}

static int		convert_smaj_helper(wchar_t *str, t_flags *data, int ret)
{
	wchar_t *tmp;

	tmp = str;
	if (data->minus)
		ft_putwstr(str);
	while (data->width > ret)
	{
		data->zero ? ft_putchar('0') : ft_putchar(' ');
		ret++;
	}
	if (!data->minus)
		ft_putwstr(str);
	if (data->precision > 0)
		ft_memdel((void**)&tmp);
	return (ret);
}

int				convert_smaj(va_list *ap, t_flags *data, int *i)
{
	wchar_t *str;
	int		ret;
	wchar_t *tmp;

	str = va_arg(*ap, wchar_t*);
	ret = 0;
	(*i)++;
	if (!str)
		return (convert_null());
	if (data->precision)
		str = apply_precision_ls(str, data->precision);
	tmp = str;
	if (data->width > (ret = ft_wstrlen(str)))
		return (convert_smaj_helper(str, data, ret));
	ret = ft_putwstr(str);
	if (data->precision > 0)
		ft_memdel((void**)&tmp);
	return (ret);
}
