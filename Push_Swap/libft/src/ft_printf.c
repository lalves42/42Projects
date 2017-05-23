/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 23:53:46 by lalves            #+#    #+#             */
/*   Updated: 2016/11/10 20:41:42 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	init_data(t_flags **data)
{
	*data = (t_flags*)malloc(sizeof(t_flags));
	if (!(*data))
		ft_error("malloc");
	(*data)->sharp = 0;
	(*data)->zero = 0;
	(*data)->minus = 0;
	(*data)->plus = 0;
	(*data)->space = 0;
	(*data)->width = 0;
	(*data)->precision = 0;
	(*data)->length = 0;
	(*data)->save = 0;
}

static void	ft_printf_helper(char c, int *ret, int *i)
{
	write(1, &c, 1);
	(*ret)++;
	(*i)++;
}

int			ft_printf(const char *restrict format, ...)
{
	int		i;
	int		ret;
	int		fn_ret;
	va_list	ap;
	t_flags	*data;

	i = 0;
	ret = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			init_data(&data);
			if ((fn_ret = get_flags(&ap, format, data, &i)) < 0)
				return (-1);
			ret += fn_ret;
			ft_memdel((void**)&data);
		}
		else if (format[i])
			ft_printf_helper(format[i], &ret, &i);
	}
	va_end(ap);
	return (ret);
}
