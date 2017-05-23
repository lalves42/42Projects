/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 19:12:52 by lalves            #+#    #+#             */
/*   Updated: 2016/11/14 16:11:46 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	get_conv(va_list *ap, const char *restrict format, t_flags *data, int *i)
{
	if (format[*i] == 'D' || format[*i] == 'O' || format[*i] == 'U')
		data->length = 4;
	if (format[*i] == '%')
		return (convert_percent(data, i));
	else if (format[*i] == 'c' && !data->length)
		return (convert_c(ap, data, i, format[*i]));
	else if (format[*i] == 's' && !data->length)
		return (convert_s(ap, data, i));
	else if (format[*i] == 'C' || (format[*i] == 'c' && data->length == 4))
		return (convert_cmaj(ap, data, i));
	else if (format[*i] == 'S' || (format[*i] == 's' && data->length == 4))
		return (convert_smaj(ap, data, i));
	else if (format[*i] == 'p')
		return (convert_p(ap, data, i));
	else if (format[*i] == 'i' || format[*i] == 'd' || format[*i] == 'D')
		return (convert_signed(ap, data, i));
	else if (format[*i] == 'x' || format[*i] == 'X' || format[*i] == 'o' ||
			format[*i] == 'O' || format[*i] == 'u' || format[*i] == 'U' ||
			format[*i] == 'b' || format[*i] == 'B')
		return (convert_unsigned(ap, data, i, format[*i]));
	else if (format[*i] >= 32 && format[*i] <= 126)
		return (convert_c(ap, data, i, format[*i]));
	return (0);
}
