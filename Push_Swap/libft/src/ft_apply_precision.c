/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 19:41:57 by lalves            #+#    #+#             */
/*   Updated: 2016/11/11 17:31:05 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

wchar_t	*apply_precision_ls(wchar_t *str, int precision)
{
	int		i;
	wchar_t	*new;

	i = 0;
	if (precision == -42)
		new = L"";
	else
	{
		new = (wchar_t*)malloc(sizeof(wchar_t) * precision + 1);
		if (!new)
			ft_error("malloc");
		while (precision >= ft_wcharlen(str[i]))
		{
			new[i] = str[i];
			precision -= ft_wcharlen(str[i]);
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}

char	*apply_precision_neg(char *str, int i)
{
	char *new;
	char *tmp;

	new = ft_strnew_c((size_t)i, '0');
	tmp = str;
	str[0] = '0';
	str = ft_strjoin(new, str);
	str[0] = '-';
	ft_strdel(&new);
	ft_strdel(&tmp);
	return (str);
}

char	*apply_precision(char *str, int i)
{
	char *new;
	char *tmp;

	new = ft_strnew_c((size_t)i, '0');
	tmp = str;
	str = ft_strjoin(new, str);
	ft_strdel(&new);
	ft_strdel(&tmp);
	return (str);
}

char	*apply_precision_s(char *str, t_flags *data)
{
	char *tmp;

	if (data->precision == -42)
	{
		tmp = ft_strdup(str);
		tmp[0] = '\0';
		return (tmp);
	}
	else
	{
		tmp = ft_strdup(str);
		tmp[data->precision] = '\0';
		return (tmp);
	}
}
