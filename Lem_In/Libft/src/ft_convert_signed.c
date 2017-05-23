/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_signed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:47:31 by lalves            #+#    #+#             */
/*   Updated: 2016/11/11 16:03:51 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static intmax_t	get_signed_arg(va_list *ap, int length)
{
	if (length)
	{
		if (length == 1)
			return ((intmax_t)(char)va_arg(*ap, int));
		if (length == 2)
			return ((intmax_t)(short)va_arg(*ap, int));
		if (length == 3)
			return ((intmax_t)va_arg(*ap, long long));
		if (length == 4)
			return ((intmax_t)va_arg(*ap, long));
		if (length == 5)
			return (va_arg(*ap, intmax_t));
		if (length == 6)
			return ((intmax_t)va_arg(*ap, ssize_t));
	}
	return ((intmax_t)va_arg(*ap, int));
}

static char		*convert_signed_helper(char *str, t_flags *data, intmax_t arg)
{
	char *tmp;

	if (data->precision > (int)ft_strlen(str) && arg >= 0)
		str = apply_precision(str, data->precision - ft_strlen(str));
	if (data->precision >= (int)ft_strlen(str) && arg < 0)
		str = apply_precision_neg(str, data->precision - ft_strlen(str) + 1);
	if (data->width > (int)ft_strlen(str) && data->zero)
		str = apply_width(str, data, data->width - ft_strlen(str));
	if ((data->plus || data->space) && arg >= 0)
	{
		tmp = str;
		str = (data->plus) ? ft_strjoin("+", str) : ft_strjoin(" ", str);
		if (ft_strcmp(tmp, ""))
			ft_strdel(&tmp);
	}
	return (str);
}

int				convert_signed(va_list *ap, t_flags *data, int *i)
{
	intmax_t		arg;
	int				ret;
	char			*str;

	arg = get_signed_arg(ap, data->length);
	if (data->precision == -42 && !arg)
		str = "";
	else
		str = ft_itoa(arg);
	str = convert_signed_helper(str, data, arg);
	if (data->width > (int)ft_strlen(str))
		str = apply_width(str, data, data->width - ft_strlen(str));
	ft_putstr(str);
	ret = ft_strlen(str);
	if (ft_strcmp(str, ""))
		ft_strdel(&str);
	(*i)++;
	return (ret);
}
