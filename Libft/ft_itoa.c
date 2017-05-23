/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 12:33:01 by lalves            #+#    #+#             */
/*   Updated: 2015/12/15 17:31:20 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_itoa_0(int n)
{
	char *str;

	str = NULL;
	if (n == 0)
	{
		str = (char*)malloc(sizeof(char) * 2);
		if (str == NULL)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
	}
	return (str);
}

static char		*ft_itoa_min(int n)
{
	char *str;

	str = NULL;
	if (n == -2147483648)
	{
		str = (char*)malloc(sizeof(char) * 12);
		if (str == NULL)
			return (NULL);
		str[0] = '-';
		str[1] = '2';
		str[2] = '1';
		str[3] = '4';
		str[4] = '7';
		str[5] = '4';
		str[6] = '8';
		str[7] = '3';
		str[8] = '6';
		str[9] = '4';
		str[10] = '8';
		str[11] = '\0';
	}
	return (str);
}

static char		*ft_itoa_helper(int n)
{
	if (n == 0)
		return (ft_itoa_0(n));
	if (n == -2147483648)
		return (ft_itoa_min(n));
	return (NULL);
}

static void		ft_get_length(int n, int *len, long long int *size)
{
	*size = 1;
	*len = 1;
	if (n < 0)
	{
		*len = *len + 1;
		n = -n;
	}
	while ((n / *size) > 0)
	{
		*size = *size * 10;
		*len = *len + 1;
	}
	*size = *size / 10;
}

char			*ft_itoa(int n)
{
	int				len;
	long long int	size;
	size_t			i;
	char			*str;

	if (n == 0 || n == -2147483648)
		return (ft_itoa_helper(n));
	i = 0;
	ft_get_length(n, &len, &size);
	str = (char*)malloc(sizeof(char) * len);
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[i++] = '-';
		n = -n;
	}
	while (size > 0)
	{
		str[i++] = (n / size % 10) + 48;
		size = size / 10;
	}
	str[i] = '\0';
	return (str);
}
