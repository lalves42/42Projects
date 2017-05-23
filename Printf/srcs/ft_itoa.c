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

#include <libftprintf.h>

static void		ft_itoa_min(char *str)
{
	str[0] = '-';
	str[1] = '9';
	str[2] = '2';
	str[3] = '2';
	str[4] = '3';
	str[5] = '3';
	str[6] = '7';
	str[7] = '2';
	str[8] = '0';
	str[9] = '3';
	str[10] = '6';
	str[11] = '8';
	str[12] = '5';
	str[13] = '4';
	str[14] = '7';
	str[15] = '7';
	str[16] = '5';
	str[17] = '8';
	str[18] = '0';
	str[19] = '8';
	str[20] = '\0';
}

static char		*ft_itoa_0(intmax_t n)
{
	char *str;

	if (n == 0)
	{
		str = (char*)malloc(sizeof(char) * 2);
		if (str == NULL)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
	}
	else
	{
		str = (char*)malloc(sizeof(char) * 21);
		if (str == NULL)
			return (NULL);
		ft_itoa_min(str);
	}
	return (str);
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
		return (ft_itoa_0(n));
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
