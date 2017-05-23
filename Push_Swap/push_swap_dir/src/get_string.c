/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalves <lalves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 16:28:47 by lalves            #+#    #+#             */
/*   Updated: 2016/11/15 18:46:05 by lalves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	fill_string(int ac, char **av, char *buf)
{
	int		i;
	int		idx;

	i = 1;
	idx = 0;
	while (i < ac)
	{
		ft_strcpy_printf(&buf[idx], av[i]);
		idx += ft_strlen(av[i]);
		if (i + 1 == ac)
			break ;
		buf[idx] = ' ';
		idx++;
		i++;
	}
	buf[idx] = '\0';
}

static int	get_length(int ac, char **av)
{
	int i;
	int len;

	i = 1;
	len = 0;
	while (i < ac)
	{
		len += ft_strlen(av[i]);
		i++;
	}
	return (len);
}

char		*get_string(int ac, char **av)
{
	char	*str;
	int		len;

	len = get_length(ac, av);
	len += ac - 2;
	str = (char*)malloc(sizeof(char) * len + 1);
	if (!str)
		ft_error("malloc");
	fill_string(ac, av, str);
	return (str);
}
