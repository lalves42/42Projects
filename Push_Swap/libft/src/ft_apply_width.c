/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 20:39:26 by lalves            #+#    #+#             */
/*   Updated: 2016/11/10 17:42:32 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	apply_width_helper(char *str, int i)
{
	str[0] = '-';
	str[i] = '0';
}

char		*apply_width(char *str, t_flags *data, int i)
{
	char *tmp;
	char *new;

	if ((data->plus || data->space) && str[0] != '-' && data->zero)
		i--;
	new = data->zero ? ft_strnew_c((size_t)i, '0') :
	ft_strnew_c((size_t)i, ' ');
	tmp = str;
	str = data->minus ? ft_strjoin(str, new) : ft_strjoin(new, str);
	if (data->zero)
	{
		i = 0;
		while (str[i++])
		{
			if (str[i] == '-')
			{
				apply_width_helper(str, i);
				break ;
			}
		}
	}
	if (ft_strcmp(tmp, ""))
		ft_strdel(&tmp);
	ft_strdel(&new);
	return (str);
}

char		*apply_width_p(char *str, t_flags *data)
{
	int		i;
	char	*tmp;

	i = 0;
	if (data->zero)
		tmp = ft_strnew_c(data->width, '0');
	else
		tmp = ft_strnew_c(data->width, ' ');
	if (!data->minus && !data->zero)
		i = data->width - ft_strlen(str);
	ft_strcpy_printf(&tmp[i], str);
	return (tmp);
}

char		*apply_width_s(char *str, t_flags *data)
{
	int		i;
	char	*tmp;

	i = 0;
	if (data->zero)
		tmp = ft_strnew_c(data->width, '0');
	else
		tmp = ft_strnew_c(data->width, ' ');
	if (!data->minus)
		i = data->width - ft_strlen(str);
	ft_strcpy_printf(&tmp[i], str);
	return (tmp);
}
