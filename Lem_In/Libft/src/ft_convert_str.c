/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:47:55 by lalves            #+#    #+#             */
/*   Updated: 2016/11/10 15:48:18 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	convert_null(void)
{
	ft_putstr("(null)");
	return (6);
}

static int	convert_s_helper(char *str, t_flags *data)
{
	char	*tmp;
	int		ret;

	tmp = apply_precision_s(str, data);
	if (data->width > (int)ft_strlen(tmp))
	{
		str = tmp;
		tmp = apply_width_s(tmp, data);
		ft_strdel(&str);
	}
	ft_putstr(tmp);
	ret = ft_strlen(tmp);
	ft_strdel(&tmp);
	return (ret);
}

int			convert_s(va_list *ap, t_flags *data, int *i)
{
	char	*str;
	char	*tmp;
	int		ret;

	str = va_arg(*ap, char*);
	(*i)++;
	if (!str)
		return (convert_null());
	if (data->precision && (data->precision == -42 ||
		data->precision < (int)ft_strlen(str)))
		return (convert_s_helper(str, data));
	if (data->width > (int)ft_strlen(str))
	{
		tmp = apply_width_s(str, data);
		ft_putstr(tmp);
		ret = ft_strlen(tmp);
		ft_strdel(&tmp);
		return (ret);
	}
	ft_putstr(str);
	return (ft_strlen(str));
}
