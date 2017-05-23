/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:48:30 by lalves            #+#    #+#             */
/*   Updated: 2016/11/11 17:51:34 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static uintmax_t	get_unsigned_arg(va_list *ap, int length)
{
	if (length)
	{
		if (length == 1)
			return ((uintmax_t)(unsigned char)va_arg(*ap, unsigned int));
		if (length == 2)
			return ((uintmax_t)(unsigned short)va_arg(*ap, unsigned int));
		if (length == 3)
			return ((uintmax_t)va_arg(*ap, unsigned long long));
		if (length == 4)
			return ((uintmax_t)va_arg(*ap, unsigned long));
		if (length == 5)
			return (va_arg(*ap, uintmax_t));
		if (length == 6)
			return ((uintmax_t)va_arg(*ap, size_t));
	}
	return ((uintmax_t)va_arg(*ap, unsigned int));
}

static int			convert_unsigned_0(t_flags *data, char c)
{
	char	*str;
	int		ret;

	str = NULL;
	ret = 0;
	if (data->width)
	{
		str = ft_strnew_c(data->width, ' ');
		if (data->sharp)
		{
			ret = data->minus ? 0 : data->width - 1;
			str[ret] = '0';
		}
		ret = ft_strlen(str);
		ft_putstr(str);
		ft_strdel(&str);
		return (ret);
	}
	else if (data->sharp && (c == 'o' || c == 'O'))
	{
		ft_putchar('0');
		return (1);
	}
	return (0);
}

static char			*convert_unsigned_helper(char *str, char c)
{
	char *tmp;

	tmp = str;
	if ((c == 'o' || c == 'O') && str[0] != '0')
	{
		str = ft_strjoin("0", str);
		ft_strdel(&tmp);
	}
	else if ((c == 'x' || c == 'X'))
	{
		str = ft_strjoin("0x", str);
		ft_strdel(&tmp);
	}
	return (str);
}

int					convert_unsigned(va_list *ap, t_flags *data, int *i, char c)
{
	uintmax_t	arg;
	char		*str;
	int			ret;

	(*i)++;
	arg = get_unsigned_arg(ap, data->length);
	if (data->precision == -42 && !arg)
		return (convert_unsigned_0(data, c));
	str = ft_itoa_base_printf(arg, c);
	if (data->sharp && data->zero && data->width - 2 >
		(int)ft_strlen(str) && !data->precision)
		str = apply_precision(str, data->width - 2 - ft_strlen(str));
	if (data->precision > (int)ft_strlen(str))
		str = apply_precision(str, data->precision - ft_strlen(str));
	if (data->sharp && arg)
		str = convert_unsigned_helper(str, c);
	if (data->width > (int)ft_strlen(str))
		str = apply_width(str, data, data->width - ft_strlen(str));
	if (c == 'X')
		ft_strmaj(str);
	ft_putstr(str);
	ret = ft_strlen(str);
	ft_strdel(&str);
	return (ret);
}
