/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 01:59:57 by lalves            #+#    #+#             */
/*   Updated: 2016/11/10 20:43:30 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	get_length(const char *restrict format, t_flags *data, int *i)
{
	if (format[*i] == 'h' && format[*i + 1] == 'h')
	{
		data->length = 1;
		(*i)++;
	}
	else if (format[*i] == 'h')
		data->length = 2;
	else if (format[*i] == 'l' && format[*i + 1] == 'l')
	{
		data->length = 3;
		(*i)++;
	}
	else if (format[*i] == 'l')
		data->length = 4;
	else if (format[*i] == 'j')
		data->length = 5;
	else if (format[*i] == 'z')
		data->length = 6;
	(*i)++;
}

static void	get_precision(const char *restrict format, t_flags *data, int *i)
{
	(*i)++;
	if (format[*i] <= '9' && format[*i] >= '0')
	{
		data->precision = ft_atoi(&format[*i]);
		if (data->precision == 0)
			data->precision = -42;
		while (format[*i] <= '9' && format[*i] >= '0')
			(*i)++;
	}
	else
		data->precision = -42;
	data->zero = 0;
}

static void	get_width(const char *restrict format, t_flags *data, int *i)
{
	data->width = ft_atoi(&format[*i]);
	while (format[*i] <= '9' && format[*i] >= '0')
		(*i)++;
}

static void	get_attributes(const char *restrict format, t_flags *data, int *i)
{
	if (format[*i] == '#')
		data->sharp = 1;
	if (format[*i] == '0')
	{
		data->save = 1;
		if (!data->minus)
			data->zero = 1;
	}
	if (format[*i] == '-')
	{
		data->minus = 1;
		if (data->zero)
			data->zero = 0;
	}
	if (format[*i] == '+')
		data->plus = 1;
	if (format[*i] == ' ' && !data->plus)
		data->space = 1;
}

int			get_flags(va_list *ap, const char *restrict format,
			t_flags *data, int *i)
{
	while (format[*i] == '#' || format[*i] == '0' || format[*i] == '-' ||
		format[*i] == '+' || format[*i] == ' ')
	{
		get_attributes(format, data, i);
		(*i)++;
	}
	if (format[*i] >= '1' && format[*i] <= '9')
		get_width(format, data, i);
	if (format[*i] == '.')
		get_precision(format, data, i);
	if (format[*i] == 'h' || format[*i] == 'l' ||
		format[*i] == 'j' || format[*i] == 'z')
		get_length(format, data, i);
	return (get_conv(ap, format, data, i));
}
