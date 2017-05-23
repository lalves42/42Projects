/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 19:12:52 by lalves            #+#    #+#             */
/*   Updated: 2016/11/16 16:30:09 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		get_conv(va_list *ap, const char *restrict s, t_flags *data, int *i)
{
	if (s[*i] == 'D' || s[*i] == 'O' || s[*i] == 'U')
		data->length = 4;
	if (s[*i] == '%')
		return (convert_percent(data, i));
	else if (s[*i] == 'c' && !data->length)
		return (convert_c(ap, data, i, s[*i]));
	else if (s[*i] == 's' && !data->length)
		return (convert_s(ap, data, i));
	else if (s[*i] == 'C' || (s[*i] == 'c' && data->length == 4))
		return (convert_cmaj(ap, data, i));
	else if (s[*i] == 'S' || (s[*i] == 's' && data->length == 4))
		return (convert_smaj(ap, data, i));
	else if (s[*i] == 'p')
		return (convert_p(ap, data, i));
	else if (s[*i] == 'i' || s[*i] == 'd' || s[*i] == 'D')
		return (convert_signed(ap, data, i));
	else if (s[*i] == 'x' || s[*i] == 'X' || s[*i] == 'o' ||
			s[*i] == 'O' || s[*i] == 'u' || s[*i] == 'U' ||
			s[*i] == 'b' || s[*i] == 'B')
		return (convert_unsigned(ap, data, i, s[*i]));
	else if (s[*i] >= 32 && s[*i] <= 126)
		return (convert_c(ap, data, i, s[*i]));
	return (0);
}
