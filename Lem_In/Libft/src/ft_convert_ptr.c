/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:37:44 by lalves            #+#    #+#             */
/*   Updated: 2016/11/11 15:54:54 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	convert_p_helper(char *addr)
{
	int ret;

	ft_putstr(addr);
	ret = ft_strlen(addr);
	ft_strdel(&addr);
	return (ret);
}

int			convert_p(va_list *ap, t_flags *data, int *i)
{
	void	*ptr;
	char	*addr;

	ptr = va_arg(*ap, void*);
	if ((int)ptr == 0 && data->precision == -42)
		addr = ft_strjoin("0x", "");
	else
	{
		addr = ft_itoa_base_printf((long long int)ptr, 'x');
		if (data->precision > data->width &&
			data->precision > (int)ft_strlen(addr))
			addr = apply_precision(addr, data->precision - ft_strlen(addr));
		ptr = (void*)addr;
		addr = ft_strjoin("0x", addr);
		ft_memdel(&ptr);
	}
	if (data->width > (int)ft_strlen(addr))
	{
		ptr = (void*)addr;
		addr = apply_width_p(addr, data);
		ft_memdel(&ptr);
	}
	(*i)++;
	return (convert_p_helper(addr));
}
