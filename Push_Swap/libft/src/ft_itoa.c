/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 12:33:01 by lalves            #+#    #+#             */
/*   Updated: 2016/11/09 20:20:07 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char		*ft_itoa_helper(intmax_t n)
{
	if (n == 0)
		return (ft_strdup("0"));
	else
		return (ft_strdup("-9223372036854775808"));
}

static void		ft_get_length(intmax_t n, int *len)
{
	*len = 1;
	if (n < 0)
	{
		*len = *len + 1;
		n = -n;
	}
	while (n > 0)
	{
		*len = *len + 1;
		n = n / 10;
	}
}

char			*ft_itoa(intmax_t n)
{
	int		len;
	char	*str;

	if (n == 0 || n == LONG_MIN)
		return (ft_itoa_helper(n));
	ft_get_length(n, &len);
	str = (char*)malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);
	str[len - 1] = '\0';
	len = len - 2;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (len >= 0)
	{
		if (str[len] == '-')
			break ;
		str[len--] = (n % 10) + 48;
		n = n / 10;
	}
	return (str);
}
